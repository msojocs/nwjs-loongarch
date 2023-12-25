//!     macOS/Linux/Fuchsia | x86_64       | `%%rdi`
//!     Linux               | ARM/ARM64    | `r0`/`x0`
//!     Linux               | MIPS/MIPS64  | `$a0`
//!
//!     Additionally, the value `LR` on ARM/ARM64 will be the return address of
//!     this function.

//----replace
//!     macOS/Linux/Fuchsia | x86_64       | `%%rdi`
//!     Linux               | ARM/ARM64    | `r0`/`x0`
//!     Linux               | MIPS/MIPS64  | `$a0`
//!     Linux               | LOONGARCH64  | `$a0`
//!
//!     Additionally, the value `LR` on ARM/ARM64 will be the return address of
//!     this function.
