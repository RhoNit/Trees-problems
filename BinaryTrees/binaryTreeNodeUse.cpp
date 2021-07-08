#include <bits/stdc++.h>
#include "binaryTreeNode.h"
using namespace std;

BinaryTreeNode<int> * takeInputs() {
	int rootData;
	cout << "Enter the data:\n";
	cin >> rootData;

	if(rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int> *node = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int> *leftNode = takeInputs();
	BinaryTreeNode<int> *rightNode = takeInputs();

	node->left = leftNode;
	node->right = rightNode;

	return node;
}

void printTree(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return;
	}

	cout << root->data << ":";

	if(root->left != NULL) {
		cout << "L->" << root->left->data;
	}
	if(root->right != NULL) {
		cout << " R->" << root->right->data;
	}
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}

int main() {
	BinaryTreeNode<int> *root = takeInputs();
	printTree(root);

	return 0;
}