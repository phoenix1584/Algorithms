/*
 * Copyright (c) 2018
 * Author phoenix1584 
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
#include <memory>
#include <algorithm>

auto helper_tbd = [](const char * str){std::cout << str << " To be implemented....\n";};

class Graph{
    private:
        std::vector<std::vector<int>> m_graph_data;
    public:
        Graph() = delete;
        explicit Graph(int n){
            m_graph_data = std::vector<std::vector<int>>(n+1);
        }

        void AddEdge(int u,int v){
            m_graph_data[u].push_back(v);
        }

        void PrintGraph() const{
            std::cout << "Printing graph\n";
            auto idx_u = 0;
            for(const auto& u : m_graph_data){
                for(const auto& v : u){
                    std::cout << " [" << idx_u << "," << v << "]";
                }
                std::cout << "\n";
                ++idx_u;
            }
            std::cout << "\n";
        }

        bool AreConnected(int u,int v) const{
            if ( u > m_graph_data.size()){
                std::cout << "Node 1 not part of graph.\n";
                return false;
            }
            return( m_graph_data[u].end() != std::find(m_graph_data[u].begin(),m_graph_data[u].end(),v));
        }

};

int main(){
    std::cout << __TIME__  << " : Program accepts first line as number of nodes, followed by comma separated edges.\n";
    int n ; // Total number of entires
    std::cin >> n;
    int u,v;
    Graph obj_graph(n);
    for(auto i = 0 ; i < n - 1 ; ++i){
        std::cin >> u >> v;;
        obj_graph.AddEdge(u,v);
    }
    obj_graph.PrintGraph();
    std::cout << "Please input 2 nodes to be checked for direct connectivity\n";
    std::cin >> u >> v;
    std::cout << (obj_graph.AreConnected(u,v) ? "Connected\n" : "Disconnected\n");
    return 0;
}

