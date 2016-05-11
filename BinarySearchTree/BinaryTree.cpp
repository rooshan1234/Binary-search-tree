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
			root->value = root->right->value;
		}
		else if (root->left != NULL) {
			root->value = root->left->value;
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
	if (root == NULL) {
		return;
	}
	else {
		if (root->value == value) {
			//node found
			if (root->left == NULL && root->right == NULL) {
				//node has no childen, node is a leaf node
				root = NULL;
				return;
			}
			else if (root->left != NULL && root->right == NULL) {
				//node has left child, no right child
				root = root->left;
				return;
			}
			else if (root->left == NULL && root->right != NULL) {
				//node has right child, no left child
				root = root->left;
				return;
			}
			else {
				//node has both left and right node
				if (root->left->right == NULL) {
					//root nodes left, right child is null and can be replaced with root
					root->left->right = root->right;
					root = root->left;
					return;
				}
				else {
					//root nodes left, right child is not null
					Node* replacementNode = FindDeleteNode(root->left->right);
					replacementNode->left = root->left;
					replacementNode->right = root->right;
					root = replacementNode;
					return;
				}
			}
		}
		else if (value > root->value) {
			//search the right tree
			DeleteNodeHelper(root->right, value);
		}
		else if (value < root->value) {
			//search the left tree
			DeleteNodeHelper(root->left, value);
		}
	}
}
template<class T>
typename BinaryTree<T>::Node* BinaryTree<T>::FindDeleteNode(Node *& root)
{
	if (root->right != NULL) {
		return FindDeleteNode(root->right);
	}
	else {
		if (root->left != NULL) {
			Node* temp = root;
			root = root->left;
			return temp;
		}
		else {
			return root;
		}
	}
}
template<class T>
void BinaryTree<T>::PrintTreePostOrderHelper(Node * root, int indent)
{
	if (root != NULL) {
		if (root->left) PrintTreePostOrderHelper(root->left, indent + 4);
		if (root->right) PrintTreePostOrderHelper(root->right, indent + 4);
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		std::cout << root->value << "\n ";
	}
}

template<class T>
void BinaryTree<T>::PrintTreePostOrder()
{
	PrintTreePostOrderHelper(root, 0);
}