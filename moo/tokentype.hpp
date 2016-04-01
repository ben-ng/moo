//
//  tokentype.hpp
//  moo
//
//  Created by Ben on 4/1/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#ifndef tokentype_hpp
#define tokentype_hpp

#include <string>

using namespace std;

struct TokenType {
    const wstring label;
    const wstring keyword;
    const int binop; // -1 if not a binop, otherwise the precedence of the operator
    const bool beforeExpr;
    const bool startsExpr;
    const bool isLoop;
    const bool isAssign;
    const bool prefix;
    const bool postfix;

    wstring toJSON() const;
};

// Generated with bin/generate-tokentype-structs.js
static const TokenType TokenTypeNum{
    .label = L"num",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeRegExp{
    .label = L"regexp",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeString{
    .label = L"string",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeName{
    .label = L"name",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeEOF{
    .label = L"eof",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBracketL{
    .label = L"[",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBracketR{
    .label = L"]",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBraceL{
    .label = L"{",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBraceR{
    .label = L"}",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeParenL{
    .label = L"(",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeParenR{
    .label = L")",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeComma{
    .label = L",",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeSemi{
    .label = L";",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeColon{
    .label = L":",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeDot{
    .label = L".",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeQuestion{
    .label = L"?",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeArrow{
    .label = L"=>",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeTemplate{
    .label = L"template",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeEllipsis{
    .label = L"...",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBackquote{
    .label = L"`",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeDollarBraceL{
    .label = L"${",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeEq{
    .label = L"=",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = true,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeAssign{
    .label = L"_=",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = true,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeIncDec{
    .label = L"++/--",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = true,
    .postfix = true
};

static const TokenType TokenTypePrefix{
    .label = L"prefix",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = true,
    .postfix = false
};

static const TokenType TokenTypeLogicalOr{
    .label = L"||",
    .keyword = L"",
    .binop = 1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeLogicalAnd{
    .label = L"&&",
    .keyword = L"",
    .binop = 2,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBitwiseOr{
    .label = L"|",
    .keyword = L"",
    .binop = 3,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBitwiseXor{
    .label = L"^",
    .keyword = L"",
    .binop = 4,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBitwiseAnd{
    .label = L"&",
    .keyword = L"",
    .binop = 5,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeEquality{
    .label = L"==/!=",
    .keyword = L"",
    .binop = 6,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeRelational{
    .label = L"</>",
    .keyword = L"",
    .binop = 7,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBitShift{
    .label = L"<</>>",
    .keyword = L"",
    .binop = 8,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypePlusMin{
    .label = L"+/-",
    .keyword = L"",
    .binop = 9,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = true,
    .postfix = false
};

static const TokenType TokenTypeModulo{
    .label = L"%",
    .keyword = L"",
    .binop = 10,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeStar{
    .label = L"*",
    .keyword = L"",
    .binop = 10,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeSlash{
    .label = L"/",
    .keyword = L"",
    .binop = 10,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeStarStar{
    .label = L"**",
    .keyword = L"",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeBreakKeyword{
    .label = L"break",
    .keyword = L"break",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeCaseKeyword{
    .label = L"case",
    .keyword = L"case",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeCatchKeyword{
    .label = L"catch",
    .keyword = L"catch",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeContinueKeyword{
    .label = L"continue",
    .keyword = L"continue",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeDebuggerKeyword{
    .label = L"debugger",
    .keyword = L"debugger",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeDefaultKeyword{
    .label = L"default",
    .keyword = L"default",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeDoKeyword{
    .label = L"do",
    .keyword = L"do",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = true,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeElseKeyword{
    .label = L"else",
    .keyword = L"else",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeFinallyKeyword{
    .label = L"finally",
    .keyword = L"finally",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeForKeyword{
    .label = L"for",
    .keyword = L"for",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = true,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeFunctionKeyword{
    .label = L"function",
    .keyword = L"function",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeIfKeyword{
    .label = L"if",
    .keyword = L"if",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeReturnKeyword{
    .label = L"return",
    .keyword = L"return",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeSwitchKeyword{
    .label = L"switch",
    .keyword = L"switch",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeThrowKeyword{
    .label = L"throw",
    .keyword = L"throw",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeTryKeyword{
    .label = L"try",
    .keyword = L"try",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeVarKeyword{
    .label = L"var",
    .keyword = L"var",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeConstKeyword{
    .label = L"const",
    .keyword = L"const",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeWhileKeyword{
    .label = L"while",
    .keyword = L"while",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = true,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeWithKeyword{
    .label = L"with",
    .keyword = L"with",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeNewKeyword{
    .label = L"new",
    .keyword = L"new",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeThisKeyword{
    .label = L"this",
    .keyword = L"this",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeSuperKeyword{
    .label = L"super",
    .keyword = L"super",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeClassKeyword{
    .label = L"class",
    .keyword = L"class",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeExtendsKeyword{
    .label = L"extends",
    .keyword = L"extends",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeExportKeyword{
    .label = L"export",
    .keyword = L"export",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeImportKeyword{
    .label = L"import",
    .keyword = L"import",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeNullKeyword{
    .label = L"null",
    .keyword = L"null",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeTrueKeyword{
    .label = L"true",
    .keyword = L"true",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeFalseKeyword{
    .label = L"false",
    .keyword = L"false",
    .binop = -1,
    .beforeExpr = false,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeInKeyword{
    .label = L"in",
    .keyword = L"in",
    .binop = 7,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeInstanceofKeyword{
    .label = L"instanceof",
    .keyword = L"instanceof",
    .binop = 7,
    .beforeExpr = true,
    .startsExpr = false,
    .isLoop = false,
    .isAssign = false,
    .prefix = false,
    .postfix = false
};

static const TokenType TokenTypeTypeofKeyword{
    .label = L"typeof",
    .keyword = L"typeof",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = true,
    .postfix = false
};

static const TokenType TokenTypeVoidKeyword{
    .label = L"void",
    .keyword = L"void",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = true,
    .postfix = false
};

static const TokenType TokenTypeDeleteKeyword{
    .label = L"delete",
    .keyword = L"delete",
    .binop = -1,
    .beforeExpr = true,
    .startsExpr = true,
    .isLoop = false,
    .isAssign = false,
    .prefix = true,
    .postfix = false
};

#endif /* tokentype_hpp */
