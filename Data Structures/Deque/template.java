import java.io.*;
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

    public static int lower_bound(ArrayList<Long> ar,long k)
    {
        int s=0;
        int e=ar.size();
        while (s !=e)
        {
            int mid = s+e>>1;
            if (ar.get(mid) <k)
            {
                s=mid+1;
            }
            else
            {
                e=mid;
            }
        }
        if(s==ar.size())
        {
            return -1;
        }
        return s;
    }

    public static int upper_bound(ArrayList<Long> ar,long k)
    {
        int s=0;
        int e=ar.size();
        while (s !=e)
        {
            int mid = s+e>>1;
            if (ar.get(mid) <=k)
            {
                s=mid+1;
            }
            else
            {
                e=mid;
            }
        }
        if(s==ar.size())
        {
            return -1;
        }
        return s;
    }

    static int bit(long n, int i){
        return (int) ((n>>i)&1);
    }

    static boolean isPowerOfTwo(long n) {

        return (n>=1) && (!((n & (n - 1))>=1));
    }

    static boolean isPrime(long n) {
     if (n <= 1) return false;
     if (n <= 3) return true;

     if (n%2 == 0 || n%3 == 0) return false;

     for (long i=5; i*i<=n; i=i+6)
         if (n%i == 0 || n%(i+2) == 0)
         return false;

     return true;
     }


    public static void main(String[] args) {
        int n, k;
        n=r.nextInt();
        k=r.nextInt();
        int a[]=new int[n];
        for(int i=0; i<n; i++){
            a[i]=r.nextInt();
        }
        Deque<Integer> dq=new ArrayDeque<>();
        int minRange[]=new int[n];
        for(int i=0; i<n; i++){
            while(dq.size()>0 && a[dq.getLast()]>=a[i]){
                dq.removeLast();
            }
            dq.offerLast(i);
            if(dq.getFirst()+k<=i)dq.removeFirst();
            if(i>=k-1)minRange[i]=a[dq.getFirst()];
        }
        for(int i=k-1; i<n; i++){
            pw.println(minRange[i]+" ");
        }
        pw.close(); // flushes the output once printing is done
    }
}
