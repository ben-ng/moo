// Which Unicode version should be used?
var version = '8.0.0'

var start = require('unicode-' + version + '/properties/ID_Start/code-points')
    .filter(function (ch) { return ch > 127 })
var last = -1
var cont = [0x200c, 0x200d].concat(require('unicode-' + version + '/properties/ID_Continue/code-points')
    .filter(function (ch) { return ch > 127 && search(start, ch, last + 1) === -1 }))

function search (arr, ch, starting) {
  for (var i = starting; arr[i] <= ch && i < arr.length; last = i++)
    if (arr[i] === ch)
      return i
  return -1
}

function pad (str, width) {
  while (str.length < width) str = '0' + str
  return str
}

function esc (code) {
  var hex = code.toString(16)
  if (hex.length <= 2) return '\\x' + pad(hex, 2)
  else return '\\u' + pad(hex, 4)
}

function generate (chars) {
  var astral = [], re = ''
  for (var i = 0, at = 0x10000; i < chars.length; i++) {
    var frm = chars[i], to = frm
    while (i < chars.length - 1 && chars[i + 1] === to + 1) {
      i++
      to++
    }
    if (to <= 0xffff) {
      if (frm === to) re += esc(frm)
      else if (frm + 1 === to) re += esc(frm) + esc(to)
      else re += esc(frm) + '-' + esc(to)
    } else {
      astral.push(frm - at, to - frm)
      at = to
    }
  }
  return {nonASCII: re, astral: astral}
}

var startData = generate(start), contData = generate(cont)

console.log('wregex nonASCIIidentifierStartChars(L"' + startData.nonASCII + '");')
console.log('wregex nonASCIIidentifierChars(L"' + contData.nonASCII + '");')
var startDataAstral = JSON.stringify(startData.astral)
console.log('wchar_t astralIdentifierStartCodes[] = {' + startDataAstral.substr(1, startDataAstral.length-2) + '};')
var contDataAstral = JSON.stringify(contData.astral)
console.log('wchar_t astralIdentifierCodes[] = {' + contDataAstral.substr(1, contDataAstral.length-2) + '};')
