/*
 * Copyright (c) 2019
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

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

auto helper_tbd = [](const char * str){std::cout << str << " To be implemented....\n";};

class Node{
    public:
        int m_value = -1;
        Node* m_left = nullptr;
        Node* m_right = nullptr;

        Node() = delete;
        explicit Node(const int val)
            :m_value(val)
        {}

        friend std::ostream& operator<<(std::ostream& os,const Node& n){
            os << n.m_value ;
            return os;
        }
        ~Node() = default;
};

class BinarySearchTree{
    private:
        Node * m_root = nullptr;
        int m_total_nodes = 0;
        Node * InsertNode(Node * node , int value);
        void IOTImpl(Node * node);
        void PreOTImpl(Node * node);
        void PostOTImpl(Node * node);
        void DeleteTree(Node * node);
        void KMinSearch(Node * root, unsigned int k,unsigned int n);
    public:
        BinarySearchTree() = delete;
        explicit BinarySearchTree(int n)
            :m_total_nodes(n)
        {}
        
        void AddNode(int value);
        void DeleteNode(int value);
        void LevelOrderTraversal();
        void InorderTraversal();
        void PreorderTraversal();
        void PostorderTraversal();
        bool Search(const int value);
        void Kmin(int k);
        ~BinarySearchTree();
};
        
Node * BinarySearchTree::InsertNode(Node * node , int value){
        if(nullptr == node){
            //++m_total_nodes;
            return (new Node(value));
        }
        if(value >= node->m_value){
            node->m_right = InsertNode(node->m_right,value);
        }else{
            node->m_left = InsertNode(node->m_left,value);
        }
        return node;
}
        
void BinarySearchTree::AddNode(int value){ 
    // Empty tree insert root else add based on BST property.
    if ( nullptr == m_root ){
        m_root = new Node(value); 
        //++m_total_nodes;
    }else{
        InsertNode(m_root,value);
    }
}

void BinarySearchTree::DeleteNode(int value){ 
    helper_tbd(__func__); 
}

void BinarySearchTree::LevelOrderTraversal(){ 
    std::cout << __func__ << " : \n"; 
    if(m_root){
        std::queue<Node *> q;
        q.push(m_root);

        while(1){
            auto node_count = q.size();
            if(0 == node_count)
                break; 

            while(node_count){
                Node * tmp = q.front();
                std::cout << tmp->m_value << " ";
                q.pop(); 
                if(tmp->m_left){
                    q.push(tmp->m_left);
                }
                if(tmp->m_right){
                    q.push(tmp->m_right);
                }
                --node_count;
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

void BinarySearchTree::IOTImpl(Node * node){
    if(node){
        if (node->m_left) { IOTImpl(node->m_left); }
        std::cout << node->m_value << ",";
        if (node->m_right) { IOTImpl(node->m_right); }
    }
}

void BinarySearchTree::InorderTraversal(){ 
    std::cout << __func__ << " : "; 
    IOTImpl(m_root);
    std::cout << "\n"; 
}

void BinarySearchTree::PreOTImpl(Node * node){
    if(node){
        std::cout << node->m_value << ",";
        if (node->m_left) { IOTImpl(node->m_left); }
        if (node->m_right) { IOTImpl(node->m_right); }
    }
}

void BinarySearchTree::PreorderTraversal(){ 
    std::cout << __func__ << " : "; 
    PreOTImpl(m_root);
    std::cout << "\n"; 
}

void BinarySearchTree::PostOTImpl(Node * node){
    if(node){
        if (node->m_left) { IOTImpl(node->m_left); }
        if (node->m_right) { IOTImpl(node->m_right); }
        std::cout << node->m_value << ",";
    }
}

void BinarySearchTree::PostorderTraversal(){ 
    std::cout << __func__ << " : "; 
    PostOTImpl(m_root);
    std::cout << "\n"; 
}

bool BinarySearchTree::Search(const int value){ 
    helper_tbd(__func__);
    return false;
}

void BinarySearchTree::DeleteTree(Node * node){
    if(node){
        if (node->m_left) { DeleteTree(node->m_left); }
        if (node->m_right) { DeleteTree(node->m_right); }
        delete node;
    }
}

// #FIXME and move to a separate file if needed.
void BinarySearchTree::KMinSearch(Node * root, unsigned int k,unsigned int n){
    // std::cout << k << "," << n << "\n";
    if(nullptr == root || n < 1 || k < 1)
        return;
    if( n == 3 ){
        if (k == 1) { std::cout << "Found it : " << root->m_left->m_value << "\n"; return; }
        if (k == 3) { std::cout << "Found it : " << root->m_right->m_value << "\n"; return; }
    }
    if (k == ((n-1)/2 + 1)){
        std::cout << "Found it : " << root->m_value << "\n";
        return;
    }
    if( k < (n-1)/2){
        // std::cout << "left " << root->m_left->m_value << "\n";
        KMinSearch(root->m_left,k,(n-1)/2);
    }
    if( k > ((n-1)/2 + 1)){
        // std::cout << root->m_right->m_value << " right\n";
        KMinSearch(root->m_right,(k - ((n-1)/2 + 1)),(n-1)/2);
    }
}
        
void BinarySearchTree::Kmin(int k){
    if ( k < 1 || k > m_total_nodes){
        std::cout << "Incorrect value of k !\n";
        return;
    }
    std::cout << k << "th min value finder.\n";  
    KMinSearch(m_root,k,m_total_nodes);
}

BinarySearchTree::~BinarySearchTree(){
    DeleteTree(m_root);
}


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
    obj_bst.InorderTraversal();
    obj_bst.PreorderTraversal();
    obj_bst.PostorderTraversal();
    obj_bst.LevelOrderTraversal();

    std::cout << "STUB for kmin logarithmic complexity.\n";
    //std::vector<int> test_data = {7,5,9,8,10,6,4};
    std::vector<int> test_data = {8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
    std::for_each(test_data.begin(),test_data.end(),[](int& x){ x = x*x;});
    BinarySearchTree obj_bst_full_and_complete(test_data.size());
    for(const auto& x : test_data){
        obj_bst_full_and_complete.AddNode(x);
    }
    obj_bst_full_and_complete.LevelOrderTraversal();
    obj_bst_full_and_complete.Kmin(5);
    obj_bst_full_and_complete.Kmin(1);
    obj_bst_full_and_complete.Kmin(15);
    obj_bst_full_and_complete.Kmin(8);
    obj_bst_full_and_complete.Kmin(10);
}
