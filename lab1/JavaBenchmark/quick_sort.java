import java.util.*;


public class quick_sort{

    static void quickSort(int a[], int l, int r){
        if(l >= r)
            return;
        int i = l, j = r, mid = a[(l + r) >> 1];
        while(i<=j){
            while(a[i] < mid) i++;
            while(a[j] > mid) j--;
            if(i<=j){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i++;
                j--;
            }
        }
        if(l < j) quickSort(a, l, j);
        if(i < r) quickSort(a, i, r);
    }

    public static void main(String[] args) {
        if(args.length != 1){
            System.err.println("Lack of parameters!");
            System.exit(-1);
        }
        int N = Integer.parseInt(args[0]);
        int[] a = new int[N];

        Random random = new Random();

        for (int i = 0; i < N; i++) a[i] = random.nextInt();

        long startTimestemp = System.currentTimeMillis();

        quickSort(a, 0, N - 1);

        long endTimestemp = System.currentTimeMillis();

        System.out.println("Elapsed time: " + (endTimestemp - startTimestemp) + " ms.");
    }
}