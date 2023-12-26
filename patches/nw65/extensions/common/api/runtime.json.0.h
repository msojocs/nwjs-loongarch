      {
        "id": "PlatformArch",
        "type": "string",
        "enum": ["arm", "arm64", "x86-32", "x86-64", "mips", "mips64"],
        "description": "The machine's processor architecture."
      },
      {
        "id": "PlatformNaclArch",
        "description": "The native client architecture. This may be different from arch on some platforms.",
        "type": "string",
        "enum": ["arm", "x86-32", "x86-64", "mips", "mips64"]
      },
      {
        "id": "PlatformInfo",

//----replace
      {
        "id": "PlatformArch",
        "type": "string",
        "enum": ["arm", "arm64", "x86-32", "x86-64", "mips", "mips64", "loong64"],
        "description": "The machine's processor architecture."
      },
      {
        "id": "PlatformNaclArch",
        "description": "The native client architecture. This may be different from arch on some platforms.",
        "type": "string",
        "enum": ["arm", "x86-32", "x86-64", "mips", "mips64", "loong64"]
      },
      {
        "id": "PlatformInfo",
