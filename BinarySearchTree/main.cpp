#include "BinaryTree.cpp"
#include <iostream>

int main() {
	BinaryTree<int> BTree;
	BTree.InsertNode(15);
	BTree.InsertNode(7);
	BTree.InsertNode(3);
	BTree.InsertNode(1);
	BTree.InsertNode(6);

	//BTree.SearchNode(3);
	
	//BTree.DeleteNode(3);

	BTree.DeleteNode(15);

	std::cout << "Node deleted: " << std::endl;
	BTree.Print();

	BTree.DeleteNode(1);

	//BTree.SearchNode(3);
	std::cout << "Node deleted: " << std::endl;
	BTree.Print();

}