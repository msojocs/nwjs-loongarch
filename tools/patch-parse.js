const fs = require('fs');
const path = require('path');

const suffix2comment = {
  h: '// loongarch64',
  cc: '// loongarch64',
  gn: '# loongarch64'
}
function splitPatchFile(patchFilePath, target) {
  const content = fs.readFileSync(patchFilePath).toString()
  const lines = content.split('\n');
  const result = {}
  const data = {
    mode: 'file',
    name: '',
    comment: '',
    list: []
  }
  let current = {
    before: '',
    after: '',
  }

  const base = path.resolve(__dirname, `../patches/nw70/${target}`)
  console.log('base:', base)
  for (let i = 0; i < lines.length; i++) {
    const line = lines[i];

    if (line.startsWith('diff')) {
      const cmds = line.split(' ')
      data.name = cmds[2]
      const suffix = data.name.split('.').reverse()[0]
      if (suffix2comment[suffix]) {
        data.comment = suffix2comment[suffix]
      }
      // data.name = cmds[3]
      continue
    } else if (line.startsWith('index') || line.startsWith('new file mode ')){
      continue
    } else if (line.startsWith('@@')) {
      // 新的修改
      // const idx = line.lastIndexOf('@@')
      current = {
        before: '',
        after: '',
      }
      data.list.push(current)
      continue
    } else if (line.startsWith('---')) {
      if (line.slice(4) === '/dev/null') {
        data.mode = 'copy'
      }
      continue
    } else if (line.startsWith('+++')) {
      continue
    } else if (line.startsWith('-')) {
      current.before += line.slice(1) + '\n';
    } else if (line.startsWith('+')) {
      current.after += line.slice(1) + `${data.comment}\n`;
    } else if (line.startsWith(' ')) {
      current.before += line.slice(1) + '\n';
      current.after += line.slice(1) + `${data.comment}\n`;
    }
    if (i + 1 === lines.length || lines[i + 1].startsWith('diff')) {
      data.path = path.resolve(base, data.name)
      // after.path = path.resolve(base, after.name)
      // 结束，写入重置
      try {
        fs.mkdirSync(path.dirname(data.path), {recursive: true})
      }catch(e){}
      try {
        fs.mkdirSync(path.dirname(data.path), {recursive: true})
      }catch(e){}
      const relativePath = path.join(target, data.name)
      console.log(`${target} + ${data.name} => ${relativePath}`)
      result[relativePath] = []
      for (let j = 0; j < data.list.length; j++) {
        const ele = data.list[j];
        if (data.mode === 'file') {
          fs.writeFileSync(`${data.path}.${j}.h`, `${ele.before}\n//----replace\n${ele.after}`)
        }
        else if (data.mode === 'copy') {
          fs.writeFileSync(`${data.path}.${j}.h`, ele.after)
        }
        result[relativePath].push([`${data.mode}://./${relativePath}.${j}.h`])
      }
      // fs.writeFileSync(after.path, after.content)
      data.name = ''
      data.mode = 'file'
      data.path = ''
      data.list = []
    }
  }
  return result
}
const cfg = [
  // # Add loongarch64 support for nwjs build
  {
      // # Add loongarch64 support in chromium for nwjs build
      'name': 'loongarch64_support_src_for_nwjs',
      path: ''
  },
  {
      // # Add loongarch64 support in breakpad for nwjs build
      'name': 'loongarch64_support_breakpad_for_nwjs',
      'path': 'third_party/breakpad/breakpad/',
  },
  {
      // # Add loongarch64 support in boringssl for nwjs build
      'name': 'loongarch64_support_boringssl_for_nwjs',
      'path': 'third_party/boringssl/',
  },
  {
      // # Add loongarch64 support in dawn for nwjs build
      'name': 'loongarch64_support_dawn_for_nwjs',
      'path': 'third_party/dawn/',
  },
  {
      // # Add loongarch64 support in ffmpeg for nwjs build
      'name': 'loongarch64_support_ffmpeg_for_nwjs',
      'path': 'third_party/ffmpeg/',
  },
  {
      // # Add loongarch64 support in lss for nwjs build
      'name': 'loongarch64_support_lss_for_nwjs',
      'path': 'third_party/lss/',
  },
  {
      // # Add loongarch64 support in node for nwjs build
      'name': 'loongarch64_support_node_for_nwjs',
      'path': 'third_party/node-nw/',
  },
  {
      // # Add loongarch64 support in v8 for nwjs build
      'name': 'loongarch64_support_v8_for_nwjs',
      'path': 'v8/',
  }
]
const config = {}
for (const c of cfg) {
  const tc = splitPatchFile(`/home/msojocs/loongarch-nwjs/source-code/nwjs/src/content/nw/patch/patches/${c.name}.patch`, c.path);
  for (const k in tc) {
    config[k] = tc[k]
  }
}

const fixPath = {
  'third_party/boringssl/include/openssl/base.h': 'third_party/boringssl/src/include/openssl/base.h'
}

const configFile = path.resolve(__dirname, `../patches/nw70/config.js`)
fs.writeFileSync(configFile, `const config = ${JSON.stringify(config, null, 2)}\n\nmodule.exports = config`)