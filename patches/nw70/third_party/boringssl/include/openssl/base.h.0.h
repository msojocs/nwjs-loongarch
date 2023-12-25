#define OPENSSL_32_BIT
#elif defined(__myriad2__)
#define OPENSSL_32_BIT
#else
// Note BoringSSL only supports standard 32-bit and 64-bit two's-complement,
// little-endian architectures. Functions will not produce the correct answer

//----replace
#define OPENSSL_32_BIT
#elif defined(__myriad2__)
#define OPENSSL_32_BIT
#elif defined(__loongarch64)
#define OPENSSL_64_BIT
#define OPENSSL_LOONG64
#else
// Note BoringSSL only supports standard 32-bit and 64-bit two's-complement,
// little-endian architectures. Functions will not produce the correct answer
