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

#include "utfconv.hpp"
#include <locale>
#include <regex>
#include <stdio.h>
#include <string>

using namespace std;

class Identifier {
    static bool isInAstralStartCodeSet(char32_t code);
    static bool isInAstralCodeSet(char32_t code);

public:
    static bool isIdentifierStart(char32_t code);
    static bool isIdentifierChar(char32_t code);
};

#endif /* identifier_hpp */
