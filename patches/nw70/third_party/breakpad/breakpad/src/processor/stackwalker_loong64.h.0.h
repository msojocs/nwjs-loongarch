// Copyright (c) 2013 Google Inc.// loongarch64
// All rights reserved.// loongarch64
//// loongarch64
// Redistribution and use in source and binary forms, with or without// loongarch64
// modification, are permitted provided that the following conditions are// loongarch64
// met:// loongarch64
//// loongarch64
//     * Redistributions of source code must retain the above copyright// loongarch64
// notice, this list of conditions and the following disclaimer.// loongarch64
//     * Redistributions in binary form must reproduce the above// loongarch64
// copyright notice, this list of conditions and the following disclaimer// loongarch64
// in the documentation and/or other materials provided with the// loongarch64
// distribution.// loongarch64
//     * Neither the name of Google Inc. nor the names of its// loongarch64
// contributors may be used to endorse or promote products derived from// loongarch64
// this software without specific prior written permission.// loongarch64
//// loongarch64
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS// loongarch64
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT// loongarch64
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR// loongarch64
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT// loongarch64
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,// loongarch64
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT// loongarch64
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,// loongarch64
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY// loongarch64
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT// loongarch64
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE// loongarch64
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.// loongarch64
// loongarch64
// stackwalker_loong64.h: LOONGARCH64-specific stackwalker.// loongarch64
//// loongarch64
// Provides stack frames given LOONGARCH64 register context and a memory region// loongarch64
// corresponding to a LOONGARCH64 stack.// loongarch64
// loongarch64
#ifndef PROCESSOR_STACKWALKER_LOONGARCH64_H__// loongarch64
#define PROCESSOR_STACKWALKER_LOONGARCH64_H__// loongarch64
// loongarch64
#include "google_breakpad/common/breakpad_types.h"// loongarch64
#include "google_breakpad/common/minidump_format.h"// loongarch64
#include "google_breakpad/processor/stackwalker.h"// loongarch64
#include "google_breakpad/processor/stack_frame_cpu.h"// loongarch64
#include "processor/cfi_frame_info.h"// loongarch64
// loongarch64
namespace google_breakpad {// loongarch64
// loongarch64
class CodeModules;// loongarch64
// loongarch64
class StackwalkerLOONGARCH64 : public Stackwalker {// loongarch64
 public:// loongarch64
  // Context is a loongarch64 context object that gives access to// loongarch64
  // loongarch64-specific register state corresponding to the innermost// loongarch64
  // called frame to be included in the stack.  The other arguments are// loongarch64
  // passed directly through to the base Stackwalker constructor.// loongarch64
  StackwalkerLOONGARCH64(const SystemInfo* system_info,// loongarch64
                  const MDRawContextLOONGARCH64* context,// loongarch64
                  MemoryRegion* memory,// loongarch64
                  const CodeModules* modules,// loongarch64
                  StackFrameSymbolizer* frame_symbolizer);// loongarch64
// loongarch64
 private:// loongarch64
  // Implementation of Stackwalker, using loongarch64 context and stack conventions.// loongarch64
  virtual StackFrame* GetContextFrame();// loongarch64
  virtual StackFrame* GetCallerFrame(const CallStack* stack,// loongarch64
                                     bool stack_scan_allowed);// loongarch64
// loongarch64
  // Use cfi_frame_info (derived from STACK CFI records) to construct// loongarch64
  // the frame that called frames.back(). The caller takes ownership// loongarch64
  // of the returned frame. Return NULL on failure.// loongarch64
  StackFrameLOONGARCH64* GetCallerByCFIFrameInfo(const vector<StackFrame*>& frames,// loongarch64
                                          CFIFrameInfo* cfi_frame_info);// loongarch64
// loongarch64
  // Scan the stack for plausible return address and frame pointer pair. // loongarch64
  // The caller takes ownership of the returned frame. Return NULL on failure.// loongarch64
  StackFrameLOONGARCH64* GetCallerByStackScan(const vector<StackFrame*>& frames);// loongarch64
// loongarch64
  // Stores the CPU context corresponding to the innermost stack frame to// loongarch64
  // be returned by GetContextFrame.// loongarch64
  const MDRawContextLOONGARCH64* context_;// loongarch64
};// loongarch64
// loongarch64
}  // namespace google_breakpad// loongarch64
// loongarch64
#endif  // PROCESSOR_STACKWALKER_LOONGARCH64_H__// loongarch64
