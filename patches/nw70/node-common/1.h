    'werror': '',                     # Turn off -Werror in V8 build.
    'visibility%': 'hidden',          # V8's visibility setting
    'target_arch%': 'ia32',           # set v8's target architecture
    'host_arch%': 'ia32',             # set v8's host architecture
    'want_separate_host_toolset%': 1, # V8 should not build target and host
    'library%': 'static_library',     # allow override to 'shared_library' for DLL/.so builds
//----replace
    'werror': '',                     # Turn off -Werror in V8 build.
    'visibility%': 'hidden',          # V8's visibility setting
    'target_arch%': 'loong64',           # set v8's target architecture
    'host_arch%': 'loong64',             # set v8's host architecture
    'want_separate_host_toolset%': 1, # V8 should not build target and host
    'library%': 'static_library',     # allow override to 'shared_library' for DLL/.so builds