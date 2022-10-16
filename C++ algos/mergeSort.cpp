#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // temp left and right sub-arrays
    int L[n1], R[n2];

    // copy data to temp arrays L[] and R[]
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // sort and merge the two arrays back
    i = j = 0;
    k = l;

    while(i < n1 && j < n2)
    {
        if(L[i]<=R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements of L[], if there any
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy the remaining elements of R[], if there any
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) cin>>arr[i];

    cout << "Given array is: " << endl;
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, n-1);

    cout << "Sorted array is: " << endl;
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}