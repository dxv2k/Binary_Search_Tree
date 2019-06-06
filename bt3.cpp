#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;
struct Node
{
	int info;
	Node *pRight;
	Node *pLeft;
};
Node *CreateNode(int num)
{
	Node *p;
	p = new Node;
	if (p == NULL)
		exit(1);
	p->pRight = NULL;
	p->pLeft = NULL;
	p->info = num;
	return p;
}
Node *Insert(Node *Root, int num)
{
	if (Root == NULL)
		return CreateNode(num);
	else if (num < Root->info)
		Root->pLeft = Insert(Root->pLeft, num);
	else if (num > Root->info)
		Root->pRight = Insert(Root->pRight, num);
	return Root;
}

void getInput(Node *&Root);
int getHeight(Node *Root);
void printLevel(Node *Root, int Height); 
std::vector<int> v; 
int main()
{
	Node *Root = NULL;
	getInput(Root);
	int k; 
	cin >> k; 

	for (int i = k + 1; i <= getHeight(Root); i++)
		printLevel(Root, i);

	sort(v.begin, v.end()); 
	
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " "; 
	cout << endl; 
	system("pause");
}
void printLevel(Node *Root, int Height)
{
	if (Root == NULL)
		return;
	if (Height == 1)
		v.push_back(Root->info);
	else if (Height > 1)
	{
		printLevel(Root->pLeft, Height - 1);
		printLevel(Root->pRight, Height - 1);
	}
}
int getHeight(Node *Root)
{
	if (Root == NULL)
		return 0;
	int left_height = getHeight(Root->pLeft);
	int right_height = getHeight(Root->pRight);
	return 1 + max(left_height, right_height);
}
void getInput(Node *&Root)
{
	int input;
	cin >> input;
	while (input != -1)
	{
		if (Root == NULL)
			Root = Insert(Root, input);
		else if (Root != NULL)
			Insert(Root, input);
		cin >> input;
	}
}
