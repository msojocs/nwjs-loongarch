      } else {
      deps += [
        ":chrome_dll",
      ]
      }


//----replace
      } else {
      deps += [
        ":chrome_dll",
        "//third_party/ffmpeg:ffmpeg",# loongarch64
      ]
      }

