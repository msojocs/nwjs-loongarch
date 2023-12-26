    // baseline policy handles fstatat().
    // Note that this will cause some legitimate but strange invocations of
    // fstatat() to fail, see https://crbug.com/1243290#c8 for details.
    const bpf_dsl::Arg<int> flags(3);
    return bpf_dsl::If((flags & AT_EMPTY_PATH) == AT_EMPTY_PATH,
                       RewriteFstatatSIGSYS(BPFBasePolicy::GetFSDeniedErrno()))
        .Else(handle_via_broker);
  } else {
    return handle_via_broker;

//----replace
    // baseline policy handles fstatat().
    // Note that this will cause some legitimate but strange invocations of
    // fstatat() to fail, see https://crbug.com/1243290#c8 for details.
#if defined(__loongarch64)// loongarch64
    const bpf_dsl::Arg<int> flags(2);// loongarch64
    return bpf_dsl::If((flags & AT_EMPTY_PATH) == AT_EMPTY_PATH,// loongarch64
		       RewriteStatxSIGSYS(BPFBasePolicy::GetFSDeniedErrno()))// loongarch64
#else// loongarch64
    const bpf_dsl::Arg<int> flags(3);
    return bpf_dsl::If((flags & AT_EMPTY_PATH) == AT_EMPTY_PATH,
                       RewriteFstatatSIGSYS(BPFBasePolicy::GetFSDeniedErrno()))
#endif// loongarch64
        .Else(handle_via_broker);
  } else {
    return handle_via_broker;
