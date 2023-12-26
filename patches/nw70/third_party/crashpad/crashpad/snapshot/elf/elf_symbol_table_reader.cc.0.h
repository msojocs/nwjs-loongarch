  SymEnt entry;
  std::string string;
  size_t i = 0;
  while (i < num_entries_ && memory_->Read(address, sizeof(entry), &entry)) {
    if (elf_reader_->ReadDynamicStringTableAtOffset(entry.st_name, &string) &&
        string == name) {
      info_out->address = entry.st_value;
      info_out->size = entry.st_size;
      info_out->shndx = entry.st_shndx;
      info_out->binding = GetBinding(entry);
      info_out->type = GetType(entry);
      info_out->visibility = GetVisibility(entry);
      return true;
    }
    // TODO(scottmg): This should respect DT_SYMENT if present.
    address += sizeof(entry);

//----replace
  SymEnt entry;
  std::string string;
  size_t i = 0;
  const char vdso_prefix[] = "__vdso_";// loongarch64
// loongarch64
  while (i < num_entries_ && memory_->Read(address, sizeof(entry), &entry)) {
    if (elf_reader_->ReadDynamicStringTableAtOffset(entry.st_name, &string)) {// loongarch64
      if (string.find(vdso_prefix) == 0)// loongarch64
        string.erase(0, sizeof(vdso_prefix) - 1);// loongarch64
      if (string == name) {// loongarch64
        info_out->address = entry.st_value;// loongarch64
        info_out->size = entry.st_size;// loongarch64
        info_out->shndx = entry.st_shndx;// loongarch64
        info_out->binding = GetBinding(entry);// loongarch64
        info_out->type = GetType(entry);// loongarch64
        info_out->visibility = GetVisibility(entry);// loongarch64
        return true;// loongarch64
      }// loongarch64
    }
    // TODO(scottmg): This should respect DT_SYMENT if present.
    address += sizeof(entry);
