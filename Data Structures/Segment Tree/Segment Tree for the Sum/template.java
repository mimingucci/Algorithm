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

    public static final int maxN=100000+7;

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

        public SegmentTree() {
            this.size=maxN;
            sums=new long[4*size];
            Arrays.fill(sums, 0);
        }

        void build(int id, int l, int r, long a[]) {
            if (l == r) {
                sums[id] = a[l];
                return;
            }

            int mid = l + r >> 1;
            build(2 * id, l, mid, a);
            build(2 * id + 1, mid + 1, r, a);

            sums[id] = sums[2 * id]+sums[2 * id + 1];
        }

        void update(int id, int l, int r, int i, long val) {
            if (l > i || r < i) return;

            if (l == r) {
                sums[id] = val;
                return;
            }

            int mid = l + r >> 1; // (l + r) / 2
            update(2 * id, l, mid, i, val);
            update(2 * id + 1, mid + 1, r, i, val);

            sums[id] = sums[2 * id]+sums[2 * id + 1];
        }


        long get(int id, int l, int r, int u, int v) {
            if (l >  v || r <  u) return 0;

            if (l >= u && r <= v) return sums[id];

            int mid = l + r >> 1; // (l + r) / 2
            long get1 = get(2 * id, l, mid, u, v);
            long get2 = get(2 * id + 1, mid + 1, r, u, v);

            return get1 + get2;
        }

    }

    public static void main(String[] args) {
        int n, m;
        n=r.nextInt();
        m=r.nextInt();
        long[] a=new long[n+1];
        for(int i=1; i<=n; i++)a[i]=r.nextLong();
        SegmentTree sg=new SegmentTree();
        sg.build(1, 1, n, a);
        while((m--)>0){
            int q;
            q=r.nextInt();
            if(q==1){
                int i=r.nextInt();
                long v=r.nextLong();
                sg.update(1, 1, n, i+1, v);
            }else{
                int x, y;
                x=r.nextInt();
                y=r.nextInt();
                pw.println(sg.get(1, 1, n, x+1, y));
            }
        }
        pw.close(); // flushes the output once printing is done
    }
}
