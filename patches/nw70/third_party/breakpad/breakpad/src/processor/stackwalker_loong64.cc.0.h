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
// stackwalker_loong64.cc: LOONGARCH64-specific stackwalker.// loongarch64
//// loongarch64
// See stackwalker_loong64.h for documentation.// loongarch64
// loongarch64
#include "common/scoped_ptr.h"// loongarch64
#include "google_breakpad/processor/call_stack.h"// loongarch64
#include "google_breakpad/processor/code_modules.h"// loongarch64
#include "google_breakpad/processor/memory_region.h"// loongarch64
#include "google_breakpad/processor/source_line_resolver_interface.h"// loongarch64
#include "google_breakpad/processor/stack_frame_cpu.h"// loongarch64
#include "processor/cfi_frame_info.h"// loongarch64
#include "processor/logging.h"// loongarch64
#include "processor/postfix_evaluator-inl.h"// loongarch64
#include "processor/stackwalker_loong64.h"// loongarch64
#include "processor/windows_frame_info.h"// loongarch64
#include "google_breakpad/common/minidump_cpu_loong64.h"// loongarch64
// loongarch64
namespace google_breakpad {// loongarch64
// loongarch64
StackwalkerLOONGARCH64::StackwalkerLOONGARCH64(const SystemInfo* system_info,// loongarch64
                                 const MDRawContextLOONGARCH64* context,// loongarch64
                                 MemoryRegion* memory,// loongarch64
                                 const CodeModules* modules,// loongarch64
                                 StackFrameSymbolizer* resolver_helper)// loongarch64
: Stackwalker(system_info, memory, modules, resolver_helper),// loongarch64
  context_(context) {// loongarch64
  if (memory_) {// loongarch64
    if (0xffffffffffffffff - memory_->GetBase() < memory_->GetSize() - 1) {// loongarch64
      BPLOG(ERROR) << "Memory out of range for stackwalking loongarch64: "// loongarch64
          << HexString(memory_->GetBase())// loongarch64
          << "+"// loongarch64
          << HexString(memory_->GetSize());// loongarch64
      memory_ = NULL;// loongarch64
    }// loongarch64
  }// loongarch64
}// loongarch64
// loongarch64
StackFrame* StackwalkerLOONGARCH64::GetContextFrame() {// loongarch64
  if (!context_) {// loongarch64
    BPLOG(ERROR) << "Can't get context frame without context.";// loongarch64
    return NULL;// loongarch64
  }// loongarch64
// loongarch64
  StackFrameLOONGARCH64* frame = new StackFrameLOONGARCH64();// loongarch64
// loongarch64
  // The instruction pointer is stored directly in a register, so pull it// loongarch64
  // straight out of the CPU context structure.// loongarch64
  frame->context = *context_;// loongarch64
  frame->context_validity = StackFrameLOONGARCH64::CONTEXT_VALID_ALL;// loongarch64
  frame->trust = StackFrame::FRAME_TRUST_CONTEXT;// loongarch64
  frame->instruction = frame->context.csr_era;// loongarch64
// loongarch64
  return frame;// loongarch64
}// loongarch64
// loongarch64
// Register names for loongarch.// loongarch64
static const char* const kRegisterNames[] = {// loongarch64
   "$r0", "$r1", "$r2", "$r3", "$r4", "$r5", "$r6", "$r7",// loongarch64
   "$r8", "$r9", "$r10", "$r11", "$r12", "$r13", "$r14", "$r15",// loongarch64
   "$r16", "$r17", "$r18", "$r19", "$r20", "$r21", "$r22", "$r23",// loongarch64
   "$r24", "$r25", "$r26", "$r27", "$r28", "$r29", "$r30", "$r31",// loongarch64
   NULL// loongarch64
  // TODO(gordanac): add float point save registers// loongarch64
};// loongarch64
// loongarch64
StackFrameLOONGARCH64* StackwalkerLOONGARCH64::GetCallerByCFIFrameInfo(// loongarch64
    const vector<StackFrame*>& frames,// loongarch64
    CFIFrameInfo* cfi_frame_info) {// loongarch64
  StackFrameLOONGARCH64* last_frame = static_cast<StackFrameLOONGARCH64*>(frames.back());// loongarch64
// loongarch64
  uint64_t pc = 0;// loongarch64
// loongarch64
  // Populate a dictionary with the valid register values in last_frame.// loongarch64
  CFIFrameInfo::RegisterValueMap<uint64_t> callee_registers;// loongarch64
  // Use the STACK CFI data to recover the caller's register values.// loongarch64
  CFIFrameInfo::RegisterValueMap<uint64_t> caller_registers;// loongarch64
// loongarch64
  for (int i = 0; kRegisterNames[i]; ++i) {// loongarch64
    caller_registers[kRegisterNames[i]] = last_frame->context.iregs[i];// loongarch64
    callee_registers[kRegisterNames[i]] = last_frame->context.iregs[i];// loongarch64
  }// loongarch64
// loongarch64
  if (!cfi_frame_info->FindCallerRegs(callee_registers, *memory_,// loongarch64
      &caller_registers))  {// loongarch64
    return NULL;// loongarch64
  }// loongarch64
// loongarch64
  CFIFrameInfo::RegisterValueMap<uint64_t>::const_iterator entry =// loongarch64
      caller_registers.find(".cfa");// loongarch64
// loongarch64
  if (entry != caller_registers.end()) {// loongarch64
    caller_registers["$r3"] = entry->second;// loongarch64
  }// loongarch64
// loongarch64
  entry = caller_registers.find(".ra");// loongarch64
  if (entry != caller_registers.end()) {// loongarch64
    caller_registers["$r1"] = entry->second;// loongarch64
    pc = entry->second - sizeof(pc);// loongarch64
  }// loongarch64
  caller_registers["$pc"] = pc;// loongarch64
  // Construct a new stack frame given the values the CFI recovered.// loongarch64
  scoped_ptr<StackFrameLOONGARCH64> frame(new StackFrameLOONGARCH64());// loongarch64
// loongarch64
  for (int i = 0; kRegisterNames[i]; ++i) {// loongarch64
    CFIFrameInfo::RegisterValueMap<uint64_t>::const_iterator caller_entry =// loongarch64
        caller_registers.find(kRegisterNames[i]);// loongarch64
// loongarch64
    if (caller_entry != caller_registers.end()) {// loongarch64
      // The value of this register is recovered; fill the context with the// loongarch64
      // value from caller_registers.// loongarch64
      frame->context.iregs[i] = caller_entry->second;// loongarch64
      frame->context_validity |= StackFrameLOONGARCH64::RegisterValidFlag(i);// loongarch64
    } else {// loongarch64
      // If the STACK CFI data doesn't mention some callee-save register, and// loongarch64
      // it is valid in the callee, assume the callee has not yet changed it.// loongarch64
      // Calee-save registers according to the loongarch psABI specification are:// loongarch64
      // $s0 to $s7, $fp, $sp// loongarch64
      frame->context.iregs[i] = last_frame->context.iregs[i];// loongarch64
      frame->context_validity |= StackFrameLOONGARCH64::RegisterValidFlag(i);// loongarch64
    }// loongarch64
  }// loongarch64
// loongarch64
  frame->context.csr_era = caller_registers["$pc"];// loongarch64
  frame->instruction = caller_registers["$pc"];// loongarch64
  frame->context_validity |= StackFrameLOONGARCH64::CONTEXT_VALID_PC;// loongarch64
// loongarch64
  frame->context.iregs[MD_CONTEXT_LOONGARCH64_REG_RA] = caller_registers["$r1"];// loongarch64
  frame->context_validity |= StackFrameLOONGARCH64::CONTEXT_VALID_RA;// loongarch64
// loongarch64
  frame->trust = StackFrame::FRAME_TRUST_CFI;// loongarch64
// loongarch64
  return frame.release();// loongarch64
}// loongarch64
// loongarch64
StackFrame* StackwalkerLOONGARCH64::GetCallerFrame(const CallStack* stack,// loongarch64
                                            bool stack_scan_allowed) {// loongarch64
  if (!memory_ || !stack) {// loongarch64
    BPLOG(ERROR) << "Can't get caller frame without memory or stack";// loongarch64
    return NULL;// loongarch64
  }// loongarch64
// loongarch64
  const vector<StackFrame*>& frames = *stack->frames();// loongarch64
  StackFrameLOONGARCH64* last_frame = static_cast<StackFrameLOONGARCH64*>(frames.back());// loongarch64
  scoped_ptr<StackFrameLOONGARCH64> new_frame;// loongarch64
// loongarch64
  // See if there is DWARF call frame information covering this address.// loongarch64
  scoped_ptr<CFIFrameInfo> cfi_frame_info(// loongarch64
    frame_symbolizer_->FindCFIFrameInfo(last_frame));// loongarch64
  if (cfi_frame_info.get())// loongarch64
    new_frame.reset(GetCallerByCFIFrameInfo(frames, cfi_frame_info.get()));// loongarch64
// loongarch64
  // If caller frame is not found in CFI try analyzing the stack.// loongarch64
  if (stack_scan_allowed && !new_frame.get()) {// loongarch64
    new_frame.reset(GetCallerByStackScan(frames));// loongarch64
  }// loongarch64
// loongarch64
  // If nothing worked, tell the caller.// loongarch64
  if (!new_frame.get()) {// loongarch64
    return NULL;// loongarch64
  }// loongarch64
// loongarch64
  // Should we terminate the stack walk? (end-of-stack or broken invariant)// loongarch64
  if (TerminateWalk(new_frame->context.csr_era,// loongarch64
                    new_frame->context.iregs[MD_CONTEXT_LOONGARCH64_REG_SP],// loongarch64
                    last_frame->context.iregs[MD_CONTEXT_LOONGARCH64_REG_SP],// loongarch64
                    frames.size() == 1)) {// loongarch64
    return NULL;// loongarch64
  }// loongarch64
// loongarch64
  return new_frame.release();// loongarch64
}// loongarch64
// loongarch64
StackFrameLOONGARCH64* StackwalkerLOONGARCH64::GetCallerByStackScan(// loongarch64
    const vector<StackFrame*>& frames) {// loongarch64
  const uint32_t kMaxFrameStackSize = 1024;// loongarch64
// loongarch64
  StackFrameLOONGARCH64* last_frame = static_cast<StackFrameLOONGARCH64*>(frames.back());// loongarch64
// loongarch64
  uint64_t last_sp = last_frame->context.iregs[MD_CONTEXT_LOONGARCH64_REG_SP];// loongarch64
  uint64_t caller_pc, caller_sp, caller_fp;// loongarch64
// loongarch64
  // Return address cannot be obtained directly.// loongarch64
  // Force stackwalking.// loongarch64
// loongarch64
  // We cannot use frame pointer to get the return address.// loongarch64
  // We'll scan the stack for a// loongarch64
  // return address. This can happen if last_frame is executing code// loongarch64
  // for a module for which we don't have symbols.// loongarch64
  int count = kMaxFrameStackSize / sizeof(caller_pc);// loongarch64
// loongarch64
  do {// loongarch64
    // Scanning for return address from stack pointer of the last frame.// loongarch64
    if (!ScanForReturnAddress(last_sp, &caller_sp, &caller_pc, count)) {// loongarch64
      // If we can't find an instruction pointer even with stack scanning,// loongarch64
      // give up.// loongarch64
      BPLOG(ERROR) << " ScanForReturnAddress failed ";// loongarch64
      return NULL;// loongarch64
    }// loongarch64
    // Get $fp stored in the stack frame.// loongarch64
    if (!memory_->GetMemoryAtAddress(caller_sp - sizeof(caller_pc),// loongarch64
        &caller_fp)) {// loongarch64
      BPLOG(INFO) << " GetMemoryAtAddress for fp failed " ;// loongarch64
      return NULL;// loongarch64
    }// loongarch64
// loongarch64
    count = count - (caller_sp - last_sp) / sizeof(caller_pc);// loongarch64
    // Now scan the next address in the stack.// loongarch64
    last_sp = caller_sp + sizeof(caller_pc);// loongarch64
  } while ((caller_fp - caller_sp >= kMaxFrameStackSize) && count > 0);// loongarch64
// loongarch64
  if (!count) {// loongarch64
    BPLOG(INFO) << " No frame found " ;// loongarch64
    return NULL;// loongarch64
  }// loongarch64
// loongarch64
  // ScanForReturnAddress found a reasonable return address. Advance// loongarch64
  // $sp to the location above the one where the return address was// loongarch64
  // found.// loongarch64
  caller_sp += sizeof(caller_pc);// loongarch64
  // caller_pc is actually containing $ra value;// loongarch64
  // $pc is two instructions before $ra,// loongarch64
  // so the caller_pc needs to be decremented accordingly.// loongarch64
  caller_pc -= sizeof(caller_pc);// loongarch64
// loongarch64
  // Create a new stack frame (ownership will be transferred to the caller)// loongarch64
  // and fill it in.// loongarch64
  StackFrameLOONGARCH64* frame = new StackFrameLOONGARCH64();// loongarch64
  frame->trust = StackFrame::FRAME_TRUST_SCAN;// loongarch64
  frame->context = last_frame->context;// loongarch64
  frame->context.csr_era = caller_pc;// loongarch64
  frame->context_validity |= StackFrameLOONGARCH64::CONTEXT_VALID_PC;// loongarch64
  frame->instruction = caller_pc;// loongarch64
// loongarch64
  frame->context.iregs[MD_CONTEXT_LOONGARCH64_REG_SP] = caller_sp;// loongarch64
  frame->context_validity |= StackFrameLOONGARCH64::CONTEXT_VALID_SP;// loongarch64
  frame->context.iregs[MD_CONTEXT_LOONGARCH64_REG_FP] = caller_fp;// loongarch64
  frame->context_validity |= StackFrameLOONGARCH64::CONTEXT_VALID_FP;// loongarch64
// loongarch64
  frame->context.iregs[MD_CONTEXT_LOONGARCH64_REG_RA] =// loongarch64
      caller_pc + sizeof(caller_pc);// loongarch64
  frame->context_validity |= StackFrameLOONGARCH64::CONTEXT_VALID_RA;// loongarch64
// loongarch64
  return frame;// loongarch64
}// loongarch64
// loongarch64
}  // namespace google_breakpad// loongarch64
// loongarch64
