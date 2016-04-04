//
//  parseerror.hpp
//  moo
//
//  Created by Ben on 4/3/16.
//  Copyright © 2016 Ben Ng. All rights reserved.
//

#ifndef parseerror_hpp
#define parseerror_hpp

#include <stdexcept>
#include <string>

using namespace std;

class ParseError : runtime_error {
public:
    ParseError(string msg)
        : runtime_error(msg){};
};

#endif /* parseerror_hpp */
