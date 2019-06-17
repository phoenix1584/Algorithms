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

// Serialize and de-seralize a tree to a string. Uses Pre order traversal.
// The string could be written to file as an extension.

#include <iostream>
#include <vector>
#include <string>

#define DELIMITER ']'
// Global storage as buffer before writing
std::string serial_data;
const int MAX_CHILDREN = 10;
// Considering N ary tree
class Node{
    public:
        char m_data;
        std::vector<Node*> m_children;
        Node(int data)
            :m_data(data)
             ,m_children(MAX_CHILDREN)
    {}
        ~Node(){
            for(auto x : m_children){
                delete x;
            }
        }
};

void Serialize(Node* root){
    if (nullptr == root)
        return;
    
    serial_data.push_back(root->m_data);
    for(auto itr = root->m_children.begin() ; (itr != root->m_children.end()) && (*itr != nullptr) ; ++itr){
        Serialize(*itr);
    }
    serial_data.push_back(DELIMITER);
}

bool Deserialize(Node *& root, unsigned int& index){
    if((index >= serial_data.size()) || (DELIMITER == serial_data[index])){
        index++;
        return false; 
    }else{
        root = new Node(serial_data[index]);
        index++;
        for(auto& x : root->m_children){
            if(!Deserialize(x,index))
                break;
        }
    }
    return true;
}

Node * CreateDummyTree()
{
    Node *root = new Node('A');
    root->m_children[0] = new Node('B');
    root->m_children[1] = new Node('C');
    root->m_children[2] = new Node('D');
    root->m_children[0]->m_children[0] = new Node('E');
    root->m_children[0]->m_children[1] = new Node('F');
    root->m_children[2]->m_children[0] = new Node('G');
    root->m_children[2]->m_children[1] = new Node('H');
    root->m_children[2]->m_children[2] = new Node('I');
    root->m_children[2]->m_children[3] = new Node('J');
    root->m_children[0]->m_children[1]->m_children[0] = new Node('K');
    return root;
}

void Traverse(Node * root){
    if(root){
        std::cout << root->m_data << ",";
        for(auto& x : root->m_children){
            Traverse(x);
        }
    }
}

int main(){
   Node * root = CreateDummyTree();
   Serialize(root);
   std::cout << "Serialized Tree : "  << serial_data << "\n";
   Node * d_root = nullptr;
   unsigned int index = 0;
   Deserialize(d_root,index);
   std::cout << "Post Deserialization\n"; 
   Traverse(d_root);
   std::cout << "\n";
   return 0; 
}
