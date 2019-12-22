#include <iostream>
using namespace std;

//-------------------------------------------------------------------
// Analysis
//-------------------------------------------------------------------
/** 简单选择排序
 * 由两重循环构成，外循环共进行n-1趟排序，内循环通过n-i次比较寻找到最大/小值及其索引
 * 共比较n(n-1)/2次，
 * 时间复杂度为O(n^2) 
 * 空间复杂度为O(1) */

void choose_sort(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        int a_min = a[i],index = i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a_min)
            {
                a_min = a[j];
                index = j;
            }

        }

        if(index != i)
        {
            int temp = a[i];
            a[i] = a_min;
            a[index] = temp;
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
    choose_sort(a,12);
    cout<<endl<<"After  sort: ";
    display(a,12);
    int mypause;
    cin>>mypause;
    return(0);
}