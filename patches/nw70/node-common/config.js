const cfg = {
  "common.gypi": [
    ['file://./1.h'],
    ['file://./2.h'],
    ['file://./3.h'],
    ['file://./4.h'],
    ['file://./5.h'],
    ['file://./6.h'],
  ],
  'config.gypi': [
    ['file://./cfg1.h'],
    ['file://./cfg2.h'],
  ],
  'deps/base64/base64/lib/env.h': [
    ['file://./env.h'],
  ],
}
module.exports = cfg