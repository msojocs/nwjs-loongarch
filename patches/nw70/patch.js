#!/usr/bin/env node
const { execSync } = require('child_process')
const fs = require('fs')
const path = require('path')
const args = process.argv.slice(2)
const srcDir = args[0]

const patchSysroot = async () => {
  const cfgFile = path.resolve(srcDir, 'build/linux/sysroot_scripts/sysroots.json')
  const c = JSON.parse(fs.readFileSync(cfgFile).toString())
  if (!c.bullseye_loong64) {
    c.bullseye_loong64 = {
      Key: "20230611T210420Z-2",
      Sha1Sum: "1b857baabd7999ff0d6949a8973f896836ac45ac",
      SysrootDir: "debian_bullseye_loong64-sysroot",
      Tarball: "debian_bullseye_loong64_sysroot.tar.xz",
      URL: c.bullseye_amd64.URL
    }
    fs.writeFileSync(cfgFile, JSON.stringify(c, null, 4))
  }

  const pyFile = path.resolve(srcDir, 'build/linux/sysroot_scripts/install-sysroot.py')
  let content = fs.readFileSync(pyFile).toString()
  content = content.replace("'mips64el')", "'mips64el', 'loong64')")
  content = content.replace("'mips64': 'mips64el',\n", "'mips64': 'mips64el','loong64': 'loong64',\n")
  content = content.replace("'mips64': 'mips64el',\r\n", "'mips64': 'mips64el','loong64': 'loong64',\r\n")
  fs.writeFileSync(pyFile, content)
}
// let cfgList = execSync(`find ${__dirname} -type f -name "config.js"`)
// cfgList = cfgList.toString().split('\n').filter(e => e.length)
// console.log(cfgList)
// console.log('current dir:', __dirname)
// for (const cfg of cfgList) {
//   console.log(path.dirname(cfg))
//   const d = require(cfg)
//   console.log('d:', d)
// }
// process.exit(1)
const patchCfg = require('./config')
const extCfg = {
  'content/nw/BUILD.gn': [
    ['file://./nw/build.h'],
    ['file://./nw/build2.h']
  ],
  'content/nw/tools/package_binaries.py': [
    ['file://./nw/package_binaries.h'],
  ],
  'third_party/wayland/src/src/wayland-client-core.h': [
    
    ['file://./wayland-client-core/1.h'],
  ]
}
for (const k in extCfg) {
  patchCfg[k] = extCfg[k]
}

const patchConfig = () => {
  let total = 0
  let replace = 0
  for (const file in patchCfg) {
    const targetFile = path.resolve(srcDir, file)
    let content = ''
    if (fs.existsSync(targetFile)) 
      content = fs.readFileSync(targetFile).toString()
    const cfg = patchCfg[file]
    for (const d of cfg) {
      total++

      let from = d[0]
      let to = d[1]
      try {
        // 复制文件
        if (from.startsWith('copy://')) {
          const p = path.resolve(__dirname, from.substring(7))
          const d = path.dirname(targetFile)
          if (!fs.existsSync(d)) {
            try{
              console.log('mkdir:', d)
              fs.mkdirSync(d, {recursive: true})
            }catch(e){}
          }
          from = fs.readFileSync(p).toString()
          if (content != from) {
            replace++
            content = from
            // console.log(`[copy]success: ${file} - `, d[0], ' applied.')
          }
          continue;
        }

        // 文件替换
        if (from.startsWith('file://')) {
          from = fs.readFileSync(path.resolve(__dirname, from.substring(7))).toString()
        }
        if (d.length == 2){
          // 两个文件，一个修改前，一个修改后
          if (to.startsWith('file://')) {
            to = fs.readFileSync(path.resolve(__dirname, to.substring(7))).toString()
          }
        }
        else if (d.length == 1) {
          // 一个文件，包含了修改前与修改后的数据，使用 \n//----replace\n 分割
          const t = from.split('\n//----replace\n')
          from = t[0]
          to = t[1]
        }
      } catch (error) {
        
      }
      if (typeof from === 'string') {
        if (content.includes(from)) {
          replace++
          content = content.replaceAll(from, to)
          // console.log(`[file]success: ${file} - `, d[0], ' applied.')
        }
        else {
          console.log(`warn: ${file} - `, d[0], ' not applied. not include.')
        }
      }
      else {
        // 有正则表达式，不能直接includes判断
        const old = content
        content = content.replace(from, to)
        if (content != old) {
          replace++
          // console.log(`[file]success: ${file} - `, d[0], ' applied.')
        }
        else {
          console.log(`warn: ${file} - `, d[0], ' not applied. replace not work.')
        }
      }
    }
    fs.writeFileSync(targetFile, content)
  }
  console.log(`Total patches: ${total}, Apply: ${replace}`)
}

  ; (async () => {
    console.log('src:', srcDir)
    await patchSysroot()
    patchConfig()
  })()