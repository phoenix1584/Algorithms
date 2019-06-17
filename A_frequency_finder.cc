/*
 * Copyright (c) 2019
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
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

int main(){
    std::vector<int> v = {3, 1, 4, 4, 5, 2, 6, 1};
    auto k = 2;
    std::unordered_map<int,int> counter;
    for(const auto& x : v){
        counter[x]++;
    }

    std::vector<std::pair<int,int>> freq_count(counter.begin(),counter.end());
    auto cmp = [](std::pair<int,int> lhs,std::pair<int,int> rhs){ 
        if(lhs.second == rhs.second)
            return lhs.first < rhs.first;
        return lhs.second < rhs.second;
    };
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,decltype(cmp)> heap(cmp,freq_count);
    for (auto i = 0 ; i < k ; ++i){
        std::cout << heap.top().first << "\n";
        heap.pop();
    }
}
