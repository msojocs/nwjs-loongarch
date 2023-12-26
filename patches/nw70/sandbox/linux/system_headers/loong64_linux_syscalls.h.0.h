// Copyright 2022 The Chromium Authors. All rights reserved.// loongarch64
// Use of this source code is governed by a BSD-style license that can be// loongarch64
// found in the LICENSE file.// loongarch64
// loongarch64
#ifndef SANDBOX_LINUX_SYSTEM_HEADERS_LOONG64_LINUX_SYSCALLS_H_// loongarch64
#define SANDBOX_LINUX_SYSTEM_HEADERS_LOONG64_LINUX_SYSCALLS_H_// loongarch64
// loongarch64
#include <asm-generic/unistd.h>// loongarch64
// loongarch64
#if !defined(__NR_io_setup)// loongarch64
#define __NR_io_setup 0// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_io_destroy)// loongarch64
#define __NR_io_destroy 1// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_io_submit)// loongarch64
#define __NR_io_submit 2// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_io_cancel)// loongarch64
#define __NR_io_cancel 3// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_io_getevents)// loongarch64
#define __NR_io_getevents 4// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setxattr)// loongarch64
#define __NR_setxattr 5// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_lsetxattr)// loongarch64
#define __NR_lsetxattr 6// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fsetxattr)// loongarch64
#define __NR_fsetxattr 7// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getxattr)// loongarch64
#define __NR_getxattr 8// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_lgetxattr)// loongarch64
#define __NR_lgetxattr 9// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fgetxattr)// loongarch64
#define __NR_fgetxattr 10// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_listxattr)// loongarch64
#define __NR_listxattr 11// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_llistxattr)// loongarch64
#define __NR_llistxattr 12// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_flistxattr)// loongarch64
#define __NR_flistxattr 13// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_removexattr)// loongarch64
#define __NR_removexattr 14// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_lremovexattr)// loongarch64
#define __NR_lremovexattr 15// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fremovexattr)// loongarch64
#define __NR_fremovexattr 16// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getcwd)// loongarch64
#define __NR_getcwd 17// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_lookup_dcookie)// loongarch64
#define __NR_lookup_dcookie 18// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_eventfd2)// loongarch64
#define __NR_eventfd2 19// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_epoll_create1)// loongarch64
#define __NR_epoll_create1 20// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_epoll_ctl)// loongarch64
#define __NR_epoll_ctl 21// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_epoll_pwait)// loongarch64
#define __NR_epoll_pwait 22// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_dup)// loongarch64
#define __NR_dup 23// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_dup3)// loongarch64
#define __NR_dup3 24// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fcntl)// loongarch64
#define __NR_fcntl 25// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_inotify_init1)// loongarch64
#define __NR_inotify_init1 26// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_inotify_add_watch)// loongarch64
#define __NR_inotify_add_watch 27// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_inotify_rm_watch)// loongarch64
#define __NR_inotify_rm_watch 28// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_ioctl)// loongarch64
#define __NR_ioctl 29// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_ioprio_set)// loongarch64
#define __NR_ioprio_set 30// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_ioprio_get)// loongarch64
#define __NR_ioprio_get 31// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_flock)// loongarch64
#define __NR_flock 32// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mknodat)// loongarch64
#define __NR_mknodat 33// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mkdirat)// loongarch64
#define __NR_mkdirat 34// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_unlinkat)// loongarch64
#define __NR_unlinkat 35// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_symlinkat)// loongarch64
#define __NR_symlinkat 36// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_linkat)// loongarch64
#define __NR_linkat 37// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_umount2)// loongarch64
#define __NR_umount2 39// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mount)// loongarch64
#define __NR_mount 40// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pivot_root)// loongarch64
#define __NR_pivot_root 41// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_nfsservctl)// loongarch64
#define __NR_nfsservctl 42// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_statfs)// loongarch64
#define __NR_statfs 43// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fstatfs)// loongarch64
#define __NR_fstatfs 44// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_truncate)// loongarch64
#define __NR_truncate 45// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_ftruncate)// loongarch64
#define __NR_ftruncate 46// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fallocate)// loongarch64
#define __NR_fallocate 47// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_faccessat)// loongarch64
#define __NR_faccessat 48// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_chdir)// loongarch64
#define __NR_chdir 49// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fchdir)// loongarch64
#define __NR_fchdir 50// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_chroot)// loongarch64
#define __NR_chroot 51// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fchmod)// loongarch64
#define __NR_fchmod 52// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fchmodat)// loongarch64
#define __NR_fchmodat 53// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fchownat)// loongarch64
#define __NR_fchownat 54// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fchown)// loongarch64
#define __NR_fchown 55// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_openat)// loongarch64
#define __NR_openat 56// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_close)// loongarch64
#define __NR_close 57// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_vhangup)// loongarch64
#define __NR_vhangup 58// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pipe2)// loongarch64
#define __NR_pipe2 59// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_quotactl)// loongarch64
#define __NR_quotactl 60// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getdents64)// loongarch64
#define __NR_getdents64 61// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_lseek)// loongarch64
#define __NR_lseek 62// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_read)// loongarch64
#define __NR_read 63// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_write)// loongarch64
#define __NR_write 64// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_readv)// loongarch64
#define __NR_readv 65// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_writev)// loongarch64
#define __NR_writev 66// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pread64)// loongarch64
#define __NR_pread64 67// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pwrite64)// loongarch64
#define __NR_pwrite64 68// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_preadv)// loongarch64
#define __NR_preadv 69// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pwritev)// loongarch64
#define __NR_pwritev 70// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sendfile)// loongarch64
#define __NR_sendfile 71// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pselect6)// loongarch64
#define __NR_pselect6 72// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_ppoll)// loongarch64
#define __NR_ppoll 73// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_signalfd4)// loongarch64
#define __NR_signalfd4 74// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_vmsplice)// loongarch64
#define __NR_vmsplice 75// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_splice)// loongarch64
#define __NR_splice 76// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_tee)// loongarch64
#define __NR_tee 77// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_readlinkat)// loongarch64
#define __NR_readlinkat 78// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sync)// loongarch64
#define __NR_sync 81// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fsync)// loongarch64
#define __NR_fsync 82// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fdatasync)// loongarch64
#define __NR_fdatasync 83// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sync_file_range)// loongarch64
#define __NR_sync_file_range 84// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_timerfd_create)// loongarch64
#define __NR_timerfd_create 85// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_timerfd_settime)// loongarch64
#define __NR_timerfd_settime 86// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_timerfd_gettime)// loongarch64
#define __NR_timerfd_gettime 87// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_utimensat)// loongarch64
#define __NR_utimensat 88// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_acct)// loongarch64
#define __NR_acct 89// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_capget)// loongarch64
#define __NR_capget 90// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_capset)// loongarch64
#define __NR_capset 91// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_personality)// loongarch64
#define __NR_personality 92// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_exit)// loongarch64
#define __NR_exit 93// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_exit_group)// loongarch64
#define __NR_exit_group 94// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_waitid)// loongarch64
#define __NR_waitid 95// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_set_tid_address)// loongarch64
#define __NR_set_tid_address 96// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_unshare)// loongarch64
#define __NR_unshare 97// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_futex)// loongarch64
#define __NR_futex 98// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_set_robust_list)// loongarch64
#define __NR_set_robust_list 99// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_get_robust_list)// loongarch64
#define __NR_get_robust_list 100// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_nanosleep)// loongarch64
#define __NR_nanosleep 101// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getitimer)// loongarch64
#define __NR_getitimer 102// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setitimer)// loongarch64
#define __NR_setitimer 103// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_kexec_load)// loongarch64
#define __NR_kexec_load 104// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_init_module)// loongarch64
#define __NR_init_module 105// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_delete_module)// loongarch64
#define __NR_delete_module 106// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_timer_create)// loongarch64
#define __NR_timer_create 107// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_timer_gettime)// loongarch64
#define __NR_timer_gettime 108// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_timer_getoverrun)// loongarch64
#define __NR_timer_getoverrun 109// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_timer_settime)// loongarch64
#define __NR_timer_settime 110// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_timer_delete)// loongarch64
#define __NR_timer_delete 111// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_clock_settime)// loongarch64
#define __NR_clock_settime 112// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_clock_gettime)// loongarch64
#define __NR_clock_gettime 113// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_clock_getres)// loongarch64
#define __NR_clock_getres 114// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_clock_nanosleep)// loongarch64
#define __NR_clock_nanosleep 115// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_syslog)// loongarch64
#define __NR_syslog 116// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_ptrace)// loongarch64
#define __NR_ptrace 117// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sched_setparam)// loongarch64
#define __NR_sched_setparam 118// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sched_setscheduler)// loongarch64
#define __NR_sched_setscheduler 119// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sched_getscheduler)// loongarch64
#define __NR_sched_getscheduler 120// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sched_getparam)// loongarch64
#define __NR_sched_getparam 121// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sched_setaffinity)// loongarch64
#define __NR_sched_setaffinity 122// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sched_getaffinity)// loongarch64
#define __NR_sched_getaffinity 123// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sched_yield)// loongarch64
#define __NR_sched_yield 124// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sched_get_priority_max)// loongarch64
#define __NR_sched_get_priority_max 125// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sched_get_priority_min)// loongarch64
#define __NR_sched_get_priority_min 126// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sched_rr_get_interval)// loongarch64
#define __NR_sched_rr_get_interval 127// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_restart_syscall)// loongarch64
#define __NR_restart_syscall 128// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_kill)// loongarch64
#define __NR_kill 129// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_tkill)// loongarch64
#define __NR_tkill 130// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_tgkill)// loongarch64
#define __NR_tgkill 131// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sigaltstack)// loongarch64
#define __NR_sigaltstack 132// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_rt_sigsuspend)// loongarch64
#define __NR_rt_sigsuspend 133// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_rt_sigaction)// loongarch64
#define __NR_rt_sigaction 134// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_rt_sigprocmask)// loongarch64
#define __NR_rt_sigprocmask 135// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_rt_sigpending)// loongarch64
#define __NR_rt_sigpending 136// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_rt_sigtimedwait)// loongarch64
#define __NR_rt_sigtimedwait 137// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_rt_sigqueueinfo)// loongarch64
#define __NR_rt_sigqueueinfo 138// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_rt_sigreturn)// loongarch64
#define __NR_rt_sigreturn 139// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setpriority)// loongarch64
#define __NR_setpriority 140// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getpriority)// loongarch64
#define __NR_getpriority 141// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_reboot)// loongarch64
#define __NR_reboot 142// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setregid)// loongarch64
#define __NR_setregid 143// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setgid)// loongarch64
#define __NR_setgid 144// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setreuid)// loongarch64
#define __NR_setreuid 145// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setuid)// loongarch64
#define __NR_setuid 146// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setresuid)// loongarch64
#define __NR_setresuid 147// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getresuid)// loongarch64
#define __NR_getresuid 148// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setresgid)// loongarch64
#define __NR_setresgid 149// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getresgid)// loongarch64
#define __NR_getresgid 150// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setfsuid)// loongarch64
#define __NR_setfsuid 151// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setfsgid)// loongarch64
#define __NR_setfsgid 152// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_times)// loongarch64
#define __NR_times 153// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setpgid)// loongarch64
#define __NR_setpgid 154// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getpgid)// loongarch64
#define __NR_getpgid 155// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getsid)// loongarch64
#define __NR_getsid 156// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setsid)// loongarch64
#define __NR_setsid 157// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getgroups)// loongarch64
#define __NR_getgroups 158// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setgroups)// loongarch64
#define __NR_setgroups 159// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_uname)// loongarch64
#define __NR_uname 160// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sethostname)// loongarch64
#define __NR_sethostname 161// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setdomainname)// loongarch64
#define __NR_setdomainname 162// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getrusage)// loongarch64
#define __NR_getrusage 165// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_umask)// loongarch64
#define __NR_umask 166// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_prctl)// loongarch64
#define __NR_prctl 167// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getcpu)// loongarch64
#define __NR_getcpu 168// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_gettimeofday)// loongarch64
#define __NR_gettimeofday 169// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_settimeofday)// loongarch64
#define __NR_settimeofday 170// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_adjtimex)// loongarch64
#define __NR_adjtimex 171// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getpid)// loongarch64
#define __NR_getpid 172// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getppid)// loongarch64
#define __NR_getppid 173// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getuid)// loongarch64
#define __NR_getuid 174// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_geteuid)// loongarch64
#define __NR_geteuid 175// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getgid)// loongarch64
#define __NR_getgid 176// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getegid)// loongarch64
#define __NR_getegid 177// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_gettid)// loongarch64
#define __NR_gettid 178// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sysinfo)// loongarch64
#define __NR_sysinfo 179// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mq_open)// loongarch64
#define __NR_mq_open 180// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mq_unlink)// loongarch64
#define __NR_mq_unlink 181// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mq_timedsend)// loongarch64
#define __NR_mq_timedsend 182// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mq_timedreceive)// loongarch64
#define __NR_mq_timedreceive 183// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mq_notify)// loongarch64
#define __NR_mq_notify 184// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mq_getsetattr)// loongarch64
#define __NR_mq_getsetattr 185// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_msgget)// loongarch64
#define __NR_msgget 186// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_msgctl)// loongarch64
#define __NR_msgctl 187// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_msgrcv)// loongarch64
#define __NR_msgrcv 188// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_msgsnd)// loongarch64
#define __NR_msgsnd 189// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_semget)// loongarch64
#define __NR_semget 190// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_semctl)// loongarch64
#define __NR_semctl 191// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_semtimedop)// loongarch64
#define __NR_semtimedop 192// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_semop)// loongarch64
#define __NR_semop 193// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_shmget)// loongarch64
#define __NR_shmget 194// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_shmctl)// loongarch64
#define __NR_shmctl 195// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_shmat)// loongarch64
#define __NR_shmat 196// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_shmdt)// loongarch64
#define __NR_shmdt 197// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_socket)// loongarch64
#define __NR_socket 198// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_socketpair)// loongarch64
#define __NR_socketpair 199// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_bind)// loongarch64
#define __NR_bind 200// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_listen)// loongarch64
#define __NR_listen 201// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_accept)// loongarch64
#define __NR_accept 202// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_connect)// loongarch64
#define __NR_connect 203// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getsockname)// loongarch64
#define __NR_getsockname 204// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getpeername)// loongarch64
#define __NR_getpeername 205// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sendto)// loongarch64
#define __NR_sendto 206// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_recvfrom)// loongarch64
#define __NR_recvfrom 207// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setsockopt)// loongarch64
#define __NR_setsockopt 208// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getsockopt)// loongarch64
#define __NR_getsockopt 209// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_shutdown)// loongarch64
#define __NR_shutdown 210// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sendmsg)// loongarch64
#define __NR_sendmsg 211// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_recvmsg)// loongarch64
#define __NR_recvmsg 212// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_readahead)// loongarch64
#define __NR_readahead 213// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_brk)// loongarch64
#define __NR_brk 214// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_munmap)// loongarch64
#define __NR_munmap 215// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mremap)// loongarch64
#define __NR_mremap 216// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_add_key)// loongarch64
#define __NR_add_key 217// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_request_key)// loongarch64
#define __NR_request_key 218// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_keyctl)// loongarch64
#define __NR_keyctl 219// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_clone)// loongarch64
#define __NR_clone 220// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_execve)// loongarch64
#define __NR_execve 221// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mmap)// loongarch64
#define __NR_mmap 222// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fadvise64)// loongarch64
#define __NR_fadvise64 223// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_swapon)// loongarch64
#define __NR_swapon 224// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_swapoff)// loongarch64
#define __NR_swapoff 225// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mprotect)// loongarch64
#define __NR_mprotect 226// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_msync)// loongarch64
#define __NR_msync 227// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mlock)// loongarch64
#define __NR_mlock 228// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_munlock)// loongarch64
#define __NR_munlock 229// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mlockall)// loongarch64
#define __NR_mlockall 230// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_munlockall)// loongarch64
#define __NR_munlockall 231// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mincore)// loongarch64
#define __NR_mincore 232// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_madvise)// loongarch64
#define __NR_madvise 233// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_remap_file_pages)// loongarch64
#define __NR_remap_file_pages 234// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mbind)// loongarch64
#define __NR_mbind 235// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_get_mempolicy)// loongarch64
#define __NR_get_mempolicy 236// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_set_mempolicy)// loongarch64
#define __NR_set_mempolicy 237// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_migrate_pages)// loongarch64
#define __NR_migrate_pages 238// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_move_pages)// loongarch64
#define __NR_move_pages 239// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_rt_tgsigqueueinfo)// loongarch64
#define __NR_rt_tgsigqueueinfo 240// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_perf_event_open)// loongarch64
#define __NR_perf_event_open 241// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_accept4)// loongarch64
#define __NR_accept4 242// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_recvmmsg)// loongarch64
#define __NR_recvmmsg 243// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_wait4)// loongarch64
#define __NR_wait4 260// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_prlimit64)// loongarch64
#define __NR_prlimit64 261// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fanotify_init)// loongarch64
#define __NR_fanotify_init 262// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fanotify_mark)// loongarch64
#define __NR_fanotify_mark 263// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_name_to_handle_at)// loongarch64
#define __NR_name_to_handle_at 264// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_open_by_handle_at)// loongarch64
#define __NR_open_by_handle_at 265// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_clock_adjtime)// loongarch64
#define __NR_clock_adjtime 266// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_syncfs)// loongarch64
#define __NR_syncfs 267// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_setns)// loongarch64
#define __NR_setns 268// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sendmmsg)// loongarch64
#define __NR_sendmmsg 269// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_process_vm_readv)// loongarch64
#define __NR_process_vm_readv 270// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_process_vm_writev)// loongarch64
#define __NR_process_vm_writev 271// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_kcmp)// loongarch64
#define __NR_kcmp 272// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_finit_module)// loongarch64
#define __NR_finit_module 273// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sched_setattr)// loongarch64
#define __NR_sched_setattr 274// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_sched_getattr)// loongarch64
#define __NR_sched_getattr 275// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_renameat2)// loongarch64
#define __NR_renameat2 276// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_seccomp)// loongarch64
#define __NR_seccomp 277// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_getrandom)// loongarch64
#define __NR_getrandom 278// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_memfd_create)// loongarch64
#define __NR_memfd_create 279// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_bpf)// loongarch64
#define __NR_bpf 280// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_execveat)// loongarch64
#define __NR_execveat 281// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_userfaultfd)// loongarch64
#define __NR_userfaultfd 282// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_membarrier)// loongarch64
#define __NR_membarrier 283// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mlock2)// loongarch64
#define __NR_mlock2 284// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_copy_file_range)// loongarch64
#define __NR_copy_file_range 285// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_preadv2)// loongarch64
#define __NR_preadv2 286// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pwritev2)// loongarch64
#define __NR_pwritev2 287// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pkey_mprotect)// loongarch64
#define __NR_pkey_mprotect 288// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pkey_alloc)// loongarch64
#define __NR_pkey_alloc 289// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pkey_free)// loongarch64
#define __NR_pkey_free 290// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_statx)// loongarch64
#define __NR_statx 291// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_io_pgetevents)// loongarch64
#define __NR_io_pgetevents 292// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_rseq)// loongarch64
#define __NR_rseq 293// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_kexec_file_load)// loongarch64
#define __NR_kexec_file_load 294// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pidfd_send_signal)// loongarch64
#define __NR_pidfd_send_signal 424// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_io_uring_setup)// loongarch64
#define __NR_io_uring_setup 425// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_io_uring_enter)// loongarch64
#define __NR_io_uring_enter 426// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_io_uring_register)// loongarch64
#define __NR_io_uring_register 427// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_open_tree)// loongarch64
#define __NR_open_tree 428// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_move_mount)// loongarch64
#define __NR_move_mount 429// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fsopen)// loongarch64
#define __NR_fsopen 430// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fsconfig)// loongarch64
#define __NR_fsconfig 431// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fsmount)// loongarch64
#define __NR_fsmount 432// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_fspick)// loongarch64
#define __NR_fspick 433// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pidfd_open)// loongarch64
#define __NR_pidfd_open 434// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_clone3)// loongarch64
#define __NR_clone3 435// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_close_range)// loongarch64
#define __NR_close_range 436// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_openat2)// loongarch64
#define __NR_openat2 437// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_pidfd_getfd)// loongarch64
#define __NR_pidfd_getfd 438// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_faccessat2)// loongarch64
#define __NR_faccessat2 439// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_process_madvise)// loongarch64
#define __NR_process_madvise 440// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_epoll_pwait2)// loongarch64
#define __NR_epoll_pwait2 441// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_mount_setattr)// loongarch64
#define __NR_mount_setattr 442// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_quotactl_path)// loongarch64
#define __NR_quotactl_path 443// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_landlock_create_ruleset)// loongarch64
#define __NR_landlock_create_ruleset 444// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_landlock_add_rule)// loongarch64
#define __NR_landlock_add_rule 445// loongarch64
#endif// loongarch64
// loongarch64
#if !defined(__NR_landlock_restrict_self)// loongarch64
#define __NR_landlock_restrict_self 446// loongarch64
#endif// loongarch64
// loongarch64
#endif  // SANDBOX_LINUX_SYSTEM_HEADERS_LOONG64_LINUX_SYSCALLS_H_// loongarch64
