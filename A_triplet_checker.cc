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
// 3 Sum variant as Pythagorean triplet. Possible with or without hash.
// O(N^2) complexity

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

auto print_vector = [](const std::vector<int>& v, std::string msg){ 
    std::cout << msg << "\n";
    for(const auto x : v){
        std::cout << x << ",";
    }
    std::cout << "\n";
};

bool TripletFinder(std::vector<int>& vec){
    for_each(vec.begin(),vec.end(),[](int& i){ i = i*i;});
    std::sort(vec.begin(),vec.end());
    auto sum = 0;
    for(auto itr = vec.end() ; itr != vec.begin() + 1 ; --itr){
       auto lbound_itr = vec.begin(); 
       auto ubound_itr = (itr -1);
       while(lbound_itr < ubound_itr){
           sum = *lbound_itr + *ubound_itr;
           if(sum == *itr){
               std::cout << *lbound_itr << " + " << *ubound_itr << " = " << *itr << "\n";
               return true;
           }
           (sum  < *itr) ? lbound_itr++ : ubound_itr--;
       } 
    }
    return false;
}

int main(){
    std::vector<int> v = {3, 1, 4, 6, 5};
    print_vector(v,"Original Data : ");
    std::cout << (TripletFinder(v) ? "Triplet exists" : "No triplets found") << "\n"; 
    return 0;
}

