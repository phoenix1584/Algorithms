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

// From a list of tuples (app,API,version) , find the apps using older versions of APIs

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

class AppInfo{
    public:
        std::string m_app_name;
        std::string m_api_version;
        AppInfo(const std::string& app = "", const std::string& version="")
            :m_app_name(app)
            ,m_api_version(version)
        {}
        friend std::ostream& operator<<(std::ostream& os,AppInfo a){
            os << "app name : " << a.m_app_name << ", api version : " << a.m_api_version;
            return os;
        }
};

class AppInfoComp{
    public:
        bool operator()(const AppInfo& lhs,const AppInfo& rhs){
            return ( std::lexicographical_compare(lhs.m_api_version.begin(),lhs.m_api_version.end(),rhs.m_api_version.begin(),rhs.m_api_version.end())
                    || std::lexicographical_compare(lhs.m_app_name.begin(),lhs.m_app_name.end(),rhs.m_app_name.begin(),rhs.m_app_name.end()) );
        }
};

int main(){
    std::string app,api,version,line;
    std::map<std::string,std::set<AppInfo,AppInfoComp> > api_index;

    while(std::getline(std::cin,line)){
        std::istringstream ss(line);
        std::getline(ss,app,',');
        std::getline(ss,api,',');
        std::getline(ss,version,',');
        api_index[api].insert(AppInfo(app,version));
    }
    
    for (const auto& x : api_index){
        if(x.second.size() > 1){
            std::cout << x. first << "=>\n"; 
            auto itr = x.second.begin();
            const auto count = x.second.size() - 1;
            for (unsigned int y = 0 ; y < count  ; ++y, ++itr){
                std::cout << "\t" << *itr << "\n";
            }
        }
    }
}
