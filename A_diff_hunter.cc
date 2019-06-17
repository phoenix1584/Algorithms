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
#include <vector>

auto vec_printer = [](const std::vector<int>& v){
    for(const auto& x : v)
        std::cout << x << "," ;
    std::cout << "\n";
};

int MaxDiff(const std::vector<int>& vec) {
    if(vec.size() < 2)
        return -1;
    auto min_val = vec[0];
    auto max_diff = vec[1] - vec[0];
    for (std::vector<int>::const_iterator itr = vec.begin() + 1 ; itr != vec.end() ; ++itr){
        if((*itr - min_val) > max_diff)
            max_diff = (*itr - min_val);
        if(*itr < min_val)
            min_val = *itr;
    }
    return max_diff;
}

void MultiMaxDiff(const std::vector<int>& vec){
    if(vec.size() < 2){
        std::cout << "Insufficient data to compute.\n";
        return;
    }
    class Interval{
        public:
            int m_low;
            int m_high;
    };

    std::vector<Interval> intervals;
    unsigned int index = 0;
    const auto iterations = vec.size() - 1;
    while(index < iterations ){
        while ((index < iterations - 1) && (vec[index + 1] <= vec[index])){
            index++;
        }
        if(index == iterations - 1){
            break;
        }else{

            intervals.emplace_back();
            intervals.back().m_low = index;
            ++index;
            while ((index < vec.size()) && (vec[index] >= vec[index - 1]))
                index++;
            intervals.back().m_high = --index;
        }
    }
    std::cout << "MultiMax Diff : \n";
    for (const auto& interval : intervals){
        std::cout << "Low : " << interval.m_low << ", High : " << interval.m_high << "\n";
    }
}


int main(){
    std::vector<int> v = {1, 2, 90, 10, 110};
    vec_printer(v);
    std::cout << "Max diff (only max) : " << MaxDiff(v) << "\n";
    std::vector<int> m_v = {100, 180, 260, 310, 40, 535, 695};
    vec_printer(m_v);
    MultiMaxDiff(m_v);
    return 0;
}
