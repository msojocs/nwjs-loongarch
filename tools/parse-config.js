
const args = process.argv.slice(2);
const { exit } = require("process");
const config = require("../config/config.json");


// 16.17.0后可以使用util.parseArgs，目前是16.11.0
const options = {
    '--target': {
        type: 'string',
    },
    '--get-nw-version': {
        type: 'boolean',
    },
    '--get-llvm-tag': {
        type: 'boolean',
    },
    '--get-llvm-version': {
        type: 'boolean',
    },
    '--get-llvm-repo': {
        type: 'boolean',
    },
    '--use-mirror': {
        type: 'boolean',
    },
    '--get-chromium-repo': {
        type: 'boolean',
    },
    '--get-v8-repo': {
        type: 'boolean',
    },
    '--get-node-repo': {
        type: 'boolean',
    },
    '--get-nw-repo': {
        type: 'boolean',
    },
    '--get-binutils-repo': {
        type: 'boolean',
    },
    '--get-binutils-tag': {
        type: 'boolean',
    },
}
const configArg = {
    target: config.buildTarget,
}
for (let i = 0; i < args.length; i++) {
    if (options[args[i]]) {
        if (options[args[i]].type === 'string') {
            i++;
            if (i < args.length) {
                if (args[i - 1] === '--target') {
                    if (args[i].startsWith('nw')) {
                        configArg.target = args[i];
                    } else {
                        console.error(`Invalid value for option --target: ${args[i]}`);
                        exit(1);
                    }
                }
            } else {
                console.error(`Missing value for option: ${args[i - 1]}`);
                exit(1);
            }
        } else if (options[args[i]].type === 'boolean') {
            configArg[args[i].substring(2)] = true;
        }
    }
}

const targetConfig = config.buildConfig[config.buildTarget]
if (configArg['get-nw-version']) {
    console.log(configArg.target);
    exit(0);
}

if (configArg['get-llvm-tag']) {
    console.log(targetConfig.llvm.tag);
    exit(0);
}

if (configArg['get-llvm-version']) {
    console.log(targetConfig.llvm.tag.match(/(\d+)\.\d+\.\d+/)[1]);
    exit(0);
}

const useMirror = configArg['use-mirror'] || config.useMirror
if (configArg['get-llvm-repo']) {
    console.log(targetConfig.llvm[useMirror ? 'mirror' : 'repo']);
    exit(0);
}

if (configArg['get-chromium-repo']) {
    console.log(targetConfig.chromium[useMirror ? 'mirror' : 'repo']);
    exit(0);
}

if (configArg['get-v8-repo']) {
    console.log(targetConfig.v8[useMirror ? 'mirror' : 'repo']);
    exit(0);
}

if (configArg['get-node-repo']) {
    console.log(targetConfig.node[useMirror ? 'mirror' : 'repo']);
    exit(0);
}

if (configArg['get-nw-repo']) {
    console.log(targetConfig.nw[useMirror ? 'mirror' : 'repo']);
    exit(0);
}

if (configArg['get-binutils-repo']) {
    console.log(targetConfig.binutils[useMirror ? 'mirror' : 'repo']);
    exit(0);
}

if (configArg['get-binutils-tag']) {
    console.log(targetConfig.binutils.tag);
    exit(0);
}