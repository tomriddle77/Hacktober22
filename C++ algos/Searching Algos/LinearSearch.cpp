#include <iostream>
using namespace std;


//The given code searches for an element, if found, returns the index of the element else returns -1 (Element not found)
int search(int arr[], int N, int x)
{
    for (int i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 
// Driver's code
int main(void)
{
    //Declaration of a sample array for demonstration
    int arr[] = { 2, 3, 4, 10, 40 };
    int x;
    cout<<"Enter the element to be searched in array : "; 
    cin>>x;
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    int result = search(arr, N, x);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}
