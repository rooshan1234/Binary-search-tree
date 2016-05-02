#include "BinaryTree.cpp"
#include <iostream>

int main() {
	BinaryTree<int> BTree;
	BTree.InsertNode(5);
	BTree.InsertNode(10);
	BTree.InsertNode(3);
	BTree.InsertNode(100);

	BTree.SearchNode(3);

	BTree.Print();
}