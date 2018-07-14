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

// Objective:
// 1. Accept input as pair of numbers
// 2. Store them in a vector
// 3. Pass the vector as divided sub vectors to a recursive call

#include <iostream>
#include <vector>
#include <sstream>
#define DEBUG 0
class Data{
    private:
        int m_f1;
        int m_f2;
    public:
        Data(const decltype(m_f1) f1, const decltype(m_f1) f2)
            :m_f1(f1), m_f2(f2)
        {}

        friend std::ostream& operator<<(std::ostream& os, const Data& d){
            os << "[" << d.m_f1 << "," << d.m_f2 << "]" ;  
            return os;
        }

        void Multiply(int factor){
            m_f1 *= factor;
            m_f2 *= factor;
        }
};

// Range class that simplifies the range passing and 
// coule be extended to perform boundary condition checks
class IndexRange{
    public:
        const unsigned int m_lower_bound;
        const unsigned int m_upper_bound;
        const unsigned int m_size = m_upper_bound - m_lower_bound;
        IndexRange(const auto lb, const auto ub)
            : m_lower_bound(lb)
              ,m_upper_bound(ub)
    {}
        friend std::ostream& operator<<(std::ostream& os, const IndexRange& r){
            os << "[ lbound : " << r.m_lower_bound << ",ubound : " << r.m_upper_bound << "] => size : " << r.m_size ;  
            return os;
        }

};

auto pf = [](){ std::cout << "-------------------\n"; };

void RangeTester(IndexRange r){
    std::cout << r << "\n";
}

void RecFunc(std::vector<Data>& data, int start_index, int size){
    auto itr = data.begin() + start_index;
    RangeTester(IndexRange(start_index,start_index+size));
    if(size < 2){
        itr->Multiply(3);
        return;
    }
    auto mid = size / 2;
    RecFunc(data,start_index,mid);
    RecFunc(data,start_index + mid,size-mid);
#if DEBUG
    pf();
    std::cout << "mid : " << mid << "\n";
    for(auto i = 0 ; i < size ; ++i, ++itr){
        std::cout <<  *itr << ",";
    }
    std::cout << "\n";
#endif
}

int main(){
    std::vector<Data> data_collection;

    int N,f1,f2;
    std::string input;
    std::cout << "Enter the total number of pairs.\n";
    std::cin >> N;
    std::cout << "Enter the pairs (space separated numbers.\n";
    for(auto i = 0 ; i < N ; ++i){
        std::cin >> f1 >> f2;
        data_collection.emplace_back(f1,f2);
    }
    RecFunc(data_collection,0,data_collection.size());
    for (const auto& x : data_collection){
        std::cout << x << ",";
    }
    std::cout << "\n";
}
