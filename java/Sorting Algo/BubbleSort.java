public class BubbleSort 
{
    int[] bubbleSort(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1]) 
                {
                    // swapping arr[j+1] and arr[j]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
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
        BubbleSort ob = new BubbleSort();
        int arr[] = { 9, 4, 2, 7, 5 };
        arr=ob.bubbleSort(arr);
        System.out.println("Sorted array:");
        ob.print(arr);
    }
}