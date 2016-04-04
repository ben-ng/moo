//
//  tokentype.cpp
//  moo
//
//  Created by Ben on 4/1/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#include "tokentype.hpp"

u32string keyword_to_esc_u32string(u32string kw)
{
    return kw.empty() ? U"null" : U"\"" + kw + U"\"";
}

u32string binop_to_u32string(int b)
{
    return b < 0 ? U"null" : UTFConv::int_to_u32string(b);
}

u32string bool_to_u32string(bool b)
{
    return b ? U"true" : U"false";
}

u32string TokenType::toJSON() const
{
    // Comments are just there to force clang-format to break lines
    return u32string(U"{\"label\":\"" + label + U"\"" + //
        U",\"keyword\":" + keyword_to_esc_u32string(keyword) + U"" + //
        U",\"binop\":" + binop_to_u32string(binop) + U"" + //
        U",\"beforeExpr\":" + bool_to_u32string(beforeExpr) + U"" + //
        U",\"startsExpr\":" + bool_to_u32string(startsExpr) + U"" + //
        U",\"isLoop\":" + bool_to_u32string(isLoop) + U"" + //
        U",\"isAssign\":" + bool_to_u32string(isAssign) + U"" + //
        U",\"prefix\":" + bool_to_u32string(prefix) + U"" + //
        U",\"postfix\":" + bool_to_u32string(postfix) + U"" + //
        U",\"updateContext\":null" + // Hardcoding for now, may remove later
        U"}");
}
