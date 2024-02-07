//Don Parker
//CPSC 300 Project 2
//Makes a binary search tree from a document of strings and allows searches in this tree.

#include<iostream>
#include<fstream>

using namespace std;

struct node
{
	string entry;
	node *leftChild;
	node *rightChild;
};

//Creates a node and adds it to a binary search tree.
void addNode(node *&root, string item)
{
	node *tmp_p = new node;
	tmp_p->entry = item;
	tmp_p->leftChild = NULL;
	tmp_p->rightChild = NULL;
	
	bool missingParent = true;
	
	if (root != NULL)
	{
		node *nodeParent = root;
		
		while(missingParent)
		{
	
			if (tmp_p->entry < nodeParent->entry )
			{
				if (nodeParent->leftChild == NULL)	
				{
					nodeParent->leftChild = tmp_p;
					missingParent = false;
				}
				if (nodeParent->leftChild != NULL)
				{
					nodeParent = nodeParent->leftChild;
				}
			}
			if (tmp_p->entry > nodeParent->entry )
			{
				if (nodeParent->rightChild == NULL)	
				{
					nodeParent->rightChild = tmp_p;
					missingParent = false;
					
				}
				if (nodeParent->rightChild != NULL)
				{
					nodeParent = nodeParent->rightChild;
				}
			}
		}
	}
	if (root == NULL)
	{
	root = tmp_p;
	}
}

//Searches for a string in a binary search tree and prints path.
void search(node *searchNode,string item)
{
	if (item == searchNode->entry)
	{
		cout << " ... found it\n";
		return;
	}
	if (item < searchNode->entry)
	{
		cout << "L";
		if (searchNode->leftChild != NULL)
		{
		search(searchNode->leftChild,item);
		return;
		}
	}
	if (item > searchNode->entry)
	{
		cout << "R";
		if (searchNode->rightChild != NULL)
		{
		search(searchNode->rightChild,item);
		return;
		}
	}
	
	cout << " ... not found\n";
}

//In-Order Traversal of tree.
void traverse(node *root)
{
	if (root == NULL)
	{
		return;
	}
	traverse(root->leftChild);
	cout << root->entry << endl;
	traverse(root->rightChild);
}

//Calculates height of binary search tree.
int treeHeight(node *root)
{
	if (root == NULL)
		{
			return 0;
		}	
	
	int left = treeHeight(root->leftChild);
	int right = treeHeight(root->rightChild);
	
	if (left > right)	
	{
		return left + 1;
	}
	else
	{
		return right + 1;
	}
}

int main()
{
	node *root = NULL;
	ifstream input;
	string item;
	string searchItem;
	
	input.open("strings.txt");

	if (input.fail())
	{
		cout << "Couldn't open file\n";
		exit(1);	
	}
	
	cout << "Reading from file 'strings' ...\n";
	while (input >> item)
	{
		addNode(root,item);
	}
	
	//traverse(root);
	cout << "Tree Height = " << (treeHeight(root) - 1) << endl;
	
	while (true)
	{
		
		cout << "Enter a string: ";
		cin >> searchItem;
		
		if (searchItem == "STOP")
		{
			cout << "bye\n";
			break;
		}
		else
		{
		cout << "search path: ";
		search(root,searchItem);
		}	
	}
	
	return 0;
}
