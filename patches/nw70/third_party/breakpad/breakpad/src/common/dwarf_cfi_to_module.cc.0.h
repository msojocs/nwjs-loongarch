                    sizeof(kRegisterNames) / sizeof(kRegisterNames[0]));
}

bool DwarfCFIToModule::Entry(size_t offset, uint64_t address, uint64_t length,
                             uint8_t version, const string& augmentation,
                             unsigned return_address) {

//----replace
                    sizeof(kRegisterNames) / sizeof(kRegisterNames[0]));
}

vector<string> DwarfCEIToModule::RegisterNames::LOONGARCH64() {// loongarch64
  static const char* const kRegisterNames[] = {// loongarch64
    "$zero", "$ra",  "$tp",  "$sp",  "$a0",   "$a1",  "$a2",  "$a3",// loongarch64
    "$a4",   "$a5",  "$a6",  "$a7",  "$v0",   "$v1",  "$t0",  "$t1",// loongarch64
    "$t2",   "$t3",  "$t4",  "$t5",  "$t6",   "$t7",  "$t8",  "$x",// loongarch64
    "$fp",   "$s0",  "$s1",  "$s2",  "$s3",   "$s4",  "$s5",  "$s6",// loongarch64
    "$s7",   "$s8",  "$pc",  "$fa0", "$fa1",  "$fa2", "$fa3", "$fa4",// loongarch64
    "$fa5",  "$fa6", "$fa7", "$fv0", "$fv1",  "$ft0", "$ft1", "$ft2",// loongarch64
    "$ft3",  "$ft4", "$ft5", "$ft6", "$ft7",  "$ft8", "$ft9", "$ft10",// loongarch64
    "$ft11", "$ft12","$ft13","$ft14","$ft15", "$fs0", "$fs1", "$fs2",// loongarch64
    "$fs3",  "$fs4", "$fs5", "$fs6", "$fs7"// loongarch64
  };// loongarch64
// loongarch64
  return MakeVector(kRegisterNames,// loongarch64
		    sizeof(kRegisterNames) / sizeof(kRegisterNames[0]));// loongarch64
}// loongarch64
// loongarch64
bool DwarfCFIToModule::Entry(size_t offset, uint64_t address, uint64_t length,
                             uint8_t version, const string& augmentation,
                             unsigned return_address) {
