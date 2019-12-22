#include <iostream>
using namespace std;

//-------------------------------------------------------------------
// Analysis
//-------------------------------------------------------------------
/** 冒泡排序
 * 最多共进行n-1次扫描，每次扫描发现相邻两个记录逆序就交换
 * 每一次扫描会使无序部分的最大值沉底，较小值上浮
 * 时间复杂度为O(n^2) 
 * 空间复杂度为O(1) */

void bubble_sort(int a[], int n)
{
    int F=n-1;
    while(F>0)
    {
        int k=F-1; F=0;
        for(int j=0;j<=k;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                F = j;
            }
        }
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
    bubble_sort(a,12);
    cout<<endl<<"After  sort: ";
    display(a,12);
    int mypause;
    cin>>mypause;
    return(0);
}