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
#include <climits>

// Function to find length of longest increasing subsequence
int SearchLISExp(int arr[], int i, int n, int prev)
{
    // Base case: nothing is remaining
    if (i == n)
        return 0;

    // case 1: exclude the current element and process the
    // remaining elements
    int excl = SearchLISExp(arr, i + 1, n, prev);

    // case 2: include the current element if it is greater
    // than previous element in LIS
    int incl = 0;
    if (arr[i] > prev)
        incl = 1 + SearchLISExp(arr, i + 1, n, arr[i]);

    // return maximum of above two choices
    return std::max(incl, excl);
}

void SearchLIS(std::vector<int>& vec){
    std::vector<int> LIS[vec.size()];
    LIS[0].push_back(vec[0]); // The longest sequence for the first element is the element itself.

    for(unsigned int i = 1 ; i < vec.size(); i++){ // WARNING : Indexing has to start from 1 NOT 0 !
        for(unsigned int j = 0 ; j < i ; j++){
            if(vec[j] < vec[i] && LIS[j].size() > LIS[i].size())
                LIS[i] = LIS[j];
        }
        LIS[i].push_back(vec[i]);
    }
    unsigned int x = 0;
    for (unsigned int i = 0 ; i < vec.size() ; i++){
        if (LIS[x].size() < LIS[i].size()){
            x = i;
        }
    }
    std::cout << "Total Length (N^2) : " << LIS[x].size() << " ==> ";
    for (auto s : LIS[x]){
        std::cout << s << " ";
    }
    std::cout << "\n";
}

// Method 2 : referene : https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
// TODO : Could be a lambda.
int CeilIndex(std::vector<int> &v , int l, int r, int key){
    while ((r-l) > 1){
        int m = l + (r - l)/2;
        if ( v[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

void SearchLISCount(std::vector<int>& vec){
    if ( vec.size() == 0)
        return;
    std::vector<int> tail(vec.size(),0);
    int length = 1; // Points to empty slot in tail
    tail[0] = vec[0];
    for (size_t i = 1 ; i < vec.size() ; i++){
        if(vec[i] < tail[0])
            tail[0] = vec[i];
        else if (vec[i] > tail[length - 1])
            tail[length++] = vec[i];
        else
            tail[CeilIndex(tail,-1,length-1,vec[i])] = vec[i];
    }
    std::cout << "LIS length (NlogN) : " << length << "\n"; 
}

int main(){
    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 ,1,2,3,4,5,6,7,8};
	int n  = sizeof(arr)/sizeof(arr[0]);
    std::vector<int> vec(arr,arr+n);
	std::cout << "Actual sequence : \n";
	for (const auto x: vec){
		std::cout << x << " ";
	}
	std::cout << "\n==Results==\n";
	std::cout << "LIS length (Exp) : " << SearchLISExp(arr,0,n,INT_MIN) << "\n";
    SearchLIS(vec);
    SearchLISCount(vec);
    return 0;
}
