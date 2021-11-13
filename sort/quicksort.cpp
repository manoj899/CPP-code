import java.util.*;

public class qs
{
    static int partition(int[] arr, int lo, int hi)
    {
        int i = lo;
        int j = lo;

        // lo to i - 1, i to j - 1, j to hi
        while(j <= hi)
        {
            if(arr[j] > arr[hi])
            {
                j++;
            }
            else
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j++;
            }
        }

        return i - 1;
    }

    static void quicksort(int[] arr, int lo, int hi)
    {
        if(lo >= hi)
        {
            return;
        }
        int pi = partition(arr, lo, hi);
        quicksort(arr, lo, pi - 1); // small
        quicksort(arr, pi + 1, hi); // big
    }

    public static void main(String[] args)
    {
        int[] arr = {2, 9, 4, 1, 6, 8, 3, 5};
        quicksort(arr, 0, arr.length - 1);
        for(int val: arr)
        {
            System.out.println(val);
        }
    }
}