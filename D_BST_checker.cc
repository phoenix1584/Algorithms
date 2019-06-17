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

#include <iostream>

class Node{
    public:
        int m_data;
        Node* m_left = nullptr;
        Node* m_right = nullptr;
        Node(int data)
           :m_data(data)
        {} 
        ~Node(){
            if(m_left)
                delete m_left;
            if(m_right)
                delete m_right;
        }
};

bool VerifyBST(Node * root, Node *left = nullptr, Node *right = nullptr){
    if (root == nullptr)
        return true;
    if(left != nullptr && root->m_data < left->m_data)
        return false;
    if(right != nullptr && root->m_data > right->m_data)
        return false;
    return ( VerifyBST(root->m_left,left,root) && VerifyBST(root->m_right,root,right));
}

int main(){
    Node * root = new Node(3);
    root->m_left = new Node(2);
    root->m_right = new Node(5);
    root->m_left->m_left = new Node(1);
    root->m_left->m_right = new Node(4);
    std::cout << (VerifyBST(root) ? "Correct BST." : "Fake BST !") << "\n";
    delete root;
}
