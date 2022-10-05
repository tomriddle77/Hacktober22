public class SelectionSort
{
    int[] selectionSort(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n-1; i++)
        {
            // Find the minimum element in unsorted array
            int min = i;
            for (int j = i+1; j < n; j++)
            {
                if (arr[j] < arr[min])
                    min = j;
            }
            // Swap the minimum element with the first element
            int t = arr[min];
            arr[min] = arr[i];
            arr[i] = t;
            
        }
        return arr;
    }
 
    void print(int arr[])
    {
        for (int i=0; i<arr.length; i++)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
 
    public static void main(String args[])
    {
        SelectionSort ob = new SelectionSort();
        int arr[] = {9, 3, 5, 1, 7};
        arr=ob.selectionSort(arr);
        System.out.println("Sorted array");
        ob.print(arr);
    }
}