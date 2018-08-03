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
#include <limits.h>

void BusiestInterval(std::vector<int>& start, std::vector<int>& finish){
    int max_start = *(std::max_element(start.begin(),start.end()));
    int max_finish = *(std::max_element(finish.begin(),finish.end()));
    int max_interval = std::max(max_start,max_finish);
    
    std::vector<int> aux(max_interval+2,0);
    for(unsigned int i = 0; i < start.size() ; ++i){
        ++aux[start[i]];
        --aux[finish[i] + 1];
    }
    int max_count = INT_MIN;
    auto curr = 0;
    auto index = 0;
    for(int i = 0 ;i <= max_interval ; i++){
        curr += aux[i];
        if(max_count < curr){
            max_count = curr;
            index = i;
        }
    }
    std::cout << "Maximum value is " << max_count << " at position " << index << "\n";
}

int main(){
    {
        std::vector<int> start={1, 2, 10, 5, 5};
        std::vector<int> finish={4, 5, 12, 9, 12};

        BusiestInterval(start,finish);
    }
    {
        std::vector<int> start={13,28,29,14,40,17,3};
        std::vector<int> finish={107,95,111,105,70,127,74};

        BusiestInterval(start,finish);
    }
    return 0;
}
