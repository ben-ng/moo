//
//  main.cpp
//  moo
//
//  Created by Ben on 3/31/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#include "lexer.hpp"
#include "token.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

int main(int argc, const char* argv[])
{
    Lexer lex(argv[1]);
    bool isFirst = true;

    wcout << L'[';

    while (true) {
        auto t = lex.nextToken();

        if (!isFirst) {
            wcout << L',';
        }
        else {
            isFirst = true;
        }

        wcout << t.toJSON();

        if (t.isEOF()) {
            break;
        }
    }

    wcout << L']';

    return 0;
}
