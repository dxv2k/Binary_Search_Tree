#include <iostream> 
using namespace std;
struct Node
{
    int info;
    Node *pRight;
    Node *pLeft;
};
Node *CreateNode(int num);
Node *Insert(Node *Root, int num);
void getInput(Node *&Root);
void LNR(Node *Root);
bool isPrime(int num); 
int main()
{
    Node *Root = NULL;
    getInput(Root);
    LNR(Root); 
    cout << endl; 
    system("pause");
}
 
void LNR(Node *Root)
{
    if (Root != NULL)
    {
        LNR(Root->pLeft);
        if (isPrime(Root -> info) == true)
            cout << Root->info << " ";
        LNR(Root->pRight);
    }
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
bool isPrime(int num)
{
    if (num < 2) return false; 
    else if (num > 2)
    {
        for (int i = 2; i <= num / 2; i++)
            if (num % i == 0) 
                    return false;
    }
    return true; 
}
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
