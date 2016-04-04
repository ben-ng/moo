//
//  main.cpp
//  moo
//
//  Created by Ben on 3/31/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#include "lexer.hpp"
#include "token.hpp"
#include "utfconv.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

int main(int argc, const char* argv[])
{
    if (argc < 2) {
        throw runtime_error("Expected at least one argument");
    }

    Lexer lex(argv[1]);
    bool isFirst = true;

    cout << '[';

    while (true) {
        auto t = lex.nextToken();

        if (!isFirst) {
            cout << ',';
        }
        else {
            isFirst = true;
        }

        cout << UTFConv::u32string_to_string(t.toJSON());

        if (t.isEOF()) {
            break;
        }
    }

    cout << ']';

    return 0;
}
