#include<iostream>

using namespace std;

int partition(int *a, int m, int n)
{
    int i,j,pindex,pivot;
    pindex = m;
    pivot = a[n];
    for(i=m;i<n;i++)
    {
        if(a[i] <= pivot)
        {
            swap(a[pindex], a[i]);
            pindex++;
        }
    }
    swap(a[pindex], a[n]);
    return pindex;
}

int quicksort(int *a, int m, int n)
{
    int index;
    if(m>=n)
        return 0;
    {
        index = partition(a,m,n);
        quicksort(a, m, index-1);
        quicksort(a, index+1, n);
    }
}

int main()
{
    int a[] = {7,2,1,6,8,5,3,4};
    int i;
    quicksort(a,0,7);
    cout <<"After Sorting" << endl;
    for(i=0;i<8;i++)
        cout <<a[i] <<endl;
}