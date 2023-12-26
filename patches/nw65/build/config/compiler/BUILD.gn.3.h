    if (!is_nacl) {
      cflags += [
        # Disabled for similar reasons as -Wunused-variable.
        "-Wno-unused-but-set-variable",

        # TODO(https://crbug.com/1202159): Clean up and enable.
        "-Wno-misleading-indentation",

//----replace
    if (!is_nacl) {
      cflags += [
        # Disabled for similar reasons as -Wunused-variable.
        #"-Wno-unused-but-set-variable", # loongarch64

        # TODO(https://crbug.com/1202159): Clean up and enable.
        "-Wno-misleading-indentation",
