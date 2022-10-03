#include <bits/stdc++.h>
using namespace std;
const int RUN = 32;

// This function sorts array from left index to
// to right index which is of size atmost RUN
void insertionSort(int a[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= l && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

// Merge function merges the sorted runs
void merge(int a[], int l, int m, int r)
{

    // Original array is broken in two parts
    // left and right array
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = a[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = a[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    // After comparing, we
    // merge those two array
    // in larger sub array
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left, if any
    while (i < len1)
    {
        a[k] = left[i];
        k++;
        i++;
    }

    // Copy remaining element of right, if any
    while (j < len2)
    {
        a[k] = right[j];
        k++;
        j++;
    }
}

// Iterative Timsort function to sort the
// array[0...n-1] (similar to merge sort)
void timSort(int a[], int n)
{

    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i += RUN)
        insertionSort(a, i, min((i + RUN - 1), (n - 1)));

    // Start merging from size RUN (or 32).
    // It will merge
    // to form size 64, then 128, 256
    // and so on ....
    for (int size = RUN; size < n;
         size = 2 * size)
    {

        // pick starting point of
        // left sub array. We
        // are going to merge
        // arr[left..left+size-1]
        // and arr[left+size, left+2*size-1]
        // After every merge, we
        // increase left by 2*size
        for (int left = 0; left < n;
             left += 2 * size)
        {

            // find ending point of
            // left sub array
            // mid+1 is starting point
            // of right sub array
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1),
                            (n - 1));

            // merge sub array arr[left.....mid] &
            // arr[mid+1....right]
            if (mid < right)
                merge(a, left, mid, right);
        }
    }
}

// Utility function to print the Array
void printAr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}

// Driver program to test above function
int main()
{
    int a[] = {-2, 7, 15, -14, 0, 15, 0, 7, -7,
               -4, -13, 5, 8, -14, 12};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Given Array is\n");
    printAr(a, n);

    // Function Call
    timSort(a, n);

    printf("After Sorting Array is\n");
    printAr(a, n);
    return 0;
}