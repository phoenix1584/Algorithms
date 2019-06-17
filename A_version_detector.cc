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

// From a list of tuples (app,API,version) , find the apps using older versions of APIs


#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <set>

int main(){
#if __cplusplus>=201103L
    std::string app,api,version,line;
    std::map<std::string,std::map<int,std::vector<std::string>>> api_index; // API NAME -> Version -> Apps 

    while(std::getline(std::cin,line)){
        std::istringstream ss(line);
        std::getline(ss,app,',');
        std::getline(ss,api,',');
        std::getline(ss,version,',');
        version.erase(remove_if(version.begin(), version.end(), isspace), version.end()); // removing spaces.
        int ver_int = std::stoi(std::string(version.begin()+1,version.end()),nullptr); // removing the "v" to extract version as number.
        api_index[api][ver_int].emplace_back(app);
    }
    std::set<std::string> old_api_user_apps;
    for(const auto& x : api_index){
        const auto old_version_count = x.second.size() - 1; 
        if(0 < old_version_count){
            for(const auto& z : x.second.begin()->second){
                old_api_user_apps.insert(z);
            }
        }
    }

    for(const auto& a : old_api_user_apps){
        std::cout << a << "\n";
    }
#else
    std::cout << "Please use c++11 for compilation\n";
#endif
    return 0;
}
