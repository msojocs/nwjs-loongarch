#endif  // defined(__clang_analyzer__)

// Use nomerge attribute to disable optimization of merging multiple same calls.
#if defined(__clang__) && __has_attribute(nomerge)
#define NOMERGE [[clang::nomerge]]
#else
#define NOMERGE

//----replace
#endif  // defined(__clang_analyzer__)

// Use nomerge attribute to disable optimization of merging multiple same calls.
#if defined(__clang__) && __has_attribute(nomerge) && __clang_major__ != 11 // loongarch64
#define NOMERGE [[clang::nomerge]]
#else
#define NOMERGE
