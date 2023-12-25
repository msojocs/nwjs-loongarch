        'v8_postmortem_support%': 1,
        'clang_dir': '<!(cd <(DEPTH) && pwd -P)/third_party/llvm-build/Release+Asserts',
      }],
      ['GENERATOR == "ninja"', {
        'obj_dir': '<(PRODUCT_DIR)/obj',
        #'v8_base': '<(PRODUCT_DIR)/obj/tools/v8_gypfiles/libv8_snapshot.a',

//----replace
        'v8_postmortem_support%': 1,
        'clang_dir': '<!(cd <(DEPTH) && pwd -P)/third_party/llvm-build/Release+Asserts',
      }],
      [ 'target_arch=="loong64" and building_nw == 1', {
        'clang_dir': '<(clang_base_dir)',
      }],
      ['GENERATOR == "ninja"', {
        'obj_dir': '<(PRODUCT_DIR)/obj',
        #'v8_base': '<(PRODUCT_DIR)/obj/tools/v8_gypfiles/libv8_snapshot.a',
