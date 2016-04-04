//
//  lexer.hpp
//  moo
//
//  Created by Ben on 3/31/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#ifndef lexer_hpp
#define lexer_hpp

#include "identifier.hpp"
#include "parseerror.hpp"
#include "token.hpp"
#include "utfconv.hpp"
#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

using namespace std;

class Lexer {
    u32string input;
    size_t inputLength;
    size_t pos;
    size_t curLine;

    string filePath;

    void skipSpace();
    Token readToken();
    Token readWord();
    Token getTokenFromChar();

public:
    Lexer(string fp);
    Token nextToken();
};

#endif /* lexer_hpp */
