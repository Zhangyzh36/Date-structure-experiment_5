#include "Tree.hpp"

void instruction();
void insertNode();
void removeNode();
void mirrorFlip();
void show();
void preOrder();
void inOrder();
void postOrder();
void clearTree();


Tree t;

int main()
{
	instruction();
	bool flag = true;
	int command;
	while (flag) 
	{
		cout << "Tree $ ";
		cin >> command;

		switch(command)
		{
			case 0:
				flag = false;
				break;
			case 1:
				insertNode();
				break;
			case 2:
				removeNode();
				break;
			case 3:
				mirrorFlip();
				break;
			case 4:
				show();
				break;
			case 5:
				preOrder();
				break;
			case 6:
				inOrder();
				break;
			case 7:
				postOrder();
				break;
			case 8:
				clearTree();
				break;
			case 9:
				instruction();
				break;
			default:
				break;
		}

	}

	return 0;
}

void instruction()
{
	cout << endl;
	cout << "******************************************" << endl
		 << "Please enter" << endl
		 << "  [1]  insert a node" << endl
		 << "  [2]  remove a node" << endl
		 << "  [3]  mirror flip" << endl
		 << "  [4]  show" << endl
		 << "  [5]  preorder" << endl
		 << "  [6]  inorder" << endl
		 << "  [7]  postorder" << endl
		 << "  [8]  clear" << endl
		 << "  [9]  show menu" << endl
		 << "  [0]  exit" << endl
		 << "******************************************" << endl << endl;
}

void insertNode()
{
	char parent;
	char insert;
	char dir;
	if (!t.empty())
	{
		cout << "Please enter the parent of the node to be inserted $ ";
		cin >> parent;
	}

	cout << "Please enter the value of the node to be inserted $ ";
	cin >> insert;

	if (t.empty())
	{
		t.insert(NaCH, insert);
		cout << insert << " has been inserted to the tree succeesfully." << endl << endl;
	}
	else 
	{
		cout << "Which side do you want to insert the node(left or right)<l/r> $ ";
		cin >> dir;
		if (dir == 'l' || dir == 'L')
		{
			if (t.insert(parent, insert, LEFT))
				cout << insert << " has been inserted to the tree succeesfully." << endl << endl;
			else
				cout << "Insertion failed, parent does not exist or it is occupied." << endl << endl;
		}
		else if (dir == 'r' || dir == 'R')
		{
			if (t.insert(parent, insert, RIGHT))
				cout << insert << " has been inserted to the tree succeesfully." << endl << endl;
			else
				cout << "Insertion failed, parent does not exist or it is occupied." << endl << endl;
		}
	}

}

void removeNode()
{
	 char rm;
	 cout << "Please enter the node you want to remove $ ";
	 cin >> rm;
	 if (t.remove(rm))
	 	cout << rm << " has been removed from the tree succeesfully." << endl << endl;
	 else
	 	cout << "Removal failes, the node does not exist." << endl << endl;

}

void mirrorFlip()
{
	t.mirror();
	cout << "The tree has been mirror fliped." << endl << endl;
}

void show()
{
	t.print();
	cout << endl;
}

void preOrder()
{
	t.preOrder();
	cout << endl << endl;
}

void inOrder()
{
	t.inOrder();
	cout << endl << endl;
}

void postOrder()
{
	t.postOrder();
	cout << endl << endl;
}

void clearTree()
{
	t.clear();
	cout << "The tree has been cleared succeesfully." << endl << endl;
}