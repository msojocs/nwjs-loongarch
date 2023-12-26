    num_matching_contexts++;
  if (context_size == sizeof(MDRawContextMIPS))
    num_matching_contexts++;
  return num_matching_contexts == 1;
}


//----replace
    num_matching_contexts++;
  if (context_size == sizeof(MDRawContextMIPS))
    num_matching_contexts++;
  if (context_size == sizeof(MDRawContextLOONGARCH64)) // loongarch64
    num_matching_contexts++; // loongarch64
  return num_matching_contexts == 1;
}

