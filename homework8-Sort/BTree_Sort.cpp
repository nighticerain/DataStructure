#include <iostream>
using namespace std;

//-------------------------------------------------------------------
// Analysis
//-------------------------------------------------------------------
/** 二叉树排序
 * 二叉排序树建立的过程即为二叉排序
 * 时间复杂度为O(n*log2(n))
 * 空间复杂度为O(n) */

typedef struct Node* Tnode;
struct Node
{
    int data;
    Tnode left, right;
};


Tnode Insert_tree(Tnode T, int i);

Tnode Btree_sort(int a[], int n)
{
    int i=a[0];
    Tnode T;
    T = new Node;
    T->data = i;
    T->left = nullptr;
    T->right = nullptr;
    for(i=1;i<n;i++)
        T = Insert_tree(T,a[i]);
    return T;
}

Tnode Insert_tree(Tnode T, int i)
{
    if(T)
    {
        if(i<T->data)
            T->left = Insert_tree(T->left, i);
        else
            T->right = Insert_tree(T->right,i);
    }
    else
    {
        T = new Node;
        T->data = i;
        T->left = nullptr;
        T->right = nullptr;
        return T;
    }
    return T;
}

void tree_display(Tnode T)
{
    if(T)
    {
        tree_display(T->left);
        cout<<T->data<<" ";
        tree_display(T->right);
    }
}

void display(int a[], int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}


int main()
{
    int a[12]={41,62,13,84,35,96,57,39,79,61,15,83};
    cout<<"Before sort: ";
    display(a,12);
    Tnode T=Btree_sort(a,12);
    cout<<endl<<"After  sort: ";
    tree_display(T);
    int mypause;
    cin>>mypause;
    return(0);
}