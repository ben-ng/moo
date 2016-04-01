//
//  lexer.hpp
//  moo
//
//  Created by Ben on 3/31/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#ifndef lexer_hpp
#define lexer_hpp

#include "token.hpp"
#include <codecvt>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>

using namespace std;

class Lexer {
    int pos{ -1 };
    string filePath;
    wifstream fileReadStream;

    void skipSpace();
    Token readToken();
    Token readWord();
    Token getTokenFromChar();

public:
    Lexer(string fp);
    Token nextToken();
};

#endif /* lexer_hpp */
