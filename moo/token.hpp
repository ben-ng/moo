//
//  token.hpp
//  moo
//
//  Created by Ben on 3/31/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#ifndef token_hpp
#define token_hpp

#include "tokentype.hpp"
#include <string>

using namespace std;

class Token {
    wstring value{ L"" };
    TokenType type;
    int start{ -1 };
    int end{ -1 };
    bool _isEOF{ false };

public:
    Token()
        : _isEOF{ true }
        , type{ TokenTypeEOF } {};

    Token(wstring _value, TokenType _type, int _start, int _end)
        : value{ _value }
        , type{ _type }
        , start{ _start }
        , end{ _end } {};

    bool isEOF() { return _isEOF; };

    wstring toJSON();
};

#endif /* token_hpp */
