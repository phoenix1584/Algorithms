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
// C program to print right sibling of a node 
#include <stdio.h> 
#include <stdlib.h> 

// A Binary Tree Node 
struct Node { 
	int data; 
	Node* left, *right, *parent; 
}; 

// A utility function to create a new Binary 
// Tree Node 
Node* newNode(int item, Node* parent) 
{ 
	Node* temp = new Node; 
	temp->data = item; 
	temp->left = temp->right = NULL; 
	temp->parent = parent; 
	return temp; 
} 

// Method to find right sibling 
Node* findRightSibling(Node* node, int level) 
{ 
	if (node == NULL || node->parent == NULL) 
		return NULL;	 

	// GET Parent pointer whose right child is not 
	// a parent or itself of this node. There might 
	// be case when parent has no right child, but, 
	// current node is left child of the parent 
	// (second condition is for that). 
	while (node->parent->right == node || 
		(node->parent->right == NULL && 
		node->parent->left == node)) { 
		if (node->parent == NULL) 
			return NULL; 
		

		node = node->parent; 
		level--; 
	} 

	// Move to the required child, where right sibling 
	// can be present 
	node = node->parent->right; 

	// find right sibling in the given subtree(from current 
	// node), when level will be 0 
	while (level < 0) { 

		// Iterate through subtree 
		if (node->left != NULL) 
			node = node->left; 
		else if (node->right != NULL) 
			node = node->right; 
		else

			// if no child are there, we cannot have right 
			// sibling in this path 
			break; 
		
		level++; 
	} 

	if (level == 0) 
		return node;	 

	// This is the case when we reach 9 node in the tree, 
	// where we need to again recursively find the right 
	// sibling 
	return findRightSibling(node, level); 
} 

// Driver Program to test above functions 
int main() 
{ 
	Node* root = newNode(1, NULL); 
	root->left = newNode(2, root); 
	root->right = newNode(3, root); 
	root->left->left = newNode(4, root->left); 
	root->left->right = newNode(6, root->left); 
	root->left->left->left = newNode(7, root->left->left); 
	root->left->left->left->left = newNode(10, root->left->left->left); 
	root->left->right->right = newNode(9, root->left->right); 
	root->right->right = newNode(5, root->right); 
	root->right->right->right = newNode(8, root->right->right); 
	root->right->right->right->right = newNode(12, root->right->right->right); 

	// passing 10 
	Node *res = findRightSibling(root->left->left->left->left, 0); 
	if (res == NULL) 
	printf("No right sibling"); 
	else
	printf("%d", res->data); 

	return 0; 
} 

