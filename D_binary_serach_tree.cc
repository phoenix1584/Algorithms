/*
 * Copyright (c) 2018
 * Author : phoenix1584
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

#include<iostream>

auto helper_tbd = [](const char * str){std::cout << str << " To be implemented....\n";};

class Node{
    public:
        int m_value;
        Node* m_left;
        Node* m_right;

        friend std::ostream& operator<<(std::ostream& os,const Node& n){
            os << n.m_value ;
            return os;
        }
};

class BinarySearchTree{
    private:
        Node * root = nullptr;
        int m_total_nodes = 0;
    public:
        BinarySearchTree() = delete;
        explicit BinarySearchTree(const int n)
            :m_total_nodes(n)
        {}
        
        void AddNode(int value);
        void DeleteNode(int value);
        void BFS();
        void DFS();
        void InorderTraversal();
        void PreorderTraversal();
        void PostorderTraversal();
};
        
void BinarySearchTree::AddNode(int value){ helper_tbd(__func__); };
void BinarySearchTree::DeleteNode(int value){ helper_tbd(__func__); };
void BinarySearchTree::BFS(){ helper_tbd(__func__); };
void BinarySearchTree::DFS(){ helper_tbd(__func__); };
void BinarySearchTree::InorderTraversal(){ helper_tbd(__func__); };
void BinarySearchTree::PreorderTraversal(){ helper_tbd(__func__); };
void BinarySearchTree::PostorderTraversal(){ helper_tbd(__func__); };

int main(){
    std::cout << __TIME__  << " : Program accepts first line as total number of entires, followed by entires.\n";
    int n ; // Total number of entires
    std::cin >> n;
    int x = 0;
    BinarySearchTree obj_bst(n);
    for(auto i = 0 ; i < n ; ++i){
        std::cin >> x;
        obj_bst.AddNode(x);
    }

}
