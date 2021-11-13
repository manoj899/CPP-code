import java.util.*;

public class tns{

    static int invCount = 0;
    static int[] merge2sortedarrays(int[] one, int[] two){
        int[] res = new int[one.length + two.length];
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < one.length && j < two.length){
            if(one[i] < two[j]){
                res[k++] = one[i++];
            } else {
                res[k++] = two[j++];
                invCount += one.length - i;
            }
        }

        while(i < one.length){
            res[k++] = one[i++];
        }

        while(j < two.length){
            res[k++] = two[j++];
        }

        return res;
    }


    static int[] mergesort(int[] arr, int lo, int hi){
        if(lo == hi){
            int[] ba = new int[1];
            ba[0] = arr[lo];
            return ba;
        }
        int mid = (lo + hi) / 2;
        int[] fh = mergesort(arr, lo, mid);
        int[] sh = mergesort(arr, mid + 1, hi);
        int[] fsa = merge2sortedarrays(fh, sh);
        return fsa;
    }

    static int binarySearch(int[] arr, int data){
        int lo = 0;
        int hi = arr.length - 1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(data == arr[mid]){
                return mid;
            } else if(data > arr[mid]){
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        return -1;
    }

    void printss(String str, int idx, String ans){
        if(str.length() == idx){
            System.out.println(ans);
            return;
        }

        char ch = str.charAt(idx);
        // String ros = str.substring(1);
        printss(str, idx + 1, ans);
        printss(str, idx + 1, ans + ch);
    }

    static int Fib(int n){
        if(n == 0 || n == 1){
            return 1;
        }
        return Fib(n - 1) + Fib(n - 2);
    }

    static void poly(int x, int n)
    {
        int co = n;
        int px = x;
        int sum = 0;

        while(co >= 1)
        {
            sum += co * px;
            px = px * x;
            co--;
        }

        System.out.println(sum);
    }

    static void soe(int n){
        // print all primes till n
        boolean[] primes = new boolean[n + 1];
        Arrays.fill(primes, true);

        primes[0] = false;
        primes[1] = false;

        for(int i = 2; i * i <= n; i++)
        {
            if(primes[i] == true)
            {
                for(int j = i; i * j <= n; j++)
                {
                    primes[i * j] = false;
                }
            }
        }        

        for(int i = 0; i < primes.length; i++)
        {
            if(primes[i] == true)
            {
                System.out.println(i);
            }
        }
    }

    static int[] getspf(int n){
        int[] res = new int[n + 1];

        boolean[] primes = new boolean[n + 1];
        Arrays.fill(primes, true);
        for(int i = 0; i < res.length; i++){
            res[i] = i;
        }

        primes[0] = false;
        primes[1] = false;

        for(int i = 2; i * i <= n; i++)
        {
            if(primes[i] == true)
            {
                for(int j = i; i * j <= n; j++)
                {
                    if(primes[i * j] == true){
                        primes[i * j] = false;
                        res[i * j] = i;
                    }
                }
            }
        }

        return res;
    }

    static void factorization(int[] spf, int x){
        System.out.print(x + " = ");
        while(x > 1){
            System.out.print(spf[x] + " * ");
            x = x / spf[x];
        }
        System.out.println(1);
    }

    static void setABit(int x, int k){
        System.out.println(x + " = " + Integer.toBinaryString(x));
        int mask = 1 << k;
        System.out.println(mask + " = " + Integer.toBinaryString(mask));
        x = x | mask;
        System.out.println(x + " = " + Integer.toBinaryString(x));
    }

    static void unsetABit(int x, int k){
        System.out.println(x + " = " + Integer.toBinaryString(x));
        int mask = ~(1 << k);
        System.out.println(mask + " = " + Integer.toBinaryString(mask));
        x = x & mask;
        System.out.println(x + " = " + Integer.toBinaryString(x));
    }

    static void toggleABit(int x, int k){
        System.out.println(x + " = " + Integer.toBinaryString(x));
        int mask = 1 << k;
        System.out.println(mask + " = " + Integer.toBinaryString(mask));
        x = x ^ mask;
        System.out.println(x + " = " + Integer.toBinaryString(x));
    }

    static int counter = 0;
    static int countWaysToParty(ArrayList<Integer>[] pcmap, 
                                int pidx, int mask, int[][] strg){
        if(pidx == pcmap.length){
            return 1;
        }

        if(strg[pidx][mask] != 0){
            return strg[pidx][mask];
        }
        int count = 0;
        System.out.println(++counter + ". " + pidx + " " + mask);
        for(int cap: pcmap[pidx]){
            if((mask & (1 << cap)) == 0){
                mask = mask ^ (1 << cap);
                
                int cc = countWaysToParty(pcmap, pidx + 1, mask, strg);
                count += cc;

                mask = mask ^ (1 << cap);
            }
        }
        strg[pidx][mask] = count;
        return count;
    }

    public static void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void sort01(int[] arr){
        for(int i = 0, j = 0; i < arr.length; ){
            if(arr[i] == 1){
                i++;
            } else {
                swap(arr, i, j);
                i++;
                j++;
            }
        }

        System.out.println(Arrays.toString(arr));
    }

    public static void sort012(int[] arr){
        int i = 0;
        int j = 0;
        int k = arr.length - 1;

        while(i <= k){
            if(arr[i] == 1){
                i++;
            } else if(arr[i] == 0){
                swap(arr, i, j);
                i++;
                j++;
            } else if(arr[i] == 2){
                swap(arr, i, k);
                k--;
            }
        }

        System.out.println(Arrays.toString(arr));
    }

    public static int partitioning(int[] arr, int lo, int hi){
        int pivot = arr[hi];

        int j = lo;
        for(int i = lo; i <= hi; ){
            if(arr[i] <= pivot){
                swap(arr, i, j);
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j - 1;
    }

    public static int quickSelect(int[] arr, int lo, int hi, int k){
        int pi = partitioning(arr, lo, hi);
        if(k < pi){
            return quickSelect(arr, lo, pi - 1, k);
        } else if(k > pi){
            return quickSelect(arr, pi + 1, hi, k);
        } else {
            return arr[pi];
        }
    }

    public static void quickSort(int[] arr, int lo, int hi){
        if(lo >= hi){
            return;
        }

        int pi = partitioning(arr, lo, hi);
        quickSort(arr, lo, pi - 1);
        quickSort(arr, pi + 1, hi);
    }

    static int[] countSort(int[] input){
        int n = input.length;
        int r = 10;
        int[] fm = new int[r];

        for(int val: input){
            fm[val]++;
        }

        for(int i = 1; i < fm.length; i++){
            fm[i] += fm[i - 1];
        }

        int[] output = new int[n];
        for(int i = input.length - 1; i >= 0; i--){
            int val = input[i];
            fm[val]--;
            output[fm[val]] = val;
        }

        return output;
    }

    static int[] countSortForRS(int[] input, int div){
        int n = input.length;
        int r = 10;
        int[] fm = new int[r];

        for(int val: input){
            val = val / div % 10;
            fm[val]++;
        }

        for(int i = 1; i < fm.length; i++){
            fm[i] += fm[i - 1];
        }

        int[] output = new int[n];
        for(int i = input.length - 1; i >= 0; i--){
            int val = input[i];
            val = val / div % 10;
            fm[val]--;
            output[fm[val]] = input[i];
        }

        return output;
    }

    static int[] radixSort(int[] input){
        int max = 0;
        for(int val: input){
            max = Math.max(max, val);
        }

        int div = 1;
        while(max / div > 0){
            input = countSortForRS(input, div);
            div = div * 10;
        }

        return input;
    }

    static void hfc(String str){
        int[] fm = new int[26];
        int maxi = 0;
        for(char val: str.toCharArray()){
            fm[val - 'a']++;

            if(fm[val - 'a'] > fm[maxi]){
                maxi = val - 'a';
            }
        }

        System.out.println((char)(maxi + 'a'));
    }

    public static void main(String[] args){
        // int[] arr = {2, 9, 3, 4, 1, 6, 8, 0};
        // int[] sarr = mergesort(arr, 0, arr.length - 1);
        // System.out.println(Arrays.toString(sarr));
        // poly(2, 3);

        // soe(100);

        // int[] spf = getspf(100000);
        // factorization(sp, f, 360);
        // factorization(spf, 1000);
        // factorization(spf, 240);
        // factorization(spf, 144);

        // unsetABit(61, 4);
        // ArrayList<Integer>[] pcmap = new ArrayList[]{
        //     new ArrayList<>(Arrays.asList(0, 2, 4)),
        //     new ArrayList<>(Arrays.asList(0, 1, 2, 3)),
        //     new ArrayList<>(Arrays.asList(1, 2, 3)),
        //     new ArrayList<>(Arrays.asList(0, 4)),
        // };
        // int caps = 5;
        // int[][] strg = new int[pcmap.length][1 << caps];
        // System.out.println(countWaysToParty(pcmap, 0, 0, strg));

        // int[] arr = {1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1};
        // sort01(arr);
        // int[] arr = {2, 1, 0, 2, 2, 1, 1, 0, 0};
        // sort012(arr);

        // int[] arr = {259, 68, 347, 924, 1036, 425, 719, 88, 463, 527, 634, 725, 978};
        // int[] sa = radixSort(arr);
        // System.out.println(Arrays.toString(sa));

        hfc("aakljsdhfaksdhflkaskkkkkkdjf");

        // int[] arr = {20, 50, 10, 80, 60, 30, 70, 40}; // 1 2 3 4 5 6 7 8
        // quickSort(arr, 0, arr.length - 1);
        // System.out.println(Arrays.toString(arr));
        // for(int i = 1; i <= arr.length; i++){
        //     int j = i - 1;
        //     System.out.println(quickSelect(arr, 0, arr.length - 1, j));
        // }
        // int[] sarr = mergesort(arr, 0, arr.length - 1);
        // System.out.println(Arrays.toString(sarr));
        // System.out.println(invCount);
    }
}