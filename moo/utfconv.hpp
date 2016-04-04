//
//  utfconv.hpp
//  moo
//
//  Created by Ben on 4/3/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#ifndef utfconv_hpp
#define utfconv_hpp

#include <cerrno>
#include <codecvt>
#include <fstream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class UTFConv {
public:
    static u32string long_to_u32string(const long& i)
    {
        wstring_convert<codecvt_utf8<char32_t>, char32_t> utf32conv;
        return utf32conv.from_bytes(to_string(i));
    }

    static u32string int_to_u32string(const int& i)
    {
        wstring_convert<codecvt_utf8<char32_t>, char32_t> utf32conv;
        return utf32conv.from_bytes(to_string(i));
    }

    static u32string string_to_u32string(const string& i)
    {
        wstring_convert<codecvt_utf8<char32_t>, char32_t> utf32conv;
        return utf32conv.from_bytes(i);
    }

    static u32string char32_t_to_u32string(const char32_t& i)
    {
        return u32string(1, i);
    }

    static u32string char32_t_vec_to_u32string(const vector<char32_t>& i)
    {
        return u32string(&i[0], i.size());
    }

    static string u32string_to_string(const u32string& i)
    {
        wstring_convert<codecvt_utf8<char32_t>, char32_t> utf32conv;
        return utf32conv.to_bytes(i);
    }
};

#endif /* utfconv_hpp */
