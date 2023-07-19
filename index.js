const {join} = require('path')
const tifw = require('tifw')

module.exports = async function makeFirmware(name, files) {
  files.unshift(
    join(__dirname, 'tiffy.cpp')
  )
  return tifw(name, files)
}
