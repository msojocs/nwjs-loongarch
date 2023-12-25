URL_PREFIX = 'https://commondatastorage.googleapis.com'
URL_PATH = 'chrome-linux-sysroot/toolchain'

VALID_ARCHS = ('arm', 'arm64', 'i386', 'amd64', 'mips', 'mips64el')

ARCH_TRANSLATIONS = {
    'x64': 'amd64',
    'x86': 'i386',
    'mipsel': 'mips',
    'mips64': 'mips64el',
}

DEFAULT_TARGET_PLATFORM = 'bullseye'

//----replace
URL_PREFIX = 'https://commondatastorage.googleapis.com'
URL_PATH = 'chrome-linux-sysroot/toolchain'

VALID_ARCHS = ('arm', 'arm64', 'i386', 'amd64', 'mips', 'mips64el', 'loong64')

ARCH_TRANSLATIONS = {
    'x64': 'amd64',
    'x86': 'i386',
    'mipsel': 'mips',
    'mips64': 'mips64el',
    'loong64': 'loong64',
}

DEFAULT_TARGET_PLATFORM = 'bullseye'
