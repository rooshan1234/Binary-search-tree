#include "BinaryTree.cpp"
#include <iostream>

int main() {
	BinaryTree<int> BTree;
	BTree.InsertNode(30);
	BTree.InsertNode(10);
	BTree.InsertNode(20);
	BTree.InsertNode(2);
	BTree.InsertNode(1);
	BTree.InsertNode(3);
	BTree.InsertNode(8);
	BTree.InsertNode(7);
	//BTree.InsertNode(12);

	BTree.PrintTreePostOrder();

	//BTree.SearchNode(9);
	
	BTree.DeleteNode(10);

	//BTree.DeleteNode(15);
	std::cout << "Node deleted: " << std::endl;

	BTree.PrintTreePostOrder();

	//BTree.Print();

	//BTree.DeleteNode(1);
	//BTree.SearchNode(3);
	//std::cout << "Node deleted: " << std::endl;
	//BTree.Print();

}