const fs = require('fs');
const path = require('path');

const args = process.argv.slice(2);
if (args.length < 1) {
  console.error('Usage: node patch-apply.js <nw-version>');
  process.exit(1);
}

const nwVersion = args[0];
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

  console.log(`Applying patch: ${patchItem.name}`);
  const execSync = require('child_process').execSync;
  try {
    const currentDir = path.resolve(rootDir, 'source-code/nwjs/src', patchItem.path)
    console.info(`Changing directory to: ${currentDir}`);
    execSync(`git restore .`, { stdio: 'inherit', cwd: currentDir });
    execSync(`git clean -fd`, { stdio: 'inherit', cwd: currentDir });
    execSync(`git apply -p0 ${patchPath}`, { stdio: 'inherit', cwd: currentDir });
    console.log(`Successfully applied patch: ${patchItem.name}`);
  } catch (error) {
    console.error(`Failed to apply patch: ${patchItem.name}`);
    process.exit(1);
  }
}