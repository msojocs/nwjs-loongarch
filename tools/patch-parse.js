const suffix2comment = {
  h: '// loongarch64',
  cc: '// loongarch64',
  gn: '# loongarch64'
}
    comment: '',
      const suffix = data.name.split('.').reverse()[0]
      if (suffix2comment[suffix]) {
        data.comment = suffix2comment[suffix]
      }
      current.after += line.slice(1) + `${data.comment}\n`;
      current.after += line.slice(1) + `${data.comment}\n`;