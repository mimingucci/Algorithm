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

    public static int[][] identity(int n){
        int[][] a=new int[n][n];
        for(int i=0; i<n; i++){
            a[i][i]=1;
        }
        return a;
    }


    public static int[][] multi_matrix(int[][] a, int[][] b){
        int[][] ans=new int[a.length][b[0].length];
        for(int i=0; i<a.length; i++){
            for(int j=0; j<b[0].length; j++){
                for(int k=0; k<a[0].length; k++){
                    ans[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        return ans;
    }

    public static int[][] pow_matrix(int[][] a, int exp){
        int[][] ans=identity(a.length);
        int[][] base=a;
        for(; exp>0; exp>>=1, base=multi_matrix(base, base)){
            if((exp & 1)>0){
                ans=multi_matrix(ans, base);
            }
        }
        return ans;
    }

    public static class Tuple{
        private long value;
        private int l;
        private int r;

        public Tuple(long value, int l, int r) {
            this.value = value;
            this.l = l;
            this.r = r;
        }

        public long getValue() {
            return value;
        }

        public void setValue(long value) {
            this.value = value;
        }

        public int getL() {
            return l;
        }

        public void setL(int l) {
            this.l = l;
        }

        public int getR() {
            return r;
        }

        public void setR(int r) {
            this.r = r;
        }
    }



    public static void main(String[] args) {
        int t;
        t=r.nextInt();
        while((t--)>0){
            int n, k;
            n=r.nextInt();
            k=r.nextInt();
            List<Long> a=new ArrayList<>();
            long sum=0;
            for(int i=0; i<n; i++){
                long x;
                x=r.nextLong();
                a.add(x);
            }
            Collections.sort(a, (o1, o2) ->(int)(o2-o1));
            int l=0;
            int r=n-2*k;
            long ans=0;
            for(int i=0; i<r; i++){
                sum+=a.get(i);
            }
            ans=Math.max(ans, sum);
            while(r<n-1){
                sum+=a.get(r);
                sum+=a.get(r+1);
                r+=2;
                sum-=a.get(l++);
                ans=Math.max(ans, sum);
            }
            pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}


