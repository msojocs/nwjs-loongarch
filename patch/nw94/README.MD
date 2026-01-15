# DecodeJSONInRust
从此版本开始 `DecodeJSONInRust` 工作会崩溃；

当rust的编译flag `opt-level=0` 时正常， `opt-level=1` 时崩溃；

有隐患，故直接禁用。