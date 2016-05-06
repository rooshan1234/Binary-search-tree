#ifndef BINARY_TREE
#define BINARY_TREE
#include <iostream>

template <class T>
class BinaryTree {
private:
	struct Node {
		T value;
		Node* left;
		Node* right;
	};
	Node *root;
	void SearchNodeHelper(Node* root, T value);
	void InsertNodeHelper(Node*& root, T value);
	void PrintHelper(Node* root);
	void DeleteNodeHelper(Node*& root, T value);
public:
	BinaryTree() { root = NULL; }
	void InsertNode(T value);
	void Print();
	void SearchNode(T value);
	void DeleteNode(T value);
	~BinaryTree() { delete root; }
};

#endif // !BINARY_TREE

