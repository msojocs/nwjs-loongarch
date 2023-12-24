            'cflags': [ '--target=arm-linux-gnueabihf' ],
            'ldflags': [ '--target=arm-linux-gnueabihf' ],
          }],
          [ 'target_arch=="ppc" and OS!="aix"', {
            'cflags': [ '-m32' ],
            'ldflags': [ '-m32' ],
//----replace
            'cflags': [ '--target=arm-linux-gnueabihf' ],
            'ldflags': [ '--target=arm-linux-gnueabihf' ],
          }],
          [ 'target_arch=="loong64" and clang==1 and building_nw==1', {
            'cflags': [ '--target=loongarch64-linux-gnu' ],
            'ldflags': [ '--target=loongarch64-linux-gnu' ],
          }],
          [ 'target_arch=="ppc" and OS!="aix"', {
            'cflags': [ '-m32' ],
            'ldflags': [ '-m32' ],
