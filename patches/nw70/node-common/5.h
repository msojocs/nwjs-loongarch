      ['OS=="linux" and target_arch=="arm" and <(building_nw)==1', {
        'sysroot': '<!(cd <(DEPTH) && pwd -P)/build/linux/debian_sid_arm-sysroot',
      }],
      ['OS=="mac"', {
        'clang%': 1,
        'obj_dir%': '<(PRODUCT_DIR)/obj.target',
//----replace
      ['OS=="linux" and target_arch=="arm" and <(building_nw)==1', {
        'sysroot': '<!(cd <(DEPTH) && pwd -P)/build/linux/debian_sid_arm-sysroot',
      }],
      ['OS=="linux" and target_arch=="loong64" and <(building_nw)==1', {
        'sysroot': '<!(cd <(DEPTH) && pwd -P)/build/linux/debian_bullseye_loong64-sysroot',
      }],
      ['OS=="mac"', {
        'clang%': 1,
        'obj_dir%': '<(PRODUCT_DIR)/obj.target',