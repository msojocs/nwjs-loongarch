const fs = require('fs');
const path = require('path');
const { execSync } = require('child_process');

const args = process.argv.slice(2);
if (args.length < 1) {
  console.error('Usage: node patch-apply.js <nw-version>');
  process.exit(1);
}

const nwVersion = args[0];
const action = args[1] || 'apply';
const rootDir = path.resolve(__dirname, '..');
const patchDir = path.join(rootDir, 'patch', nwVersion);

if (!fs.existsSync(patchDir)) {
  console.log(`No patches found for NW.js version ${nwVersion}.`);
  process.exit(0);
}

const patchConfig = require(path.join(patchDir, 'config.json')).filter(e => !e.disabled);

for (const patchItem of patchConfig) {
  const patchPath = path.join(patchDir, `${patchItem.name}.patch`);
  if (!fs.existsSync(patchPath)) {
    console.warn(`Patch file ${patchItem.name}.patch not found, skipping.`);
    continue;
  }
  const currentDir = path.resolve(rootDir, 'source-code/nwjs/src', patchItem.path)

  if (action === 'stage') {
    console.log(`Staging patch: ${patchItem.name}`);
    execSync(`git add .`, { stdio: 'inherit', cwd: currentDir });
  } else if (action === 'apply') {
    console.log(`Applying patch: ${patchItem.name}`);
    try {
      console.info(`Changing directory to: ${currentDir}`);
      // TODO: 检查 -> 撤销已应用的补丁（工作区）
      execSync(`git apply -p0 ${patchPath}`, { stdio: 'inherit', cwd: currentDir });
      console.log(`Successfully applied patch: ${patchItem.name}`);
    } catch (error) {
      console.error(`Failed to apply patch: ${patchItem.name}`);
      console.error(`git apply -p0 --reject ${patchPath}`);
      console.error(`git diff --cached --no-prefix > ${patchPath}`);
      process.exit(1);
    }
  }
}