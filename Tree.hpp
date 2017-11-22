#ifndef TREE_HPP
#define TREE_HPP

#include <iomanip>
#include <iostream>
using namespace std;

const char NaCH = '\0';
enum dir{LEFT, RIGHT};

typedef struct treeNode {
	treeNode(char _data, treeNode *_par = NULL,treeNode *_left = NULL, treeNode *_right = NULL) 
			: data(_data), par(_par), left(_left), right(_right) {}
	char data;
	treeNode *par;
	treeNode *left;
	treeNode *right;
}Node;

class Tree {	
public:
	Tree();
	bool insert(char parent, char iValue, dir d = LEFT);
	bool remove(char rValue);
	bool empty();
	void preOrder();
	void inOrder();
	void postOrder();
	void mirror();
	void clear();
	void print();
	~Tree();
private:
	Node *root;
	Node *searchNode(Node *subRoot, char value);
	void pre(Node *root);
	void in(Node *root);
	void post(Node *root);
	void mir(Node *root);
	void printTree(Node *subRoot, int totalSpaces);
	void removeSubtree(Node *subRoot);
};

#endif
