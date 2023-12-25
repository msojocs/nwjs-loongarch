  }
} else if (current_cpu == "riscv64") {
  cpu_arch_full = "generic"
} else {
  cpu_arch_full = current_cpu
}

//----replace
  }
} else if (current_cpu == "riscv64") {
  cpu_arch_full = "generic"
} else if (current_cpu == "loong64") {
  cpu_arch_full = "generic"
} else {
  cpu_arch_full = current_cpu
}
