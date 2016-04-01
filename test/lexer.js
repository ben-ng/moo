'use strict'

/**
* The lexer is tested against Acorn's output
*/

const tap = require('tap')
const fs = require('fs')
const path = require('path')
const acorn = require('acorn')
const async = require('async')
const glob = require('glob')
const exec = require('child_process').exec

// Makes the output cleaner when the stack track is useless
const minimal = {at: null}

// const everythingDir = path.dirname(require.resolve('everything.js'))
// const everythingFixture = fileName => path.join(everythingDir, fileName)

function lexMoo (file, cb) {
  exec(['npm', 'run', 'lex', file, '--silent'].join(' ')
  , {maxBuffer: 128 * 1024*1024}
  , (err, _stdout, _stderr) => {
    if (err) {
      cb(err)
      return
    }

    const stderr = _stderr.toString().trim()

    if (stderr.length > 0) {
      cb(new Error(stderr))
      return
    }

    const stdout = _stdout.toString().trim()

    try {
      const tokens = JSON.parse(stdout)

      if (Array.isArray(tokens)) {
        cb(null, tokens)
      }
      else {
        cb(new Error(`Expected Array, got ${typeof tokens}: ${stdout}`))
      }
    }
    catch (e) {
      cb(new Error(`Moo could not parse: ${stdout}`))
    }
  })
}

function lexAcorn (file, cb) {
  fs.readFile(file, (err, buf) => {
    if (err) {
      cb(err)
      return
    }

    cb(null, [...acorn.tokenizer(buf.toString())])
  })
}

function lex (file, cb) {
  async.auto({
    acorn: async.apply(lexAcorn, file)
  , moo: async.apply(lexMoo, file)
  }, (err, results) => {
    cb(err, err == null ? results.acorn : null, err == null ? results.moo : null)
  })
}

function defineTest (file) {
  tap.test(`lexing ${path.basename(file)}`, t => {
    lex(file, (err, acornTokens, mooTokens) => {
      t.ifError(err, 'Should not error')

      t.equals(mooTokens.length, acornTokens.length, 'Token counts should match', minimal)

      let i = 0

      // Keep asserting until something fails
      while (i < acornTokens.length &&
        t.deepEquals(mooTokens[i], acornTokens[i], `Token ${i} should match`, minimal)) {
        i++
      }

      t.end()
    })
  })
}

// Tests must be defined synchronously!
glob.sync(path.join(__dirname, 'fixtures', '*')).forEach(file => {
  defineTest(file)
})
