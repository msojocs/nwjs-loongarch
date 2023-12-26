/* Copyright (c) 2013, Google Inc.// loongarch64
 * All rights reserved.// loongarch64
 *// loongarch64
 * Redistribution and use in source and binary forms, with or without// loongarch64
 * modification, are permitted provided that the following conditions are// loongarch64
 * met:// loongarch64
 *// loongarch64
 *     * Redistributions of source code must retain the above copyright// loongarch64
 * notice, this list of conditions and the following disclaimer.// loongarch64
 *     * Redistributions in binary form must reproduce the above// loongarch64
 * copyright notice, this list of conditions and the following disclaimer// loongarch64
 * in the documentation and/or other materials provided with the// loongarch64
 * distribution.// loongarch64
 *     * Neither the name of Google Inc. nor the names of its// loongarch64
 * contributors may be used to endorse or promote products derived from// loongarch64
 * this software without specific prior written permission.// loongarch64
 *// loongarch64
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS// loongarch64
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT// loongarch64
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR// loongarch64
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT// loongarch64
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,// loongarch64
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT// loongarch64
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,// loongarch64
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY// loongarch64
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT// loongarch64
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE// loongarch64
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */// loongarch64
// loongarch64
/* minidump_format.h: A cross-platform reimplementation of minidump-related// loongarch64
 * portions of DbgHelp.h from the Windows Platform SDK.// loongarch64
 *// loongarch64
 * (This is C99 source, please don't corrupt it with C++.)// loongarch64
 *// loongarch64
 * This file contains the necessary definitions to read minidump files// loongarch64
 * produced on LOONGARCH.  These files may be read on any platform provided// loongarch64
 * that the alignments of these structures on the processing system are// loongarch64
 * identical to the alignments of these structures on the producing system.// loongarch64
 * For this reason, precise-sized types are used.  The structures defined// loongarch64
 * by this file have been laid out to minimize alignment problems by// loongarch64
 * ensuring that all members are aligned on their natural boundaries.// loongarch64
 * In some cases, tail-padding may be significant when different ABIs specify// loongarch64
 * different tail-padding behaviors.  To avoid problems when reading or// loongarch64
 * writing affected structures, MD_*_SIZE macros are provided where needed,// loongarch64
 * containing the useful size of the structures without padding.// loongarch64
 *// loongarch64
 * Structures that are defined by Microsoft to contain a zero-length array// loongarch64
 * are instead defined here to contain an array with one element, as// loongarch64
 * zero-length arrays are forbidden by standard C and C++.  In these cases,// loongarch64
 * *_minsize constants are provided to be used in place of sizeof.  For a// loongarch64
 * cleaner interface to these sizes when using C++, see minidump_size.h.// loongarch64
 *// loongarch64
 * These structures are also sufficient to populate minidump files.// loongarch64
 *// loongarch64
 * Because precise data type sizes are crucial for this implementation to// loongarch64
 * function properly and portably, a set of primitive types with known sizes// loongarch64
 * are used as the basis of each structure defined by this file.// loongarch64
 */// loongarch64
// loongarch64
/*// loongarch64
 * Loongarch64 support// loongarch64
 */// loongarch64
// loongarch64
#ifndef GOOGLE_BREAKPAD_COMMON_MINIDUMP_CPU_LOONGARCH64_H__// loongarch64
#define GOOGLE_BREAKPAD_COMMON_MINIDUMP_CPU_LOONGARCH64_H__// loongarch64
// loongarch64
#define MD_CONTEXT_LOONGARCH64_GPR_COUNT 32// loongarch64
#define MD_FLOATINGSAVEAREA_LOONGARCH64_FPR_COUNT 32// loongarch64
// loongarch64
typedef struct {// loongarch64
  /* 32 64-bit floating point registers, f0..f31 */// loongarch64
  uint64_t regs[MD_FLOATINGSAVEAREA_LOONGARCH64_FPR_COUNT];// loongarch64
  uint64_t fcc;// loongarch64
  uint32_t fcsr;// loongarch64
} MDFloatingSaveAreaLoongarch64;// loongarch64
// loongarch64
typedef struct {// loongarch64
  /* The next field determines the layout of the structure, and which parts// loongarch64
   * of it are populated.// loongarch64
   */// loongarch64
  uint32_t context_flags;// loongarch64
  uint32_t _pad0;// loongarch64
// loongarch64
  /* 32 64-bit integer registers, r0..r31.// loongarch64
   * Note the following fixed uses:// loongarch64
   *   r3 is the stack pointer.// loongarch64
   *   r1 is the return address.// loongarch64
   */// loongarch64
  uint64_t iregs[MD_CONTEXT_LOONGARCH64_GPR_COUNT];// loongarch64
// loongarch64
  uint64_t csr_era;// loongarch64
// loongarch64
  /* The next field is included with MD_CONTEXT_LOONGARCH64_FLOATING_POINT. */// loongarch64
  MDFloatingSaveAreaLoongarch64 float_save;// loongarch64
// loongarch64
} MDRawContextLOONGARCH64;// loongarch64
// loongarch64
/* Indices into iregs for registers with a dedicated or conventional// loongarch64
 * purpose.// loongarch64
 */// loongarch64
enum MDLoongarchRegisterNumbers {// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_RA     = 1,// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_GP     = 2,// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_SP     = 3,// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_FP     = 22,// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_S0     = 23,// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_S1,// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_S2,// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_S3,// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_S4,// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_S5,// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_S6,// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_S7,// loongarch64
  MD_CONTEXT_LOONGARCH64_REG_S8,// loongarch64
};// loongarch64
// loongarch64
/**// loongarch64
 * Breakpad defines for Loongarch64// loongarch64
 */// loongarch64
#define MD_CONTEXT_LOONGARCH64  0x00800000// loongarch64
#define MD_CONTEXT_LOONGARCH64_INTEGER           (MD_CONTEXT_LOONGARCH64| 0x00000002)// loongarch64
#define MD_CONTEXT_LOONGARCH64_FLOATING_POINT    (MD_CONTEXT_LOONGARCH64 | 0x00000004)// loongarch64
// loongarch64
#define MD_CONTEXT_LOONGARCH64_FULL              (MD_CONTEXT_LOONGARCH64_INTEGER | \// loongarch64
                                                 MD_CONTEXT_LOONGARCH64_FLOATING_POINT)// loongarch64
// loongarch64
#define MD_CONTEXT_LOONGARCH64_ALL               (MD_CONTEXT_LOONGARCH64_INTEGER | \// loongarch64
                                                 MD_CONTEXT_LOONGARCH64_FLOATING_POINT)// loongarch64
// loongarch64
#endif  // GOOGLE_BREAKPAD_COMMON_MINIDUMP_CPU_LOONGARCH64_H__// loongarch64
