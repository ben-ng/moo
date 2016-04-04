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
#include <locale>
#include <string>

using namespace std;

class Token {
    const u32string value{ U"" };
    const TokenType& type;
    const size_t start{ 0 };
    const size_t end{ 0 };
    const bool _isEOF{ false };

public:
    Token()
        : type{ TokenTypeEOF }
        , _isEOF{ true } {};

    Token(TokenType _type, size_t _start, size_t _end)
        : type{ _type }
        , start{ _start }
        , end{ _end } {};

    Token(u32string _value, TokenType _type, size_t _start, size_t _end)
        : value{ _value }
        , type{ _type }
        , start{ _start }
        , end{ _end } {};

    bool isEOF() { return _isEOF; };

    u32string toJSON() const;
};

#endif /* token_hpp */
