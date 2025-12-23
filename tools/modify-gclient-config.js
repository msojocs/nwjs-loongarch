const fs = require('fs');
const path = require('path');

const configFile = path.join(__dirname, '..', 'source-code/nwjs/.gclient');
let content = fs.readFileSync(configFile, 'utf-8');
content = content.replace(`"custom_deps" : {
    },`, `"custom_deps" : {
      "src/third_party/WebKit/LayoutTests": None,
      "src/chrome_frame/tools/test/reference_build/chrome": None,
      "src/chrome_frame/tools/test/reference_build/chrome_win": None,
      "src/chrome/tools/test/reference_build/chrome": None,
      "src/chrome/tools/test/reference_build/chrome_linux": None,
      "src/chrome/tools/test/reference_build/chrome_mac": None,
      "src/chrome/tools/test/reference_build/chrome_win": None,
    },`)
fs.writeFileSync(configFile, content, 'utf-8');