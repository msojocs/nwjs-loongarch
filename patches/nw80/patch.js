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
  'build/config/clang/BUILD.gn': [
    ['_dir = "aarch64-unknown-linux-gnu"\n        } else {\n', '_dir = "aarch64-unknown-linux-gnu"\n  } else if (current_cpu == "loong64") {\n    _dir = "loongarch64-unknown-linux-gnu"\n  } else {\n'],
  ],
  'build/config/compiler/BUILD.gn': [
    ['\n\n  # Normally, this would be defined in', '\n  # loong64 rust compiler flags setup for cef\nif (is_linux && current_cpu == "loong64") {rustflags += [ "-Ccode-model=medium" ]}\n  # Normally, this would be defined in']
  ],
  'build/config/linux/libffi/BUILD.gn': [
    ['libs = [ ":libffi_pic.a" ]', 'libs = [ "ffi" ]']
  ],
  'build/config/linux/pkg_config.gni': [
    ['system_libdir = "lib"\n}', 'system_libdir = "lib"\n  if (current_cpu == "loong64") {system_libdir = "lib64"}\n}'],
  ],
  'build/config/rust.gni': [
    ['}\n  } else {\n    # Best', '}\n  } else if (current_cpu == "loong64") { rust_abi_target = "loongarch64-unknown-linux-gnu" } else {\n    # Best'],
    ['rust_target_arch = "riscv64"\n}\n', 'rust_target_arch = "riscv64"\n} else if (current_cpu == "loong64") {\n  rust_target_arch = "loong64"\n}\n']
  ],
  'build/config/sysroot.gni': [
    ['if (sysroot == "") {\n  if (current_os ', 'if (sysroot == "") {\n  if (target_sysroot == "" && current_cpu == "loong64") {    target_sysroot = "$target_sysroot_dir/debian_bullseye_loong64-sysroot"}\n  if (current_os ']
  ],
  'sandbox/linux/BUILD.gn': [
    ['"system_headers/x86_64_linux_syscalls.h",\n', '"system_headers/x86_64_linux_syscalls.h","system_headers/loong64_linux_syscalls.h",\n']
  ],
  'sandbox/linux/system_headers/linux_syscalls.h': [
    ['#endif\n\n#endif', '#endif\n\n#if defined(__loongarch64)\n#include "sandbox/linux/system_headers/loong64_linux_syscalls.h"\n#endif\n#endif']
  ],
  'sandbox/linux/system_headers/linux_signal.h': [
    ['file://./linux_signal/1.h']
  ],
  'skia/BUILD.gn': [
    ['# Conditional and empty body needed to avoid assert() below.\n  } else {', '# Conditional and empty body needed to avoid assert() below.\n  } else if (current_cpu == "loong64") {\n  } else {']
  ],
  'third_party/libvpx/BUILD.gn': [
    ['if (current_cpu == "loong64") {\n  source_set("libvpx_loongarch_lsx") {\n    configs -= [ "//build/config/compiler:chromium_code" ]\n    configs += [ "//build/config/compiler:no_chromium_code" ]\n    configs += [ ":libvpx_config" ]\n    cflags = [ "-mlsx" ]\n    sources = libvpx_srcs_loongarch_lsx\n  }\n}', ''],
    ['source_set("libvpx_loongarch_headers") {\n  sources = libvpx_srcs_loongarch_headers\n}', ''],
    ['  if (current_cpu == "loong64") {\n    deps += [ ":libvpx_loongarch_lsx" ]\n  }\n', ''],
    ['cpu_arch_full = "loongarch"', 'cpu_arch_full = "generic"'],
    ['sources = libvpx_srcs_loongarch\n', 'sources = libvpx_srcs_generic\n'],
    ['public_deps = [ ":libvpx_loongarch_headers" ]', 'public_deps = [ ":libvpx_generic_headers" ]']
  ],
  'sandbox/linux/system_headers/linux_stat.h': [
    ['file://./linux_stat/1.h'],
    ['file://./linux_stat/2.h'],
    ['file://./linux_stat/3.h'],
  ],
  'sandbox/linux/services/credentials.cc': [
    ['file://./credentials/1.h'],
  ],
  'sandbox/linux/bpf_dsl/seccomp_macros.h': [
    ['file://./seccomp_macros/1.h'],
  ],
  'sandbox/linux/services/syscall_wrappers.cc': [
    ['file://./syscall_wrappers/0_0.h'],
    ['file://./syscall_wrappers/1_0.h'],
    ['file://./syscall_wrappers/2_0.h'],
  ],
  'sandbox/linux/syscall_broker/broker_process.cc': [
    [/#if !defined\(__aarch64__\) && !BUILDFLAG\(IS_ANDROID\)\n/g, '#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID) && !defined(__loongarch64)\n'],
    ['file://./broker_process/0_0.h'],
  ],
  'sandbox/linux/system_headers/linux_seccomp.h': [
    ['file://./linux_seccomp/0_0.h'],
    ['file://./linux_seccomp/1_0.h'],
  ],
  'sandbox/linux/bpf_dsl/linux_syscall_ranges.h': [
    ['file://./linux_syscall_ranges/0_0.h'],
  ],
  'sandbox/linux/seccomp-bpf-helpers/baseline_policy.cc': [
    ['#if !defined(__aarch64__)\n', '#if !defined(__aarch64__) && !defined(__loongarch__)\n'],
    ['    defined(__aarch64__)\n', '    defined(__aarch64__) || defined(__loongarch64)\n'],
    ['file://./baseline_policy/0_0.h', 'file://./baseline_policy/0_1.h'],
  ],
  'sandbox/linux/seccomp-bpf-helpers/sigsys_handlers.h': [
    ['file://./sigsys_handlers/1_0.h', 'file://./sigsys_handlers/1_1.h'],
    ['file://./sigsys_handlers/2_0.h', 'file://./sigsys_handlers/2_1.h'],
  ],
  'sandbox/linux/seccomp-bpf-helpers/syscall_parameters_restrictions.cc': [
    ['!defined(PTRACE_GET_THREAD_AREA)\n', '!defined(PTRACE_GET_THREAD_AREA) && !defined(__loongarch64)\n'],
    ['file://./syscall_parameters_restrictions/0_0.h', 'file://./syscall_parameters_restrictions/0_1.h'],
  ],
  'sandbox/linux/seccomp-bpf/syscall.cc': [
    ['defined(ARCH_CPU_MIPS_FAMILY)\n', 'defined(ARCH_CPU_MIPS_FAMILY) || defined(ARCH_CPU_LOONGARCH_FAMILY)\n'],
    ['file://./syscall/0_0.h', 'file://./syscall/0_1.h'],
    ['file://./syscall/1_0.h', 'file://./syscall/1_1.h'],
  ],
  'sandbox/linux/seccomp-bpf-helpers/syscall_sets.h': [
    [/\(defined\(ARCH_CPU_MIPS_FAMILY\) && defined\(ARCH_CPU_64_BITS\)\)\n/g, '(defined(ARCH_CPU_MIPS_FAMILY) && defined(ARCH_CPU_64_BITS)) || defined(__loongarch64)\n'],
    ['defined(__aarch64__)\n', 'defined(__aarch64__) || defined(__loongarch64)\n'],
  ],
  'sandbox/linux/seccomp-bpf-helpers/syscall_sets.cc': [
    // [/#if !defined\(__aarch64__\)\n/g, '#if !defined(__aarch64__) && !defined(__loongarch64)\n']
    ['file://./syscall_sets_cc/0_0.h', 'file://./syscall_sets_cc/0_1.h'],
  ],
  'third_party/crashpad/crashpad/util/linux/thread_info.h': [
    ['file://./thread_info/0_0.h', 'file://./thread_info/0_1.h'],
    ['file://./thread_info/1_0.h', 'file://./thread_info/1_1.h'],
    ['file://./thread_info/2_0.h', 'file://./thread_info/2_1.h'],
    ['file://./thread_info/3_0.h', 'file://./thread_info/3_1.h'],
    ['file://./thread_info/4_0.h', 'file://./thread_info/4_1.h'],
  ],
  'third_party/crashpad/crashpad/snapshot/linux/signal_context.h': [
    ['#ifdef ARCH_CPU_MIPS_FAMILY\n', '#if defined(ARCH_CPU_MIPS_FAMILY) || defined(ARCH_CPU_LOONGARCH_FAMILY)\n'],
    ['file://./signal_context/0_0.h', 'file://./signal_context/0_1.h'],
  ],
  'third_party/crashpad/crashpad/snapshot/linux/thread_snapshot_linux.cc': [
    ['file://./thread_snapshot_linux/0_0.h', 'file://./thread_snapshot_linux/0_1.h'],
  ],
  'third_party/crashpad/crashpad/snapshot/linux/thread_snapshot_linux.h': [
    ['file://./thread_snapshot_linux/h_0.h', 'file://./thread_snapshot_linux/h_1.h'],
  ],
  'third_party/crashpad/crashpad/minidump/minidump_misc_info_writer.cc': [
    ['file://./minidump_misc_info_writer/0_0.h', 'file://./minidump_misc_info_writer/0_1.h'],
  ],
  'third_party/crashpad/crashpad/snapshot/capture_memory.cc': [
    ['file://./capture_memory/0_0.h', 'file://./capture_memory/0_1.h'],
  ],
  'third_party/crashpad/crashpad/snapshot/linux/cpu_context_linux.cc': [
    ['file://./cpu_context_linux/0_0.h', 'file://./cpu_context_linux/0_1.h'],
  ],
  'third_party/crashpad/crashpad/snapshot/linux/cpu_context_linux.h': [
    ['file://./cpu_context_linux/h_0.h', 'file://./cpu_context_linux/h_1.h'],
  ],
  'third_party/crashpad/crashpad/snapshot/cpu_context.cc': [
    ['file://./cpu_context/c1_0.h', 'file://./cpu_context/c1_1.h'],
    ['file://./cpu_context/c2_0.h', 'file://./cpu_context/c2_1.h'],
    ['file://./cpu_context/c3_0.h', 'file://./cpu_context/c3_1.h'],
  ],
  'third_party/crashpad/crashpad/snapshot/cpu_context.h': [
    ['file://./cpu_context/h1_0.h', 'file://./cpu_context/h1_1.h'],
    ['file://./cpu_context/h2_0.h', 'file://./cpu_context/h2_1.h'],
  ],
  'third_party/crashpad/crashpad/snapshot/cpu_architecture.h': [
    ['kCPUArchitectureRISCV64,\n}', 'kCPUArchitectureRISCV64,\n\n  //! \brief 64-bit LOONGARCH.\n  kCPUArchitectureLOONGARCH64,}']
  ],
  'third_party/crashpad/crashpad/snapshot/linux/system_snapshot_linux.cc': [
    ['file://./system_snapshot_linux/1_0.h'],
    ['file://./system_snapshot_linux/2.h'],
    ['file://./system_snapshot_linux/3.h'],
    ['file://./system_snapshot_linux/4.h'],
  ],
  'third_party/crashpad/crashpad/util/net/http_transport_libcurl.cc': [
    ['file://./http_transport_libcurl/1.h']
  ],
  'third_party/crashpad/crashpad/snapshot/linux/exception_snapshot_linux.cc': [
    ['file://./exception_snapshot_linux/c1.h'],
    ['file://./exception_snapshot_linux/c2.h'],
    ['file://./exception_snapshot_linux/c3.h'],
  ],
  'third_party/crashpad/crashpad/snapshot/linux/exception_snapshot_linux.h': [
    ['file://./exception_snapshot_linux/h1.h'],
  ],
  'third_party/crashpad/crashpad/snapshot/linux/process_reader_linux.cc': [
    ['file://./process_reader_linux/1.h'],
  ],
  'third_party/crashpad/crashpad/util/linux/ptracer.cc': [
    ['file://./ptracer/1.h'],
  ],
  'sandbox/policy/linux/bpf_network_policy_linux.cc': [
    ['#if !defined(__aarch64__)\n', '#if !defined(__aarch64__) && !defined(__loongarch64)\n']
  ],
  'sandbox/policy/linux/bpf_gpu_policy_linux.cc': [
    ['#if !defined(__aarch64__)\n', '#if !defined(__aarch64__) && !defined(__loongarch64)\n']
  ],
  'sandbox/policy/linux/bpf_cros_amd_gpu_policy_linux.cc': [
    ['#if !defined(__aarch64__)\n', '#if !defined(__aarch64__) && !defined(__loongarch64)\n']
  ],
  'sandbox/features.gni': [
    [' current_cpu == "mips64el")', ' current_cpu == "mips64el" || current_cpu == "loong64")']
  ],
  'third_party/blink/renderer/platform/BUILD.gn': [
    ['"graphics/cpu/loongarch64/webgl_image_conversion_lsx.h",', ''],
    ['file://./renderer_platform/BUILD.h'],
  ],
  'third_party/blink/renderer/platform/graphics/gpu/webgl_image_conversion.cc': [
    ['#include "third_party/blink/renderer/platform/graphics/cpu/loongarch64/webgl_image_conversion_lsx.h"', ''],
    ['file://./webgl_image_conversion/1.h'],
    ['file://./webgl_image_conversion/2.h'],
    ['file://./webgl_image_conversion/3.h'],
    ['file://./webgl_image_conversion/4.h'],
    ['file://./webgl_image_conversion/5.h'],
    ['file://./webgl_image_conversion/6.h'],
  ],
  'build/toolchain/gcc_toolchain.gni': [
    ['file://./gcc_toolchain/1.h'],
    ['file://./gcc_toolchain/2.h'],
  ],
}
const patchConfig = () => {
  for (const file in patchCfg) {
    const targetFile = path.resolve(srcDir, file)
    let content = fs.readFileSync(targetFile).toString()
    const cfg = patchCfg[file]
    for (const d of cfg) {
      let from = d[0]
      let to = d[1]
      try {
        if (from.startsWith('file://')) {
          from = fs.readFileSync(path.resolve(__dirname, from.substring(7))).toString()
        }
        if (d.length == 2){
          // 两个文件，一个修改前，一个修改后
          if (to.startsWith('file://')) {
            to = fs.readFileSync(path.resolve(__dirname, to.substring(7))).toString()
          }
        }
        else if (d.length == 1) {
          // 一个文件，包含了修改前与修改后的数据，使用 \n//----replace\n 分割
          const t = from.split('\n//----replace\n')
          from = t[0]
          to = t[1]
        }
      } catch (error) {
        
      }
      if (typeof from === 'string') {
        content = content.replaceAll(from, to)
      }
      else {
        content = content.replace(from, to)
      }
    }
    fs.writeFileSync(targetFile, content)
  }
}

  ; (async () => {
    console.log('src:', srcDir)
    await patchSysroot()
    patchConfig()
  })()