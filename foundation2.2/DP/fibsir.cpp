import java.util.*;

public class dp {
    public static int Fib(int n){
        if(n == 0 || n == 1){
            return n;
        }

        int fnm1 = Fib(n - 1);
        int fnm2 = Fib(n - 2);
        int fn = fnm1 + fnm2;

        return fn;
    }

    public static int FibM(int n, int[] qb){
        if(n == 0 || n == 1){
            return n;
        } 

        if(qb[n] != 0){
            return qb[n];
        }

        int fnm1 = FibM(n - 1, qb);
        int fnm2 = FibM(n - 2, qb);
        int fn = fnm1 + fnm2;

        qb[n] = fn;
        return fn;
    }

    public static int climbDownStairs(int n, int[] qb){
        if(n == 0){
            return 1;
        } else if(n < 0){
            return 0;
        } else if(qb[n] != 0) {
            return qb[n];
        }

        int pnm1 = climbDownStairs(n - 1, qb);
        int pnm2 = climbDownStairs(n - 2, qb);
        int pnm3 = climbDownStairs(n - 3, qb);
        int pn = pnm1 + pnm2 + pnm3;

        qb[n] = pn;
        return pn;
    }

    public static int countPaths(int[] arr){
        int[] strg = new int[arr.length];

        strg[strg.length - 1] = 1;
        for(int i = strg.length - 2; i >= 0; i--){
            for(int j = i + 1; j <= i + arr[i] && 
                               j < arr.length; j++){
                strg[i] += strg[j];
            }
        }

        return strg[0];
    }


    public static int minsteps(int[] arr){
        int[] strg = new int[arr.length];

        strg[strg.length - 1] = 0;
        for(int i = strg.length - 2; i >= 0; i--){
            int min = arr.length;

            for(int j = i + 1; j <= i + arr[i] && 
                            j < arr.length; j++){
                if(strg[j] < min){
                    min = strg[j];
                }
            }

            strg[i] = min + 1;
        }

        return strg[0];
    }

    public static void main(String[] args){
        int n = 40;

        long start = System.currentTimeMillis();
        int[] qb = new int[n + 1];
        // int fn = FibM(n, qb);
        // int res = climbDownStairs(n, qb);
        int[] arr = {4, 2, 0, 0, 2, 4, 6, 3, 1, 0, 1, 2, 3, 1, 1};
        int res = minsteps(arr);
        long end = System.currentTimeMillis();
        long duration = end - start;

        System.out.println(res + " in " + duration + " ms");
    }
}


