#include <iostream>
using namespace std;

//-------------------------------------------------------------------
// Analysis
//-------------------------------------------------------------------
/** 快速排序
 * 选取控制关键字和无序区其他元素关键字进行比较
 * 设置两个指示器，使得后端指示器j逐渐减小，前端指示器i逐渐增大，将控制关键字a[i]移到相应适宜的位置
 * 在对控制关键字分割的两个无序区进行分割，直到序列有序为止
 * 时间复杂度为O(n*log2(n))
 * 空间复杂度为O(log2(n))~O(n) */

void display(int a[], int n);

int quick_sort(int a[], int l, int h)
{
    int x = a[l];
    if(l>=h)
        return 0;
    int i=l,j=h;
    while(i<j)
    {
        while(i<j && a[j]>=x)
            j--;
        a[i] = a[j];
        while(i<j && a[i]<=x)
            i++;
        a[j] = a[i];
    }
    a[i] = x;
    quick_sort(a,l,i-1);
    quick_sort(a,i+1,h);
    return 0;
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
    quick_sort(a,0,11);
    cout<<endl<<"After  sort: ";
    display(a,12);
    int mypause;
    cin>>mypause;
    return(0);
}