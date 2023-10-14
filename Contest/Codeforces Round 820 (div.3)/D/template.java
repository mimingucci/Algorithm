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

    public static int lower_bound(ArrayList<Long> ar, long k) {
        int s = 0;
        int e = ar.size();
        while (s != e) {
            int mid = s + e >> 1;
            if (ar.get(mid) < k) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        if (s == ar.size()) {
            return -1;
        }
        return s;
    }

    public static int upper_bound(ArrayList<Long> ar, long k) {
        int s = 0;
        int e = ar.size();
        while (s != e) {
            int mid = s + e >> 1;
            if (ar.get(mid) <= k) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        if (s == ar.size()) {
            return -1;
        }
        return s;
    }

    static int bit(long n, int i) {
        return (int) ((n >> i) & 1);
    }

    static boolean isPowerOfTwo(long n) {

        return (n >= 1) && (!((n & (n - 1)) >= 1));
    }

    static boolean isPrime(long n) {
        if (n <= 1) return false;
        if (n <= 3) return true;

        if (n % 2 == 0 || n % 3 == 0) return false;

        for (long i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;

        return true;
    }

    public static class Pair<F, SC> {
        public F First;
        public SC Second;

        public Pair(F first, SC second) {
            First = first;
            Second = second;
        }

        public F getFirst() {
            return First;
        }

        public void setFirst(F first) {
            First = first;
        }

        public SC getSecond() {
            return Second;
        }

        public void setSecond(SC second) {
            Second = second;
        }
    }

    public static boolean isPalindrome(String s) {
        if (s.length() == 1) {
            return true;
        } else {
            int n = s.length();
            for (int i = 0; i < n / 2; i++) {
                if (s.charAt(i) != s.charAt(n - 1 - i)) {
                    return false;
                }
            }
            return true;
        }
    }

    public static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    public static long lcm(long a, long b) {
        return (a / gcd(a, b)) * b;
    }

    public static class SegmentTree{
        public int size;
        public long[] sums;

        public int size(){return this.size;}

        public SegmentTree(int n) {
            init(n);
        }

        private void init(int n){
           size=1;
           while(size<n)size=size*2;
           sums=new long[2*size];
           Arrays.fill(sums, 0);
        }

        private void set(int i, long v, int x, int lx, int rx){
            if(rx-lx==1) {
                sums[x]=v;
                return;
            }
            int m=(lx+rx)/2;
            if(i<m){
                set(i, v, 2*x+1, lx, m);
            }else{
                set(i, v, 2*x+2, m, rx);
            }
            sums[x]=sums[2*x+1]+sums[2*x+2];
        }

        public void set(int i, long v){
            set(i, v,0, 0, size);
        }

        private long sum(int l, int r, int x, int lx, int rx){
            if(l>=rx || lx>=r)return 0;
            if(l>=lx && rx<=r)return sums[x];
            int m=(lx+rx)/2;
            long s1=sum(l, r, 2*x+1, lx, m);
            long s2=sum(l, r, 2*x+2, m, rx);
            return s1+s2;
        }

        public long sum(int l, int r){
            return sum(l, r, 0, 0, size);
        }
    }

    public static void main(String[] args) {
        int t;
        t=r.nextInt();
        while((t--)>0){
           int n;
           n=r.nextInt();
           long[] x=new long[n];
           long[] y=new long[n];
           for(int i=0; i<n; i++)x[i]=r.nextLong();
           for(int i=0; i<n; i++)y[i]=r.nextLong();
           Vector<Long> a=new Vector<>();
           for(int i=0; i<n; i++)a.add(y[i]-x[i]);
           Collections.sort(a);
           int l=0; int r=n-1;
           int ans=0;
           while(l<r){
               if(a.get(l)+a.get(r)>=0){
                   ++ans;
                   ++l;
                   --r;
               }else{
                   ++l;
               }
           }
           pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}