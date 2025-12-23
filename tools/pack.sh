#!/bin/bash
set -e
root_dir=$(cd `dirname $0`/.. && pwd -P)
source "$root_dir/tools/common/log.sh"

trap 'catchError $LINENO "$BASH_COMMAND"' ERR # 捕获错误情况
catchError() {
  exit_code=$?
  if [ $exit_code -ne 0 ]; then
      fail "\033[31mcommand: $2\n  at $0:$1\n  at $STEP\033[0m"
  fi
  exit $exit_code
}
src_dir="$root_dir/source-code"
src_dir="$src_dir/nwjs/src"
output_dir="$root_dir/output"

cd "$src_dir"
mkdir -p "$output_dir/dist_nwjs/"{simple,sdk}

python_version=$(node $root_dir/tools/parse-config.js --get-pack-python-version $@)
if [ "$python_version" == "python3" ];then
  python=python3
else
  python=python2
fi
notice "Start to pack"
$python content/nw/tools/package_binaries.py -p out/nw -a loong64 -n symbol
mv "out/nw/dist/"* "$output_dir/dist_nwjs/simple"

notice "Start to pack SDK"
$python content/nw/tools/package_binaries.py -p out/nw -a loong64 -n symbol -m sdk
mv "out/nw/dist/"* "$output_dir/dist_nwjs/sdk"

mv "$output_dir/dist_nwjs/simple/nwjs"*.tar.gz "$output_dir/dist_nwjs"
mv "$output_dir/dist_nwjs/sdk/nwjs"*.tar.gz "$output_dir/dist_nwjs"
mv "$output_dir/dist_nwjs/sdk/nw-"*.tar.gz "$output_dir/dist_nwjs"

> "$output_dir/dist_nwjs/SHASUMS256.txt"
notice "Start to merge SHASUMS256.txt"
if [ -f "$output_dir/dist_nwjs/simple/SHASUMS256.txt" ];then
  cat "$output_dir/dist_nwjs/simple/SHASUMS256.txt" >> "$output_dir/dist_nwjs/SHASUMS256.txt"
  echo "" >> "$output_dir/dist_nwjs/SHASUMS256.txt"
  cat "$output_dir/dist_nwjs/sdk/SHASUMS256.txt" >> "$output_dir/dist_nwjs/SHASUMS256.txt"
else
  cat "$output_dir/dist_nwjs/simple/"nwjs-*-linux-loong64.tar.gz.sha256.txt >> "$output_dir/dist_nwjs/SHASUMS256.txt"
  echo "" >> "$output_dir/dist_nwjs/SHASUMS256.txt"
  cat "$output_dir/dist_nwjs/sdk/"nwjs-sdk-*-linux-loong64.tar.gz.sha256.txt >> "$output_dir/dist_nwjs/SHASUMS256.txt"
  echo "" >> "$output_dir/dist_nwjs/SHASUMS256.txt"
  cat "$output_dir/dist_nwjs/sdk/"nw-headers-*.tar.gz.sha256.txt >> "$output_dir/dist_nwjs/SHASUMS256.txt"
fi

rm -rf "$output_dir/dist_nwjs/simple" "$output_dir/dist_nwjs/sdk"