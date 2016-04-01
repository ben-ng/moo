//
//  identifier.hpp
//  moo
//
//  Created by Ben on 3/31/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//
// Ported from Acorn.js
//

#ifndef identifier_hpp
#define identifier_hpp

#include <regex>
#include <stdio.h>
#include <string>

using namespace std;

class Identifier {
    static bool isInAstralStartCodeSet(wchar_t code);
    static bool isInAstralCodeSet(wchar_t code);

public:
    static bool isIdentifierStart(wchar_t code);
    static bool isIdentifierChar(wchar_t code);
};

#endif /* identifier_hpp */
