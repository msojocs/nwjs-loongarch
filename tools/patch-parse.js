  h: ' // loongarch64',
  cc: ' // loongarch64',
  gn: ' # loongarch64',
  gni: ' # loongarch64',
  S: ' /* loongarch64 */'
  const base = path.resolve(__dirname, `../patches/nw65/${target}`)
      let l = line.slice(1)
      if (!l.endsWith('\\') && data.mode != 'copy')
        l += data.comment
      current.after += `${l}\n`;
      current.after += line.slice(1) + `\n`;
      data.comment = ''
      'path': 'third_party/boringssl/src/',
      'name': 'loongarch64_support_webrtc_for_nwjs',
      'path': 'third_party/webrtc/',
const configFile = path.resolve(__dirname, `../patches/nw65/config.js`)