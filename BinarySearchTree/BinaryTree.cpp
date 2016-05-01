#include "BinaryTree.h"

template<class T>
void BinaryTree<T>::InsertNode(T value) {
	if (root == NULL) {
		root = new Node();
		root->value = value;
	}
	else {
		if (value > root->value) {
			InsertNodeHelper(root->right, value);
		}
		else if (value < root->value) {
			InsertNodeHelper(root->left, value);
		}
	}
}

template<class T>
void BinaryTree<T>::InsertNodeHelper(Node*& root, T value) {
	
	if (root == NULL) {
		root = new Node();
		root->value = value;
	}
	else {
		if (value > root->value) {
			InsertNodeHelper(root->right, value);
		}
		else if (value < root->value) {
			InsertNodeHelper(root->left, value);
		}
	}
}

template<class T>
void BinaryTree<T>::Print() {
	std::cout << root->value;
	if (root->left != NULL) {
		PrintHelper(root->left);
	}	
	if (root->right != NULL) {
		PrintHelper(root->right);
	}
}

template<class T>
void BinaryTree<T>::PrintHelper(Node* root) {
	if (root != NULL) {
		std::cout << root->value;
		if (root->left != NULL) {
			std::cout << root->value;
			PrintHelper(root->left);
		}
		else if (root->right != NULL) {
			std::cout << root->value;
			PrintHelper(root->right);
		}
	}
}
