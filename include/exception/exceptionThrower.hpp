//
//  exceptionThrower.hpp
//  exception
//
// The MIT License (MIT)
//
// Copyright (c) 2019 André Pereira Henriques
// aphenriques (at) outlook (dot) com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef exception_exceptionThrower_hpp
#define exception_exceptionThrower_hpp

#include <sstream>
#include "Exception.hpp"

namespace exception::exceptionThrower {
    // compiler attributes optimized for unlikely exception
    template<typename E = exception::RuntimeException, typename ...A>
    [[using gnu : noinline, cold]] [[noreturn]] void throwException(
        const char *fileName,
        int lineNumber,
        const char *functionName,
        const A &...messages
    );

    //--

    template<typename E, typename ...A>
    void throwException(const char *fileName, int lineNumber, const char *functionName, const A &...messages) {
        std::ostringstream ostringstream;
        (ostringstream << ... << messages);
        throw E(fileName, lineNumber, functionName, ostringstream.str());
    }
}

#endif

