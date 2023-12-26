  if (is_linux) {
    deps += [ "//chrome:xdg_mime", "//components/crash/core/app:chrome_crashpad_handler", ":copy_icd" ]
  }
//----replace
  if (is_linux) {
    deps += [ "//chrome:xdg_mime", "//components/crash/core/app:chrome_crashpad_handler" ]
  }