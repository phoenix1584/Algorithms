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

// One possible implementation of Least Recently Used (LRU) Cache using List and Hash
// The list presrves the access sequence and the hash provide the constant time data look-up
// TODO : Implement as templates and check if user defined classes could be
// handled as well

#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class LRUCache{
    private:
        std::list<int> m_seq_store;
        std::unordered_map<int,std::list<int>::iterator> m_key_store;
        unsigned int m_max_size;
    public:
        LRUCache(int max_size) 
            :m_max_size(max_size)
        {}

        void Refer(int key){
            // Check if element already present. If not update cache, otherwise reorder the 
            // sequence list.
            if(m_key_store.end() == m_key_store.find(key)){
                if(m_max_size == m_seq_store.size()){
                    m_key_store.erase(m_seq_store.back()); 
                    m_seq_store.pop_back();
                }
            }else{
                m_seq_store.erase(m_key_store[key]);
            }

            // Cache has been reorganized, hence update the latest entry.
            m_seq_store.push_front(key);
            m_key_store[key] = m_seq_store.begin();
        }

        friend std::ostream& operator<<(std::ostream& os, const LRUCache& lc){
            os << "Capacity : [ " << lc.m_seq_store.size() << "/" << lc.m_max_size << " ] : ";
            for(const auto& x : lc.m_seq_store){
                os << x << " ";
            }
            return os;
        }
};

int main(){
    auto itr_count = 0;
    const int max_size = 5;
    const int rand_limiter = max_size * 2;
    std::cout << "Please enter the total number of iterations you want to see simulated for cache size of " << max_size << ", data range [1,10] \n";
    std::cin >> itr_count;

    std::cout << "Starting simulation for " << itr_count << " iterations.\n";
    LRUCache lru_cache(max_size);
    std::srand(std::time(nullptr));
    for(int i = 0 ; i < itr_count ; ++i){
        auto key = 1 + std::rand()% rand_limiter;
        lru_cache.Refer(key);
        std::cout << "Access #" << i <<" : Key = " << key << " ==> Cache : "  << lru_cache << "\n";
        sleep(1);
    }
    
    return 0;
}
