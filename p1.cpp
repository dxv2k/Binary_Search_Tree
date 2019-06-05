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

int findMax(Node *Root);
void replaceNode(Node *a, Node *b); 
void print_InOrder(Node *Root); 
void delete_Node(Node *&Root, int val); 
void getInput(Node *Root);

int main()
{
    Node *Root = NULL; 
    getInput(Root); 
    cout << endl;
    system("pause"); 
}

void getInput(Node *Root)
{ 
    // While 
    // Input 1 -> AddNode in root
    // Input 2 -> Largest node will be deleted
    // Input -1 -> break program 
    // After -1 -> Print InOrder
    while (1)
    {
        int action, num; 
        cin >> action;
        if (action == 1)
        {
            cin >> num;
            if (Root == NULL)
                Root = Insert(Root,num);
            else if (Root -> data != NULL)
                Insert(Root,num); 
        }
        if (action == 2)
        {
            // Delete largest node 
            int LARGEST = findMax(Root); 
            delete_Node(Root,LARGEST); 
        }   
        if (action == -1)
            break; 
    }   
    print_InOrder(Root);

}
void delete_Node(Node *&Root,int val)
{
    // Find max first
    if (Root != NULL)
    {
        if (Root -> data < val)
            delete_Node(Root -> pRight, val); 
        else 
        {
            if (Root -> data > val)
                delete_Node(Root -> pLeft, val); 
            else
            {
                Node *temp;
                temp = Root;
                if (Root -> pLeft == NULL)
                    Root = Root -> pRight;
                else
                {
                    if (Root -> pRight == NULL)
                        Root = Root -> pLeft; 
                    else
                        replaceNode(temp, Root -> pLeft);
                    delete temp; 
                }
            }
        }
    }
}
void replaceNode(Node *a, Node *b)
{
    if (a -> pLeft != NULL)
        replaceNode(a, b -> pLeft);
    else 
    {
        a -> data = b -> data; 
        a = b;
        b = b -> pRight;
    }
}
int findMax(Node *Root)
{
    // Base case  
    if (Root == NULL)  
        return -1; 
    // Return maximum of 3 values:  
    // 1) Root's data 2) Max in Left Subtree  
    // 3) Max in right subtree  
    int res = Root->data;  
    int lres = findMax(Root->pLeft);  
    int rres = findMax(Root->pRight);  
    
    if (lres > res)  
    res = lres;  
    if (rres > res)  
    res = rres;  
    
    return res;  
}
void print_InOrder(Node *Root)
{
    // Use recursive 
    if (Root != NULL)
    { 
        print_InOrder(Root -> pLeft); 
        cout << Root -> data << " ";
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