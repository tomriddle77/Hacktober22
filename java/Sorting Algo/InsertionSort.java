public class InsertionSort 
{
    
    int[] insertionSort(int arr[])
    {
        int n = arr.length;
        for (int i = 1; i < n; ++i) 
        {
            int t = arr[i];
            int j = i - 1;
            /*Moving elements of arr that are greater than t to a position 
            before the present position */
            while (j >= 0 && arr[j] > t) 
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = t;
        }
        return arr;
    }
  
    void print(int arr[])
    {
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
  
    public static void main(String args[])
    {
        int arr[] = { 9, 3, 6, 1, 7 };
        InsertionSort ob = new InsertionSort();
        arr=ob.insertionSort(arr);
        System.out.println("Sorted array");
        ob.print(arr);
    }
}