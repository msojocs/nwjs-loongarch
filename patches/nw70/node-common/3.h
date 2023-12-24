
    # Enable disassembler for `--print-code` v8 options
    'v8_enable_disassembler': 1,
    'v8_host_byteorder': '<!(python -c "import sys; print sys.byteorder")',

    # Sets -dOBJECT_PRINT.
    'v8_enable_object_print%': 1,
//----replace

    # Enable disassembler for `--print-code` v8 options
    'v8_enable_disassembler': 1,
    'v8_host_byteorder': '<!(python -c "import sys; print(sys.byteorder)")',

    # Sets -dOBJECT_PRINT.
    'v8_enable_object_print%': 1,
