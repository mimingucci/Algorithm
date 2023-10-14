import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.lang.*;

public class template {
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        String next() { // reads in the next string
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() { // reads in the next int
            return Integer.parseInt(next());
        }

        public long nextLong() { // reads in the next long
            return Long.parseLong(next());
        }

        public double nextDouble() { // reads in the next double
            return Double.parseDouble(next());
        }
    }

    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);


    public static int upper_bound_int(int[] ar, int n, long k) {
        int s = 0;
        int e = n;
        while (s != e) {
            int mid = s + e >> 1;
            if (ar[mid] <= k) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        if (s == n) {
            return -1;
        }
        return s;
    }


    static int[] a;

    static boolean check(int v, int n){
        int f=upper_bound_int(a, n, a[0]+2*v);
        if(f==-1)return true;
        int sc=upper_bound_int(a, n, a[f]+2*v);
        if(sc==-1)return true;
        int t=upper_bound_int(a, n, a[sc]+2*v);
        if(t==-1)return true;
        return false;
    }

    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
           int n=r.nextInt();
           a=new int[n];
           for(int i=0; i<n; i++)a[i]=r.nextInt();
           Arrays.sort(a);
           int left=0;
           int right=1000000000;
           while(right>left+1){
               int mid=(right+left)/2;
               if(check(mid, n)){
                   right=mid;
               }else{
                   left=mid+1;
               }
           }
           if(left+1==right){
               if(check(left, n)){
                   pw.println(left);
               }else{
                   pw.println(right);
               }
           }else{
               pw.println(left);
           }
        }
        pw.close(); // flushes the output once printing is done
    }
}
