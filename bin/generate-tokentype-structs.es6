import {types} from 'acorn/src/tokentype'

const normalizeSuffix = tyName => {
  const isKeyword = tyName.charAt(0) === '_'

  tyName = isKeyword ? tyName.substr(1) : tyName

  const capitalized = tyName.charAt(0).toUpperCase() + tyName.substr(1).toLowerCase()

  return capitalized.replace('Regexp', 'RegExp')
  .replace('Eof', 'EOF')
  .replace('Bracketl', 'BracketL')
  .replace('Bracketr', 'BracketR')
  .replace('Bracel', 'BraceL')
  .replace('Bracer', 'BraceR')
  .replace('Parenl', 'ParenL')
  .replace('Parenr', 'ParenR')
  .replace('Dollarbracel', 'DollarBraceL')
  .replace('Incdec', 'IncDec')
  .replace('Logicalor', 'LogicalOr')
  .replace('Logicaland', 'LogicalAnd')
  .replace('Bitwiseor', 'BitwiseOr')
  .replace('Bitwisexor', 'BitwiseXor')
  .replace('Bitwiseand', 'BitwiseAnd')
  .replace('Bitshift', 'BitShift')
  .replace('Plusmin', 'PlusMin')
  .replace('Starstar', 'StarStar') + (isKeyword ? 'Keyword' : '')
}

for (let tyName in types) {

  let ty = types[tyName]

  console.log(`
static const TokenType TokenType${normalizeSuffix(tyName)}{
    .label = L"${ty.label}",
    .keyword = L"${ty.keyword == null ? '' : ty.keyword}",
    .binop = ${ty.binop == null ? -1 : ty.binop},
    .beforeExpr = ${ty.beforeExpr},
    .startsExpr = ${ty.startsExpr},
    .isLoop = ${ty.isLoop},
    .isAssign = ${ty.isAssign},
    .prefix = ${ty.prefix},
    .postfix = ${ty.postfix}
};\n`)

}
