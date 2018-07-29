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

// Partition an array with 3 distinct values a.k.a Dutch Flag problem.
// refs : https://en.wikipedia.org/wiki/Dutch_national_flag_problem

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void TriPart(std::vector<int>& vec,const int mid){
    unsigned int lbound = 0;
    unsigned int ubound = vec.size() - 1;
    unsigned int curr =0;
    while (curr <= ubound){
        if(vec[curr] < mid){
            std::swap(vec[curr],vec[lbound]);
            lbound++;
            curr++;
        }else if(vec[curr] > mid){
            std::swap(vec[curr],vec[ubound]);
            ubound--;
        }else{
            curr++;
        }
    }
}

int main(){
    std::srand(std::time(nullptr));
    std::vector<int> v;
    for(auto x = 0 ; x < 20 ; ++x){
        v.emplace_back(rand()%3);
    }
    auto print_vector = [&](std::string msg){ 
        std::cout << msg << "\n";
        for(const auto x : v){
            std::cout << x << ",";
        }
        std::cout << "\n";
    };
    print_vector("Original Array :"); 
    TriPart(v,1);
    print_vector("After Partioning Array :"); 
    return 0;
}

