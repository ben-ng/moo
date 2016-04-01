//
//  tokentype.cpp
//  moo
//
//  Created by Ben on 4/1/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#include "tokentype.hpp"

wstring keyword_to_esc_wstring(wstring kw)
{
    return kw.empty() ? L"null" : L"\"" + kw + L"\"";
}

wstring binop_to_wstring(int b)
{
    return b < 0 ? L"null" : to_wstring(b);
}

wstring bool_to_wstring(bool b)
{
    return b ? L"true" : L"false";
}

wstring TokenType::toJSON() const
{
    // Comments are just there to force clang-format to break lines
    return wstring(L"{\"label\":\"" + label + L"\"" + //
        L",\"keyword\":" + keyword_to_esc_wstring(keyword) + L"" + //
        L",\"binop\":" + binop_to_wstring(binop) + L"" + //
        L",\"beforeExpr\":" + bool_to_wstring(beforeExpr) + L"" + //
        L",\"startsExpr\":" + bool_to_wstring(startsExpr) + L"" + //
        L",\"isLoop\":" + bool_to_wstring(isLoop) + L"" + //
        L",\"isAssign\":" + bool_to_wstring(isAssign) + L"" + //
        L",\"prefix\":" + bool_to_wstring(prefix) + L"" + //
        L",\"postfix\":" + bool_to_wstring(postfix) + L"" + //
        L",\"updateContext\":null" + // Hardcoding for now, may remove later
        L"}");
}
