#include <iostream>
#include <math.h>
using namespace std;

//-------------------------------------------------------------------
// Analysis
//-------------------------------------------------------------------
/** 线性插入排序
 * 在有序区进行顺序查找，以确定插入的位置
 * 比较次数和移动次数与序列中关键字的原始排列情况有关
 * 时间复杂度为O(n^2) 
 * 空间复杂度为O(1) */

void insert_sort(int a[], int n)
{
    for(int i=2;i<n;i++)
    {
        a[0]=a[i];
        int j=i-1;
        while(a[0]<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = a[0];
    }
}

//-------------------------------------------------------------------
// Analysis
//-------------------------------------------------------------------
/** 对半插入排序
 * 在插入排序的基础上，使用对分查找在有序区确定插入的位置
 * 时间复杂度为O(n^2) 
 * 空间复杂度为O(1) */

void bin_sort(int a[], int n)
{
    for(int i=2;i<n;i++)
    {
        a[0]=a[i];
        int l=1,h=i-1;
        while(l<=h)
        {
            int m =floor((l+h)/2);
            if(a[0]<a[m])
                h = m-1;
            else
                l = m+1;
        }
        for(int j=i-1;j>=l;j--)
            a[j+1]=a[j];
        a[l]=a[0];
    }
}


void display(int a[], int n)
{
    for(int i=1;i<n;i++)
        cout<<a[i]<<" ";
}


int main()
{
    int a[13]={0,41,62,13,84,35,96,57,39,79,61,15,83};
    int b[13]={0,41,62,13,84,35,96,57,39,79,61,15,83};
    cout<<"Before sort: ";
    display(a,13);
    insert_sort(a,13);
    cout<<endl<<"After Insert sort: ";
    display(a,13);
    
    cout<<endl<<endl<<"Before sort: ";
    display(b,13);
    bin_sort(b,13);
    cout<<endl<<"After Bin sort: ";
    display(b,13);
    int mypause;
    cin>>mypause;
    return(0);
}