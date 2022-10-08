#include <bits/stdc++.h>
using namespace std;

// An iterative binary search function. It returns
// Location of x in given array arr[l..r] if present,
// Otherwise -1
// NOTE: BINARY SEARCH ONLY WORKS ON A SORTED ARRAY
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = (l + r) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // else if x greater, ignore left half
        else if (arr[m] < x)
            l = m + 1;

        // else if x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was not present in the Array, thus return -1
    return -1;
}

int main()
{
    // Sample declarationf of an array
    int arr[] = {2, 3, 4, 10, 40};
    int x;
    cout<<"Enter element to be searched : ";
    cin>>x;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
