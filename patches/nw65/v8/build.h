  if (is_clang) {
    cflags += [
      "-Wmissing-field-initializers",

      # TODO(v8:12245): Fix shadowing instances and remove.
      "-Wno-shadow",
    ]

//----replace
  if (is_clang) {
    cflags += [
      "-Wmissing-field-initializers",

      # TODO(v8:12245): Fix shadowing instances and remove.
      "-Wno-shadow",
      "-Wno-error=enum-constexpr-conversion",
    ]
