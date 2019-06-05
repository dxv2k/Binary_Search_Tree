	#include <iostream> 
using namespace std; 
struct Node
{
        int data; 
        Node *pLeft; 
        Node *pRight; 
};
Node *CreateNode(int info);
Node *Insert(Node *Root, int Num);
void InOrder(Node *Root); // Left -> Node -> Right 
/*
    Keep in mind, if asked to print BST with increase order
    => Use Left -> Node -> Right to print min -> max
    => Use right -> Node -> Left to print max -> min 
    And vice versa.
*/
void PostOrder(Node *Root); 
bool Find_X(Node *Root, int x); 

int CountLeaf(Node *Root); // Leaf is count when there are no branches
int CountNode(Node *Root);
int CountNode_w_Branches(Node *Root); // Count Node with Branches 
void CountNode_2Branches(Node *Root,int &cnt); 
int Find_Max(Node *Root); 
void CountNode_Even(Node *Root,int &cnt);

int getHeight(Node *Root);  

/*----------2 function below use to print BST----------*/
Node* printTree(Node *Root); 
void printLevel(Node *Root, int Height); 
/*-----------------------------------------------------*/

// Extra 
void Node_wLeftBranch(Node *Root,int &cnt);
void Node_w1Branch(Node *Root,int &cnt); 

int main()
{ 
    /*-----------------------------------------------*/
    /* Test case with the BST below
            50 (Root)
        /       \
        30      70
    /       \        \
    20      40        80   
    */
    Node *Root = NULL; 
    Root = Insert(Root,50);
    Insert(Root,30);
    Insert(Root,70); 
    Insert(Root,20); 
    Insert(Root,40);
    Insert(Root,80);   
    /*-----------------------------------------------*/
    printLevel(Root); 
    cout << endl;
    
    system("pause"); 
}
void Node_wLeftBranch(Node *Root,int &cnt)
{ 

}
void Node_w1Branch(Node *Root,int &cnt)
{
    
}
int Find_Max(Node* Root)
{
	Node *Search; 
	while (Search -> pRight != NULL)
	{
		Search = Search -> pRight; 
	}
	return Search -> data; 
}
Node* printTree(Node *Root)
{ 
   int h = getHeight(Root); 
   for (int i = 1; i <= h; i++)
   { 
        printLevel(Root,i); 
        cout << endl; 
   }
}
void printLevel(Node *Root, int Height)
{ 
    if (Root == NULL)
        return;    
    if (Height == 1 )
        cout << Root -> data << " "; 
    else if (Height > 1)
    { 
        printLevel(Root -> pLeft,Height - 1); 
        printLevel(Root -> pRight,Height - 1); 
    }
}
int getHeight(Node *Root)
{
    if (Root == NULL)
        return 0; 
    int left_height = getHeight(Root -> pLeft);
    int right_height = getHeight(Root -> pRight); 
    return 1 + max(left_height,right_height); 
}   
void CountNode_Even(Node *Root,int &cnt) 
{ 
    if (Root){
        CountNode_Even(Root -> pLeft,cnt); 
        if (Root -> data % 2 == 0)
            cnt++; 
        CountNode_Even(Root -> pRight,cnt); 
    }
}
void CountNode_2Branches(Node *Root,int &cnt)
{ 
    if (Root)
    { 
        CountNode_2Branches(Root -> pLeft,cnt);
        if (Root -> pLeft != NULL && 
                Root -> pRight != NULL)
            cnt++;
        CountNode_2Branches(Root -> pRight,cnt); 
    }
}
int CountNode(Node *Root)
{ 
    int cnt = 1; // count 
    if (Root != NULL)
    { 
        if (Root -> pLeft != NULL)
            cnt += CountNode(Root -> pLeft); 
        if (Root -> pRight != NULL)
            cnt += CountNode(Root -> pRight); 
    }
    return cnt;
}
int CountLeaf(Node *Root)
{
    // //Leaf is count when there are no branches 
    // int cnt = 0; 
    // if (Root != NULL)
    // { 
    //     if (Root -> pLeft == NULL && Root -> pRight == NULL)
    //         cnt++; 
    //     CountLeaf(Root -> pLeft); 
    //     CountLeaf(Root -> pRight); 
    // }  
    // return cnt;
    if (Root == NULL) return 0; 
    if (Root -> pLeft == NULL && Root -> pRight == NULL)
                    return 1; 
    return CountLeaf(Root -> pLeft) + CountLeaf(Root -> pRight);  
}
bool Find_X(Node *Root, int x)
{
    // if x < Root -> move to  left
    /*if (x < Root -> data)
    { 
        return Find_X(Root -> pLeft,x); 
    }
    // if x > Root -> move to right 
    if (x > Root -> data)
    {
        return Find_X(Root -> pRight,x);
    }
    // x == Root -> return 
    if (x == Root -> data)
        return true; 
    return false;*/
   while (Root != NULL)
   { 
        if (x < Root -> data)
            Root = Root -> pLeft; 
        else if (x > Root -> data)
            Root = Root -> pRight; 
        else if (x == Root -> data) 
            return true; 
   }
   return false;
} 
void InOrder(Node *Root)
{
    // Using recursive 
    if (Root != NULL)
    { 
        InOrder(Root -> pLeft);
            cout << Root -> data << " ";
        InOrder(Root -> pRight);
    }
}
void PostOrder(Node *Root)
{ 
    // Using recursive 
    if (Root != NULL)
    { 
        PostOrder(Root -> pRight); 
            cout << Root -> data << " ";
        PostOrder(Root -> pLeft); 
    }
}
Node *Insert(Node *Root, int Num)
{
    // 3 case: 
    // 1st case, there is no root
    if (Root == NULL)
        return CreateNode(Num);
    // 2nd case, Num < Root => Num on pLeft 
    if (Num < Root -> data)
        Root -> pLeft = Insert(Root -> pLeft, Num); 
    // 3rd case, Num > Root => Num on pRight 
    else if (Num > Root -> data)
        Root -> pRight = Insert(Root -> pRight, Num); 
    return Root;  
}
Node *CreateNode(int info) 
{ 
    Node *p = new Node; 
    if (p == NULL) 
    {
        cout << "Error: Can't create new Node " << endl;
        exit(1); 
    }
    p -> data = info; 
    p -> pLeft = NULL; 
    p -> pRight = NULL; 
    return p; 
}
