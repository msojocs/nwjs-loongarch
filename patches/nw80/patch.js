#!/usr/bin/env node
const fs = require('fs')
const path = require('path')
const args = process.argv.slice(2)
const srcDir = args[0]

const patchSysroot = async () => {
  const cfgFile = path.resolve(srcDir, 'build/linux/sysroot_scripts/sysroots.json')
  const c = JSON.parse(fs.readFileSync(cfgFile).toString())
  if (!c.bullseye_loong64) {
    c.bullseye_loong64 = {
      Key: "20230611T210420Z-2",
      Sha1Sum: "1b857baabd7999ff0d6949a8973f896836ac45ac",
      SysrootDir: "debian_bullseye_loong64-sysroot",
      Tarball: "debian_bullseye_loong64_sysroot.tar.xz",
      URL: c.bullseye_amd64.URL
    }
    fs.writeFileSync(cfgFile, JSON.stringify(c, null, 4))
  }

  const pyFile = path.resolve(srcDir, 'build/linux/sysroot_scripts/install-sysroot.py')
  let content = fs.readFileSync(pyFile).toString()
  content = content.replace("'mips64el')", "'mips64el', 'loong64')")
  content = content.replace("'mips64': 'mips64el',\n", "'mips64': 'mips64el','loong64': 'loong64',\n")
  content = content.replace("'mips64': 'mips64el',\r\n", "'mips64': 'mips64el','loong64': 'loong64',\r\n")
  fs.writeFileSync(pyFile, content)
}
const patchCfg = {
  'build/config/clang/BUILD.gn': {
    '_dir = "aarch64-unknown-linux-gnu"\n        } else {\n': '_dir = "aarch64-unknown-linux-gnu"\n  } else if (current_cpu == "loong64") {\n    _dir = "loongarch64-unknown-linux-gnu"\n  } else {\n',
  },
  'build/config/compiler/BUILD.gn': {
    '\n\n  # Normally, this would be defined in': '\n  # loong64 rust compiler flags setup for cef\nif (is_linux && current_cpu == "loong64") {rustflags += [ "-Ccode-model=medium" ]}\n  # Normally, this would be defined in'
  },
  'build/config/linux/libffi/BUILD.gn': {
    'libs = [ ":libffi_pic.a" ]': 'libs = [ "ffi" ]'
  },
  'build/config/linux/pkg_config.gni': {
    'system_libdir = "lib"\n}': 'system_libdir = "lib"\n  if (current_cpu == "loong64") {system_libdir = "lib64"}\n}',
  },
  'build/config/rust.gni': {
    '}\n  } else {\n    # Best': '}\n  } else if (current_cpu == "loong64") { rust_abi_target = "loongarch64-unknown-linux-gnu" } else {\n    # Best',
    'rust_target_arch = "riscv64"\n}\n': 'rust_target_arch = "riscv64"\n} else if (current_cpu == "loong64") {\n  rust_target_arch = "loong64"\n}\n'
  },
  'build/config/sysroot.gni': {
    'if (sysroot == "") {\n  if (current_os ': 'if (sysroot == "") {\n  if (target_sysroot == "" && current_cpu == "loong64") {    target_sysroot = "$target_sysroot_dir/debian_bullseye_loong64-sysroot"}\n  if (current_os '
  },
  'skia/BUILD.gn': {
    '# Conditional and empty body needed to avoid assert() below.\n  } else': '# Conditional and empty body needed to avoid assert() below.\n  } else if (current_cpu == "loong64") {\n  } else'
  },
  'third_party/libvpx/BUILD.gn': {
    'if (current_cpu == "loong64") {\n  source_set("libvpx_loongarch_lsx") {\n    configs -= [ "//build/config/compiler:chromium_code" ]\n    configs += [ "//build/config/compiler:no_chromium_code" ]\n    configs += [ ":libvpx_config" ]\n    cflags = [ "-mlsx" ]\n    sources = libvpx_srcs_loongarch_lsx\n  }\n}': '',
    'source_set("libvpx_loongarch_headers") {\n  sources = libvpx_srcs_loongarch_headers\n}': '',
    '  if (current_cpu == "loong64") {\n    deps += [ ":libvpx_loongarch_lsx" ]\n  }\n': '',
    'cpu_arch_full = "loongarch"': 'cpu_arch_full = "generic"',
    'sources = libvpx_srcs_loongarch\n': 'sources = libvpx_srcs_generic\n',
    'public_deps = [ ":libvpx_loongarch_headers" ]': 'public_deps = [ ":libvpx_generic_headers" ]'
  },
}
const patchConfig = () => {
  for (const file in patchCfg) {
    const targetFile = path.resolve(srcDir, file)
    let content = fs.readFileSync(targetFile).toString()
    const cfg = patchCfg[file]
    for (const from in cfg) {
      const to = cfg[from]
      content = content.replace(from, to)
    }
    fs.writeFileSync(targetFile, content)
  }
}

;(async () => {
  console.log('src:', srcDir)
  await patchSysroot()
  patchConfig()
})()