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
  'sandbox/linux/BUILD.gn': [
    ['"system_headers/x86_64_linux_syscalls.h",\n', '"system_headers/x86_64_linux_syscalls.h","system_headers/loong64_linux_syscalls.h",\n']
  ],
  'sandbox/linux/system_headers/linux_syscalls.h': [
    ['#endif\n\n#endif', '#endif\n\n#if defined(__loongarch64)\n#include "sandbox/linux/system_headers/loong64_linux_syscalls.h"\n#endif\n#endif']
  ],
  'sandbox/linux/system_headers/linux_signal.h': [
    [`#if defined(__i386__) || defined(__x86_64__) || defined(__arm__) || \\
    defined(__aarch64__)
`, `#if defined(__i386__) || defined(__x86_64__) || defined(__arm__) || \\\ndefined(__aarch64__) || defined(__loongarch64)\n`]
  ],
  'sandbox/linux/system_headers/linux_stat.h': [
    [`#define __NR_fstatat_default __NR_newfstatat
#define __NR_fstat_default __NR_fstat

#else
#error "one of fstatat64 and newfstatat must be defined"`, `#define __NR_fstatat_default __NR_newfstatat
#define __NR_fstat_default __NR_fstat

#elif defined(__loongarch64)

namespace sandbox {
using default_stat_struct = struct kernel_stat;
} // namespace sandbox

#define __NR_fstatat_default __NR_statx
#define __NR_fstat_default __NR_statx
// loong64
#else
#error "one of fstatat64 and newfstatat must be defined"`],
[
`#endif

#if !defined(AT_EMPTY_PATH)`,
`#endif

#if defined(__loongarch64)
#define AT_STATX_SYNC_AS_STAT 0x0000
#define STATX_ALL 0x00000fffU
#endif
// loong64
#if !defined(AT_EMPTY_PATH)`
],
[
`#elif defined(__aarch64__)
struct kernel_stat {
  unsigned long st_dev;
  unsigned long st_ino;
  unsigned int st_mode;
  unsigned int st_nlink;
  unsigned int st_uid;
  unsigned int st_gid;
  unsigned long st_rdev;
  unsigned long __pad1;
  long st_size;
  int st_blksize;
  int __pad2;
  long st_blocks;
  long st_atime_;
  unsigned long st_atime_nsec_;
  long st_mtime_;
  unsigned long st_mtime_nsec_;
  long st_ctime_;
  unsigned long st_ctime_nsec_;
  unsigned int __unused4;
  unsigned int __unused5;
};
#endif`,
`#elif defined(__aarch64__) 
struct kernel_stat {
  unsigned long st_dev;
  unsigned long st_ino;
  unsigned int st_mode;
  unsigned int st_nlink;
  unsigned int st_uid;
  unsigned int st_gid;
  unsigned long st_rdev;
  unsigned long __pad1;
  long st_size;
  int st_blksize;
  int __pad2;
  long st_blocks;
  long st_atime_;
  unsigned long st_atime_nsec_;
  long st_mtime_;
  unsigned long st_mtime_nsec_;
  long st_ctime_;
  unsigned long st_ctime_nsec_;
  unsigned int __unused4;
  unsigned int __unused5;
};
#elif defined(__loongarch64)
struct kernel_timestamp {
  long         tv_sec;
  unsigned int tv_nsec;
  signed int   reserved;
};

struct kernel_stat {
  unsigned int st_mask;
  unsigned int st_blksize;
  unsigned long        st_attributes;
  unsigned int st_nlink;
  unsigned int st_uid;
  unsigned int st_gid;
  unsigned char st_mode;
  unsigned char __spare0[1];
  unsigned long        st_ino;
  unsigned long st_size;
  unsigned long st_blocks;
  unsigned long st_attributes_mask;
  struct kernel_timestamp st_atime_;
  struct kernel_timestamp st_btime_;
  struct kernel_timestamp st_ctime_;
  struct kernel_timestamp st_mtime_;
  unsigned int st_rdev_major;
  unsigned int st_rdev_minor;
  unsigned int st_dev_major;
  unsigned int st_dev_minor;
  unsigned long        st_mnt_id;
  unsigned long        __spare2;
  unsigned long        __spare3[12];
};
#endif`
]
  ],
  'sandbox/linux/services/credentials.cc': [
[
`#if defined(ARCH_CPU_X86_FAMILY) || defined(ARCH_CPU_ARM_FAMILY) || \\
    defined(ARCH_CPU_MIPS_FAMILY)
  // The stack grows downward.`,
`#if defined(ARCH_CPU_X86_FAMILY) || defined(ARCH_CPU_ARM_FAMILY) || \\
    defined(ARCH_CPU_MIPS_FAMILY) || defined(ARCH_CPU_LOONGARCH_FAMILY)
  // The stack grows downward.`
]
  ],
  'sandbox/linux/bpf_dsl/seccomp_macros.h': [
[
`#define SECCOMP_PT_PARM5(_regs) (_regs).regs[4]
#define SECCOMP_PT_PARM6(_regs) (_regs).regs[5]
#else
#error Unsupported target platform`,
`#define SECCOMP_PT_PARM5(_regs) (_regs).regs[4]
#define SECCOMP_PT_PARM6(_regs) (_regs).regs[5]

#elif defined(__loongarch64)
struct regs_struct {
  uint64_t regs[32];
  uint64_t orig_a0;
  uint64_t csr_era;
  uint64_t csr_badv;
  uint64_t reserved[10];
};

typedef unsigned long int greg_t;

#define SECCOMP_ARCH AUDIT_ARCH_LOONGARCH64

#define SECCOMP_REG(_ctx, _reg) ((_ctx)->uc_mcontext.__gregs[_reg])

#define SECCOMP_RESULT(_ctx) SECCOMP_REG(_ctx, 4)
#define SECCOMP_SYSCALL(_ctx) SECCOMP_REG(_ctx, 11)
#define SECCOMP_IP(_ctx) (_ctx)->uc_mcontext.__pc
#define SECCOMP_PARM1(_ctx) SECCOMP_REG(_ctx, 4)
#define SECCOMP_PARM2(_ctx) SECCOMP_REG(_ctx, 5)
#define SECCOMP_PARM3(_ctx) SECCOMP_REG(_ctx, 6)
#define SECCOMP_PARM4(_ctx) SECCOMP_REG(_ctx, 7)
#define SECCOMP_PARM5(_ctx) SECCOMP_REG(_ctx, 8)
#define SECCOMP_PARM6(_ctx) SECCOMP_REG(_ctx, 9)

#define SECCOMP_NR_IDX (offsetof(struct arch_seccomp_data, nr))
#define SECCOMP_ARCH_IDX (offsetof(struct arch_seccomp_data, arch))
#define SECCOMP_IP_MSB_IDX \\
	(offsetof(struct arch_seccomp_data, instruction_pointer) + 4)
#define SECCOMP_IP_LSB_IDX \\
	(offsetof(struct arch_seccomp_data, instruction_pointer) + 0)
#define SECCOMP_ARG_MSB_IDX(nr) \\
	(offsetof(struct arch_seccomp_data, args) + 8 * (nr) + 4)
#define SECCOMP_ARG_LSB_IDX(nr) \\
	(offsetof(struct arch_seccomp_data, args) + 8 * (nr) + 0)

#define SECCOMP_PT_RESULT(_regs) (_regs).regs[4]
#define SECCOMP_PT_SYSCALL(_regs) (_regs).regs[11]
#define SECCOMP_PT_IP(_regs) (_regs).csr_era
#define SECCOMP_PT_PARM1(_regs) (_regs).regs[4]
#define SECCOMP_PT_PARM2(_regs) (_regs).regs[5]
#define SECCOMP_PT_PARM3(_regs) (_regs).regs[6]
#define SECCOMP_PT_PARM4(_regs) (_regs).regs[7]
#define SECCOMP_PT_PARM5(_regs) (_regs).regs[8]
#define SECCOMP_PT_PARM6(_regs) (_regs).regs[9]

#else
#error Unsupported target platform`
]
  ],
  'sandbox/linux/services/syscall_wrappers.cc': [
    ['file://./syscall_wrappers/0_0.h', 'file://./syscall_wrappers/0_1.h'],
    ['file://./syscall_wrappers/1_0.h', 'file://./syscall_wrappers/1_1.h'],
    ['file://./syscall_wrappers/2_0.h', 'file://./syscall_wrappers/2_1.h'],
  ],
  'sandbox/linux/syscall_broker/broker_process.cc': [
    [/#if !defined\(__aarch64__\) && !BUILDFLAG\(IS_ANDROID\)\n/g, '#if !defined(__aarch64__) && !BUILDFLAG(IS_ANDROID) && !defined(__loongarch64)\n'],
    ['file://./broker_process/0_0.h', 'file://./broker_process/0_1.h'],
  ],
  'sandbox/linux/system_headers/linux_seccomp.h': [
    ['file://./linux_seccomp/0_0.h', 'file://./linux_seccomp/0_1.h'],
    ['file://./linux_seccomp/1_0.h', 'file://./linux_seccomp/1_1.h'],
  ],
  'sandbox/linux/bpf_dsl/linux_syscall_ranges.h': [
    ['file://./linux_syscall_ranges/0_0.h', 'file://./linux_syscall_ranges/0_1.h'],
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
        if (to.startsWith('file://')) {
          to = fs.readFileSync(path.resolve(__dirname, to.substring(7))).toString()
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