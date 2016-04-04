//
//  lexer.cpp
//  moo
//
//  Created by Ben on 3/31/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#include "lexer.hpp"

Lexer::Lexer(string fp)
    : filePath{ fp }
{
    // open as a byte stream
    ifstream fileReadStream(filePath, ios::in | ios::binary);
    //
    //    // apply BOM-sensitive UTF-8 facet
    //    fileReadStream.imbue(locale(fileReadStream.getloc(),
    //        new codecvt_utf8<char32_t, 0x10ffff, std::consume_header>));

    // Read the entire file into input
    if (fileReadStream) {
        ostringstream ss;
        ss << fileReadStream.rdbuf();
        fileReadStream.close();
        input = UTFConv::string_to_u32string(ss.str());
        inputLength = input.size();
        // Okay, I've convinced myself that this actually works.
        // cout << UTFConv::u32string_to_string(input) << "is " << to_string(inputLength) << " long";
    }
    else {
        throw(errno);
    }

    pos = 0;
    curLine = 0;
}

void Lexer::skipSpace()
{
    while (pos < inputLength) {
        char32_t c = input[pos];
        ++pos;

        bool lastCharWasStar = false;

        switch (c) {

        case U' ': //   32 ' '  (blank space)
        case 160: //    160 ' '  (?)
        case U'\r': //  13 '\r' (carriage return)
        case U'\n': //  10 '\n' (new line)
        case 8232: //   8232 '?'  (line break)
        case 8233: //   8233 '?'  (line break)

        // Other weird unicode whitespace
        // TODO: Maybe move this close to the default? Could be faster.
        // TODO: I think I should emit whitespace tokens...
        // might need to differentiate them with a "isLineTerminator" flag
        // in order to handle ASI.
        case 5760: // U+1680
        case 6158: //U+180E
        case 8239: //U+202F
        case 8287: //U+205F
        case 12288: //U+3000
        case 65279: //U+FEFF
            continue;

        // Possible comment
        case U'/': {

            // EOF, this is not whitespace!
            if (pos + 1 >= inputLength) {
                pos--;
                return;
            }

            switch (input[pos + 1]) {

            // Slurp up a line comment
            case U'/':
                while (pos < inputLength) {
                    c = input[pos];

                    if (c == U'\n' || c == U'\r' || c == U'\x2028' || c == U'\x2029') {
                        break;
                    }
                    else {
                        ++pos;
                    }
                }
                continue;

            // Slurp up a block comment
            case U'\x002A': // 42 '*' (asterisk)
                while (pos < inputLength) {
                    c = input[pos];

                    if (lastCharWasStar && c == U'/') {
                        break;
                    }

                    lastCharWasStar = (c == U'*');
                    ++pos;
                }
                continue;

            // Well that didn't turn out to be a comment.
            // Back up, and exit the loop
            default:
                --pos;
                break;
            }
        }

        default:
            if ((c > 8 && c < 14) || (c > 8192 && c < 8202)) {
                continue;
            }

            // We've skipped all the whitespace that we can
            --pos;
            return;
        }
    }
}

Token Lexer::nextToken()
{
    skipSpace();

    // If EOF, return the EOF token (no arg constructor)
    if (pos >= inputLength) {
        return Token();
    }

    char32_t c = input[pos];

    // Identifier or keyword. The \ might be a \uXXXX sequence.
    if (Identifier::isIdentifierStart(c) || c == U'\\') {
        cout << "HIT" << endl;
    }

    // Otherwise, it's some other type of token
    switch (c) {
    case U';':
        pos += 1;
        return Token(TokenTypeSemi, pos - 1, pos);

    case U'.':
        if (pos + 1 >= inputLength) {
            return Token(TokenTypeDot, pos, pos + 1);
        }

        char32_t c1Ahead = input[pos + 1];

        // Need to check if it is followed by a digit (number) or another two dots (ellipsis)

        // Next char is a digit
        if (c1Ahead >= 48 && c1Ahead <= 57) {
            vector<char32_t> digits{ c };

            size_t start_pos = pos;

            pos += 1;

            // Read until EOF
            while (pos < inputLength) {
                // Accept digits
                if (c >= 48 && c <= 57) {
                    digits.push_back(c);
                    pos += 1;
                }
                // Reject anything else
                else {
                    pos -= 1;
                    break;
                }
            }

            return Token(UTFConv::char32_t_vec_to_u32string(digits), TokenTypeNum, start_pos, pos);
        }
        // Next char is another dot
        else if (c1Ahead == U'.') {

            if (pos + 2 <= inputLength && input[pos + 2] == U'.') {
                Token t(TokenTypeEllipsis, pos, pos + 3);
                pos += 3;
                return t;
            }

            throw ParseError("Expected a third '.' to complete the ellipsis at " + to_string(pos + 2));
        }
        // Anything else? Okay, it's really a dot.
        else {
            pos += 1;
            return Token(TokenTypeDot, pos, pos + 1);
        }
    }

    u32string ws({ c });
    string str(ws.begin(), ws.end());
    throw ParseError("Character '" + str + "' is not a prefix of any known token");
}
