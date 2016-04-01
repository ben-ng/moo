//
//  lexer.cpp
//  moo
//
//  Created by Ben on 3/31/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//
//  Help from: http://stackoverflow.com/a/10504278
//  Unicode, you scary
//

#include "lexer.hpp"

Lexer::Lexer(string fp)
    : filePath{ fp }
{
    // open as a byte stream
    fileReadStream = wifstream(filePath, ios::binary);

    // apply BOM-sensitive UTF-16 facet
    fileReadStream.imbue(std::locale(fileReadStream.getloc(),
        new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));
}

void Lexer::skipSpace()
{
    for (wchar_t c; fileReadStream.get(c);) {
        ++pos;

        bool lastCharWasStar = false;

        switch (c) {
        case L' ': //   32 ' '  (blank space)
        case 160: //    160 ' '  (?)
        case L'\r': //  13 '\r' (carriage return)
        case L'\n': //  10 '\n' (new line)
        case 8232: //   8232 '?'  (line break)
        case 8233: //   8233 '?'  (line break)

        // Other weird unicode whitespace
        // TODO: Maybe move this close to the default? Could be faster.
        case 5760: // U+1680
        case 6158: //U+180E
        case 8239: //U+202F
        case 8287: //U+205F
        case 12288: //U+3000
        case 65279: //U+FEFF
            continue;

        // Possible comment
        case L'/': {

            switch (fileReadStream.peek()) {

            // Slurp up a line comment
            case L'/':
                while (fileReadStream.get(c)) {
                    ++pos;

                    if (c == L'\n' || c == L'\r' || c == L'\x2028' || c == L'\x2029') {
                        break;
                    }
                }
                continue;

            // Slurp up a block comment
            case L'\x002A': // 42 '*' (asterisk)
                while (fileReadStream.get(c)) {
                    ++pos;

                    if (lastCharWasStar && c == L'/') {
                        break;
                    }

                    lastCharWasStar = (c == L'*');
                }
                continue;

            // Well that didn't turn out to be a comment.
            // Back up, and exit the loop
            default:
                fileReadStream.unget();
                --pos;
                break;
            }
        }

        default:
            if ((c > 8 && c < 14) || (c > 8192 && c < 8202)) {
                continue;
            }
            break;
        }
    }
}

Token Lexer::nextToken()
{
    skipSpace();

    wchar_t c;

    // If EOF, return the EOF token (no arg constructor)
    if (!fileReadStream.get(c) || c == WEOF) {
        return Token();
    }

    return Token();
}
