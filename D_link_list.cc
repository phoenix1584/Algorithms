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

class LinkedList{
    private:
        class Node{
            private:
            public:
                int m_data;
                Node* m_next;
                Node() = delete;
                explicit Node(const int data)
                    :m_data(data)
                    ,m_next(nullptr)
                {}
        };

        Node* m_head = nullptr;
        Node* m_tail = nullptr;
        
        void DeleteNode(Node* to_be_deleted){
            if(to_be_deleted->m_next){
                Node* tmp = to_be_deleted->m_next;
                to_be_deleted->m_data = to_be_deleted->m_next->m_data;
                to_be_deleted->m_next = to_be_deleted->m_next->m_next;
                delete tmp;
            }else{
               delete to_be_deleted;
            }
        }

    public:

        LinkedList()
        {}

        void AddNode(int data){
            if(nullptr == m_head){
                m_head = new Node(data); 
                m_tail = m_head;
            }else{
                m_tail->m_next = new Node(data);
                m_tail = m_tail->m_next;
            }
        }

        void DeleteNode(int node_index){
            Node* itr = m_head;
            for(auto i = 0 ; i < node_index-1 ; ++i){
                itr = itr->m_next;
            }
            if(itr){
                DeleteNode(itr);
            }
        }
      
        // The Linus Method. Works but has memory leak ! 
        void DeleteNodeByValue(int to_remove){
            Node **pp = &m_head; /* pointer to a pointer */
            Node *entry = m_head;
            while (entry) {
                if (entry->m_data == to_remove){
                    *pp = entry->m_next;
                }

                pp = &entry->m_next;
                entry = entry->m_next;
            }
        }
        
        void PrintList() const{
            if(m_head){ 
                std::cout << "Nodes : ";
                Node * itr = m_head;
                while(itr){
                    std::cout << itr->m_data << ",";
                    itr = itr->m_next;
                }
                std::cout << "\n";
            }else{
                std::cout << "List is empty.\n";
            }
        }

        ~LinkedList(){
            Node * curr = m_head;
            Node * next = nullptr;
            while(curr){
                next = curr->m_next;
                delete(curr);
                curr = next;
            }
        }
};

int main(){
    std::cout << __TIME__  << " : Program accepts first line as total number of entires, followed by entires.\n";
    int n ; // Total number of entires
    std::cin >> n;
    int x = 0;
    LinkedList obj_ll;
    for(auto i = 0 ; i < n ; ++i){
        std::cin >> x;
        obj_ll.AddNode(x);
    }
    obj_ll.PrintList();
    obj_ll.DeleteNodeByValue(4);
    std::cout << "List post deletion.\n";
    obj_ll.PrintList();
    return 0;
}
