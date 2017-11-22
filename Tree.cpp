#include "Tree.hpp"

Tree::Tree()
{
	root = NULL;
}

bool Tree::insert(char parent, char iValue, dir d)
{
	if (!root && parent == NaCH)
	{
		root = new Node(iValue);
		return true;
	}

	Node *ptr = searchNode(root, parent);
	if (!ptr)
		return false;
	if (d == LEFT && ptr->left || d == RIGHT && ptr->right)
		return false;

	if (d == LEFT)
		ptr->left = new Node(iValue, ptr);
	else if (d == RIGHT)
		ptr->right = new Node(iValue, ptr);
	return true;
}

bool Tree::remove(char rValue)
{
	Node *ptr = searchNode(root, rValue);
	if (!ptr)
		return false;
	
	removeSubtree(ptr);
	return true;
}

bool Tree::empty()
{
	return root == NULL;
}

void Tree::preOrder()
{
	if (empty())
		cout << "empty tree";
	else
		pre(root);
}

void Tree::inOrder()
{
	if (empty())
		cout << "empty tree";
	else
		in(root);
}

void Tree::postOrder()
{
	if (empty())
		cout << "empty tree";
	else
		post(root);
}

void Tree::mirror()
{
	mir(root);
}

void Tree::clear()
{
	removeSubtree(root);
}

void Tree::print()
{
	if (empty())
		cout << "empty tree" << endl;
	else
		printTree(root, 1);
}

Tree::~Tree()
{
	clear();
}

Node * Tree::searchNode(Node *subRoot, char value)
{
	Node *parentOfValue = NULL;

	if (!subRoot)
		return NULL;
	if (subRoot->data == value)
		return subRoot;

	if (parentOfValue = searchNode(subRoot->left, value))
		return parentOfValue;
	if (parentOfValue = searchNode(subRoot->right, value))
		return parentOfValue;

	return NULL;
}

void Tree::pre(Node *root)
{
	if (root)
	{
		cout << root->data << " ";
		pre(root->left);
		pre(root->right);
	}
}

void Tree::in(Node *root)
{
	if (root)
	{	
		in(root->left);
		cout << root->data << " ";
		in(root->right);
	}
}

void Tree::post(Node *root)
{
	if (root)
	{
		post(root->left);
		post(root->right);
		cout << root->data << " ";
	}
}

void Tree::mir(Node *root)
{
	if (!root)
		return;

	Node *temp = root->left;
	root->left = root->right;
	root->right = temp;

	mir(root->left);
	mir(root->right);
}

void Tree::printTree(Node *subRoot, int totalSpaces)
{
	if (!subRoot)
		return;

	printTree(subRoot->right, totalSpaces + 5);

	for (int i = 0; i < totalSpaces; ++i)
		cout << " ";

	cout << subRoot->data << endl;

	printTree(subRoot->left, totalSpaces + 5);
}


void Tree::removeSubtree(Node *subRoot)
{
	if (!subRoot)
		return;

	removeSubtree(subRoot->left);
	removeSubtree(subRoot->right);

	Node *temp = subRoot;
	if (!subRoot->par)
	{
		delete temp;
		root = NULL;
	}
	else
	{
		if (subRoot->par->left == subRoot)
			subRoot->par->left = NULL;
		else
			subRoot->par->right = NULL;
		delete temp;
	}

}

