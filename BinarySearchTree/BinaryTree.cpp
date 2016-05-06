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
	std::cout << root->value << std::endl;
	if (root->left != NULL) {
		PrintHelper(root->left);
	}	
	if (root->right != NULL) {
		PrintHelper(root->right);
	}
}

template<class T>
void BinaryTree<T>::PrintHelper(Node* root) {

	std::cout << root->value << std::endl;
	if (root->left != NULL) {
		PrintHelper(root->left);
	}
	if (root->right != NULL) {
		PrintHelper(root->right);
	}
}

template<class T>
void BinaryTree<T>::SearchNode(T value) {
	if (root->value == value) {
		std::cout << "Node exists";
		return;
	}
	else if (value > root->value){
		SearchNodeHelper(root->right, value);
	}else if (value < root->value){
		SearchNodeHelper(root->left, value);
	}
}

template<class T>
void BinaryTree<T>::SearchNodeHelper(Node* root, T value) {
	if (root!= NULL) {
		if (root->value == value) {
			std::cout << "Node exist";
			return;
		}
		else if (value > root->value) {
			SearchNodeHelper(root->right, value);
		}
		else if (value < root->value) {
			SearchNodeHelper(root->left, value);
		}
	}
	//root is null case
	else {
		std::cout << "Node does exist";
		return;
	}
}

template<class T>
void BinaryTree<T>::DeleteNode(T value)
{
	if (root->value == value) {
		//delete of the root of the tree
		if (root->right != NULL) {
			root = root->right;
		}
		else if (root->left != NULL) {
			root = root->left;
		}
		else if (root->right == NULL && root->left == NULL) {
			//delete the tree if root has no children
			root = NULL;
		}
	}
	else if (value > root->value) {
		DeleteNodeHelper(root->right, value);
	}
	else if (value < root->value) {
		DeleteNodeHelper(root->left, value);
	}
}

template<class T>
void BinaryTree<T>::DeleteNodeHelper(Node*& root, T value)
{
	bool found = false;
	if (root == NULL && !found) {
		//end of subtree, node not found
		return;
	}
	else {
		if (value == root->value && !found) {
			//handle three different cases
			if (root->right == NULL && root->left == NULL) {
				//deleting node has no childern
				root = NULL;
				return;
			}
			//deleting node has 1 child, left or right
			else if (root->right != NULL && root->left == NULL) {
				//handling right case
				root = root->right;
				return;
			}
			else if (root->right == NULL && root->left != NULL) {
				//handling left case
				root = root->left;
				return;
			}
			//deleting node has both left and right child
			else {
				//sub case 1:
				//target nodes left child has no right child
				if (root->left->right == NULL) {
					root = root->left;
				}
				else {
					//start new sub function to find root replacement
					//funck(root->left->right, value, true);
				}
			}
		}
	}
}