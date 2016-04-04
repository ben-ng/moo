//
//  tokentype.hpp
//  moo
//
//  Created by Ben on 4/1/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#ifndef tokentype_hpp
#define tokentype_hpp

#include "utfconv.hpp"
#include <string>

using namespace std;

struct TokenType {
    const u32string label;
    const u32string keyword;
    const int binop; // -1 if not a binop, otherwise the precedence of the operator
    const bool beforeExpr;
    const bool startsExpr;
    const bool isLoop;
    const bool isAssign;
    const bool prefix;
    const bool postfix;

    u32string toJSON() const;
};

// Generated with bin/generate-tokentype-structs.js
static const TokenType TokenTypeNum{
    .label = U"num",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeRegExp{
    .label = U"regexp",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeString{
    .label = U"string",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeName{
    .label = U"name",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeEOF{
    .label = U"eof",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBracketL{
    .label = U"[",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBracketR{
    .label = U"]",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBraceL{
    .label = U"{",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBraceR{
    .label = U"}",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeParenL{
    .label = U"(",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeParenR{
    .label = U")",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeComma{
    .label = U",",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeSemi{
    .label = U";",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeColon{
    .label = U":",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeDot{
    .label = U".",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeQuestion{
    .label = U"?",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeArrow{
    .label = U"=>",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeTemplate{
    .label = U"template",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeEllipsis{
    .label = U"...",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBackquote{
    .label = U"`",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeDollarBraceL{
    .label = U"${",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeEq{
    .label = U"=",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = true,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeAssign{
    .label = U"_=",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = true,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeIncDec{
    .label = U"++/--",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = true,
    .postfix = true
};

static const TokenType TokenTypePrefix{
    .label = U"prefix",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = true,
    .postfix = false
};

static const TokenType TokenTypeLogicalOr{
    .label = U"||",
    .keyword = U"",
    .binop = 1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeLogicalAnd{
    .label = U"&&",
    .keyword = U"",
    .binop = 2,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBitwiseOr{
    .label = U"|",
    .keyword = U"",
    .binop = 3,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBitwiseXor{
    .label = U"^",
    .keyword = U"",
    .binop = 4,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBitwiseAnd{
    .label = U"&",
    .keyword = U"",
    .binop = 5,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeEquality{
    .label = U"==/!=",
    .keyword = U"",
    .binop = 6,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeRelational{
    .label = U"</>",
    .keyword = U"",
    .binop = 7,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBitShift{
    .label = U"<</>>",
    .keyword = U"",
    .binop = 8,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypePlusMin{
    .label = U"+/-",
    .keyword = U"",
    .binop = 9,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = true,
    .postfix = false
};

static const TokenType TokenTypeModulo{
    .label = U"%",
    .keyword = U"",
    .binop = 10,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeStar{
    .label = U"*",
    .keyword = U"",
    .binop = 10,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeSlash{
    .label = U"/",
    .keyword = U"",
    .binop = 10,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeStarStar{
    .label = U"**",
    .keyword = U"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBreakKeyword{
    .label = U"break",
    .keyword = U"break",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeCaseKeyword{
    .label = U"case",
    .keyword = U"case",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeCatchKeyword{
    .label = U"catch",
    .keyword = U"catch",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeContinueKeyword{
    .label = U"continue",
    .keyword = U"continue",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeDebuggerKeyword{
    .label = U"debugger",
    .keyword = U"debugger",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeDefaultKeyword{
    .label = U"default",
    .keyword = U"default",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeDoKeyword{
    .label = U"do",
    .keyword = U"do",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = true,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeElseKeyword{
    .label = U"else",
    .keyword = U"else",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeFinallyKeyword{
    .label = U"finally",
    .keyword = U"finally",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeForKeyword{
    .label = U"for",
    .keyword = U"for",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = true,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeFunctionKeyword{
    .label = U"function",
    .keyword = U"function",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeIfKeyword{
    .label = U"if",
    .keyword = U"if",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeReturnKeyword{
    .label = U"return",
    .keyword = U"return",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeSwitchKeyword{
    .label = U"switch",
    .keyword = U"switch",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeThrowKeyword{
    .label = U"throw",
    .keyword = U"throw",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeTryKeyword{
    .label = U"try",
    .keyword = U"try",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeVarKeyword{
    .label = U"var",
    .keyword = U"var",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeConstKeyword{
    .label = U"const",
    .keyword = U"const",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeWhileKeyword{
    .label = U"while",
    .keyword = U"while",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = true,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeWithKeyword{
    .label = U"with",
    .keyword = U"with",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeNewKeyword{
    .label = U"new",
    .keyword = U"new",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeThisKeyword{
    .label = U"this",
    .keyword = U"this",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeSuperKeyword{
    .label = U"super",
    .keyword = U"super",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeClassKeyword{
    .label = U"class",
    .keyword = U"class",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeExtendsKeyword{
    .label = U"extends",
    .keyword = U"extends",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeExportKeyword{
    .label = U"export",
    .keyword = U"export",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeImportKeyword{
    .label = U"import",
    .keyword = U"import",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeNullKeyword{
    .label = U"null",
    .keyword = U"null",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeTrueKeyword{
    .label = U"true",
    .keyword = U"true",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeFalseKeyword{
    .label = U"false",
    .keyword = U"false",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeInKeyword{
    .label = U"in",
    .keyword = U"in",
    .binop = 7,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeInstanceofKeyword{
    .label = U"instanceof",
    .keyword = U"instanceof",
    .binop = 7,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeTypeofKeyword{
    .label = U"typeof",
    .keyword = U"typeof",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = true,
    .postfix = false
};

static const TokenType TokenTypeVoidKeyword{
    .label = U"void",
    .keyword = U"void",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = true,
    .postfix = false
};

static const TokenType TokenTypeDeleteKeyword{
    .label = U"delete",
    .keyword = U"delete",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = true,
    .postfix = false
};

#endif /* tokentype_hpp */
