#include <iostream>
#include <math.h> 
using namespace std;

//-------------------------------------------------------------------
// Analysis
//-------------------------------------------------------------------
/** 堆排序
 * 通过shift函数形成堆，堆顶为每次排序的最大元素
 * 堆顶最大元素出堆，与堆中最后一个元素交换，剩下的n-i个元素再次通过shift函数形成堆
 * 时间复杂度为O(n*log2(n)) 
 * 空间复杂度为O(1) */

void shift(int a[], int n, int k)
{
    int i=k, j=2*i+1;
    int T=a[i];
    while(j<n)
    {
        if(j<n-1 && a[j]<a[j+1])
            j++;
        if(T<a[j])
        {
            a[i] = a[j];
            i = j;
            j = 2*i+1;
        }
        else
        {
            break;
        }        
    }
    a[i] = T;
}

void heap_sort(int a[], int n)
{
    int p = floor(n/2)-1;
    for(int i=p; i>=0; i--)
        shift(a,n,i);
    for(int i=n-1; i>0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        shift(a,i-1,0);
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
    heap_sort(a,12);
    cout<<endl<<"After  sort: ";
    display(a,12);
    int mypause;
    cin>>mypause;
    return(0);
}