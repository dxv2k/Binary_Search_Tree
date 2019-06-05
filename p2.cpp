#include <iostream>
using namespace std;
// Binary Search Tree

struct Node 
{
    int data;
    Node *pLeft;
    Node *pRight;
};
Node *CreateNode(int info); 
Node *Insert(Node *Root, int Num);

void print_InOrder(Node *Root); 
void getInput(Node *&Root);

int main()
{
    Node *Root = NULL; 
    getInput(Root);
    print_InOrder(Root);  
    cout << endl;
    system("pause"); 
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
        else if (Root -> data!= NULL)
            Insert(Root,num);
    }
}
void print_InOrder(Node *Root)
{
    // Use recursive 
    if (Root != NULL)
    { 
        print_InOrder(Root -> pLeft); 
        if (Root -> pLeft != NULL && Root -> pRight != NULL)
            cout << "2" << " ";
        else if (Root -> pLeft == NULL 
                        && Root -> pRight == NULL)
            cout << "0" << " "; 
        else if (Root -> pLeft == NULL 
                        || Root -> pRight == NULL)
            cout << "1" << " ";
        print_InOrder(Root -> pRight); 
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