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
#include <unordered_set>

std::pair<int,int> Check2Sum(std::vector<int>& vec, const int target_sum){
    std::sort(vec.begin(),vec.end()); 
    auto itr_start = vec.begin();
    auto itr_end = vec.end() -1;
    std::pair<int,int> result(-1,-1);
    auto sum = 0; 
    while(itr_start < itr_end){
        sum = (*itr_start + *itr_end);
        if(target_sum == sum){
            result.first = *itr_start;
            result.second = *itr_end;
            break;
        }else if(sum < target_sum){
            itr_start++;
        }else{
            itr_end--;
        }
    }
    return result;
}

std::pair<int,int> Check2SumHash(std::vector<int>& vec, const int target_sum){
    std::unordered_set<int> val_hash;
    std::pair<int,int> result(-1,-1);
    for(const auto& x : vec){
        if(val_hash.find(target_sum - x) != val_hash.end()){
            result.first = target_sum - x;
            result.second = x;
            break;
        }
        val_hash.insert(x);
    }
    return result;
}

int main(){
    std::vector<int> vec = {1, 4, 45, 6, 10, -8}; 
    int target = 16;
    auto result_vals = Check2Sum(vec,target);
    std::cout << target << " => " << result_vals.first << "," << result_vals.second << "\n";
    auto result_vals_hash = Check2SumHash(vec,target);
    std::cout << target << " => " << result_vals_hash.first << "," << result_vals_hash.second << "\n";
    return 0;
}
