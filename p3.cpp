#include <iostream>
using namespace std;
// Binary Search Tree

struct Node 
{
    int data;
    int level; 
    Node *pLeft;
    Node *pRight;
};
Node *CreateNode(int info); 
Node *Insert(Node *Root, int Num);
void getInput(Node *&Root);
void printLevel(Node *Root); 
int main()
{ 
    Node *Root = NULL; 
    getInput(Root); 
    printLevel(Root); 
    system("pause"); 
}
int lv = 0; 
void printLevel(Node *Root)
{
    // Left -> Node -> Right
    if(Root != NULL)
    { 
        lv++; 
        printLevel(Root -> pLeft); 
        cout << lv-1 << " ";
        printLevel(Root -> pRight); 
        lv--;
    }
}
Node *Insert(Node *Root, int Num)
{
    // 3 case:
    // 1st, there is no root 
    if (Root == NULL)
        return CreateNode(Num); 
    // 2nd, Num < Root => Num on pLeft
    if (Num < Root -> data)
        Root -> pLeft = Insert(Root -> pLeft, Num); 
    // 3rd, Num > Root => Num on pRight
    if (Num > Root -> data)
        Root -> pRight = Insert(Root -> pRight, Num);        
    return Root; 
}
Node *CreateNode(int info)
{ 
    Node *p = new Node;
    if (p == NULL)
        exit(1); // means can't create new node 
    p -> data = info;
    p -> pLeft = NULL; 
    p -> pRight = NULL; 
    return p;    
}
void getInput(Node *&Root)
{ 
    int n; 
    cin >> n;
    
    int num; 
    for (int i = 0; i < n; i++)
    {
        cin >> num; 
        if (Root == NULL)
            Root = Insert(Root,num); 
        else if (Root != NULL)
            Insert(Root,num);
    }
}