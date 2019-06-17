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

// Long int ID <=> shortURL

#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>

class URLConvertor{
    private:
        const std::string m_alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    public:
        std::string IDToShortURL(unsigned long int id){
            std::string short_url;
            while(id){
                short_url.push_back(m_alphabet[id%m_alphabet.size()]);
                id = (id/m_alphabet.size());
            }
            std::reverse(short_url.begin(),short_url.end());
            return short_url;
        }

        unsigned long int ShortURLToID(std::string short_url){
            unsigned long int id = 0;
            for(const auto& c : short_url){
                if( 'a' <= c && c <= 'z')
                { id = id * m_alphabet.size() + (c - 'a'); }
                else if( 'A' <= c && c <= 'Z')
                { id = id * m_alphabet.size() + (c - 'A' + ('z' - 'a' + 1)); }
                else if( '0' <= c && c <= '9')
                { id = id * m_alphabet.size() + (c - '0' + ('Z' - 'a' + 1)); }
                else{
                    std::cout << " == ERROR ===\n";
                }
            }
            return id;
        }
};

int main(){
    std::cout << "Enter a valid unsigned 64 bit integer : \n";
    unsigned int n = 0 ;
    std::cin >> n;
    if( n < UINT_MAX){
        URLConvertor conv;
        std::string url = conv.IDToShortURL(n);
        std::cout << url << " <=> " << conv.ShortURLToID(url) << "\n";
    }else{
        std::cout << "Inavlid input.Exiting application.\n";
    }
    return 0;
}
