#!/usr/bin/env node
const {join} = require('path')
const makeFirmware = require('.')
const conf = require('rc')('tiffy')

async function main() {
  const usage = new Error(`Usage:
  tiffy FILE1 [MORE FILES ...] --name NAME
    `)
  try {
    const files = conf._
    const name = conf.name || 'tifw'
    if (!files.length) throw isage
    await makeFirmware(name, files)
  } catch(err) {
    console.error(err.message)
    process.exit(1)
  }
}

main()

