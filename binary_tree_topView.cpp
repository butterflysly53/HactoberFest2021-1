//this is a C++ program to print top view of binary tree

#include <bits/stdc++.h>
using namespace std;

// structure of binary tree
struct Node {
	Node* left;
	Node* right;
	int hd;
	int data;
};

// function to create a new node
Node* newNode(int key)
{
	Node* node = new Node();
	node->left = node->right = NULL;
	node->data = key;
	return node;
}

// function to print the topView of the binary tree
void topview(Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> q;
	map<int, int> m;
	int hd = 0;
	root->hd = hd;

	// push node and horizontal distance to queue
	q.push(root);
	cout << "Top view of the tree is : \n";
	while (q.size()) {
		hd = root->hd;

		// count function returns 1 if the container
		// contains an element whose key is equivalent to hd, or returns zero otherwise.
		if (m.count(hd) == 0)
			m[hd] = root->data;
		if (root->left) {
			root->left->hd = hd - 1;
			q.push(root->left);
		}
		if (root->right) {
			root->right->hd = hd + 1;
			q.push(root->right);
		}
		q.pop();
		root = q.front();
	}

	for (auto i = m.begin(); i != m.end(); i++) {
		cout << i->second << " ";
	}
}

int main()
{
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left= newNode(6);
	root->right->right= newNode(7);
	topview(root);
	return 0;
}

