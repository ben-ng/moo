//
//  token.cpp
//  moo
//
//  Created by Ben on 3/31/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#include "token.hpp"

u32string Token::toJSON() const
{
    // Comments are just there to force clang-format to break lines
    return u32string(U"{\"end\":" + UTFConv::long_to_u32string(end) + //
        U",\"start\":" + UTFConv::long_to_u32string(start) + //
        U",\"type\":" + type.toJSON() + //
        U"}");
}
