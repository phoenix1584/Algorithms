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
#include <vector>
#include <algorithm>

class ResultStore{
    private:
        int m_min;
        int m_max;
    public:
        ResultStore(int min_init, int max_init)
            :m_min(min_init),
             m_max(max_init)
    {}
        void operator()(int i){
            if( i > m_max)
                m_max = i;
            else if( i < m_min)
                m_min = i;
        }

        friend std::ostream& operator<<(std::ostream& os, ResultStore& rs){
            os << "Result => Min : " << rs.m_min << ", Max : " << rs.m_max << "\n";
            return os;
        }
};

int main(){
    std::vector<int> vec = {1000, 11, 445, 1, 330, 3000};
    if(vec.size() > 1){
        ResultStore rs(vec[0],vec[1]);
        for (const auto& x : vec){
            rs(x);
        }
        std::cout << rs ;
    }
    return 0;
}

