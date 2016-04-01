//
//  token.cpp
//  moo
//
//  Created by Ben on 3/31/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#include "token.hpp"

wstring Token::toJSON() const
{
    // Comments are just there to force clang-format to break lines
    return wstring(L"{\"end\":" + to_wstring(end) + //
        L",\"start\":" + to_wstring(start) + //
        L",\"type\":" + type.toJSON() + //
        L"}");
}
