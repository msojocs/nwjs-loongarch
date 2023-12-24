} else if (current_cpu == "riscv64") {
    # Conditional and empty body needed to avoid assert() below.
  } else {
    assert(false, "Unknown cpu target")
  }
//----replace
} else if (current_cpu == "riscv64") {
    # Conditional and empty body needed to avoid assert() below.
  } else if (current_cpu == "loong64") {
    # Conditional and empty body needed to avoid assert() below.
  } else {
    assert(false, "Unknown cpu target")
  }