/*
 * Copyright (c) 2018
 * Author: phoenix1584
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <iostream>

unsigned int fibonacci_generator(unsigned int x){
    return ( x < 2) ? x : (fibonacci_generator(x-1) + fibonacci_generator(x-2)) ;
}

constexpr unsigned int fibonacci_compile_time(unsigned int x){
    return ( x < 2) ? x : (fibonacci_compile_time(x-1) + fibonacci_compile_time(x-2)) ;
}

template <int T>
class fibonacci_template{
    public:
        static constexpr unsigned int m_value = fibonacci_template<T-1>::m_value + fibonacci_template<T-2>::m_value; 
};

template <>
class fibonacci_template<0>{
    public:
        static constexpr unsigned int m_value = 0;
};

template <>
class fibonacci_template<1>{
    public:
        static constexpr unsigned int m_value = 1;
};

int main(){
    std::cout << "Runtime   : " << fibonacci_generator(32) << "\n";
    std::cout << "Constexpr : " << fibonacci_compile_time(32) << "\n";
    std::cout << "Template  : " << fibonacci_template<32>::m_value << "\n";
    return 0;
}
