# 新版本diff创建方法

## 1. 手动应用，解决冲突
```bash
cd path/to/target
git apply -p0 --reject nwjs-loongarch/patch/nw{old}/xxx.patch
```
有冲突的会产生 `.rej` 文件，使用编辑器，手动将改动应用到文件中

## 2. 暂存文件
```bash
git add .
```

## 2. 生成新的patch文件
```bash
git diff --cached --no-prefix > nwjs-loongarch/patch/nw{new}/xxx.patch
```