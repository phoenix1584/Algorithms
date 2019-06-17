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

 // Finding the median of stream of number.
 // Solution uses two heaps. 

#include<iostream>
#include<fstream>
#include<queue>
   
int main(){
    std::priority_queue<int,std::vector<int>,std::less<int> > q_low;
    std::priority_queue<int,std::vector<int>,std::greater<int> >q_high;
    std::ifstream ifs("median_stream.txt");
    auto x = 0,sum_median = 0, median = 0,k = 0;
    while(ifs >> x){
        ++k;
        if(q_low.size() == q_high.size()){
            (x < median) ? q_low.push(x) : q_high.push(x);
        }else{
            if(q_low.size() > q_high.size()){
                if(x < median){
                    q_high.push(q_low.top());
                    q_low.pop();
                    q_low.push(x);
                }else{
                    q_high.push(x); 
                } 
            }
            if(q_low.size() < q_high.size()){
                if(x < median){
                    q_low.push(x);
                }else{
                    q_low.push(q_high.top());
                    q_high.pop();
                    q_high.push(x);
                } 
            }
        }
        if(q_low.size() == q_high.size()){
            median = q_low.top();
        }else{
            if(q_low.size() > q_high.size()){
                median = q_low.top();
            }else{
                median = q_high.top();
            }
        }
        sum_median += median;
    }
    std::cout << (sum_median%10000) << "\n";
}
