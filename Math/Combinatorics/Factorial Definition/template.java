import java.io.*;
import java.util.*;
import java.lang.*;

public class Combinatorics {
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

    static template.InputReader r = new template.InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);

    private static final int MAXN = (int)1e6;
    private static final int MOD = (int)1e9 + 7;
    private static long[] fac = new long[MAXN + 1];
    private static long[] inv = new long[MAXN + 1];

    private static long exp(long x, long n, long m) {
        x %= m;
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1) { res = (res * x) % m; }
            x = (x * x) % m;
            n /= 2;
        }
        return res;
    }

    private static void factorial() {
        fac[0] = 1;
        for (int i = 1; i <= MAXN; i++) { fac[i] = (fac[i - 1] * i) % MOD; }
    }

    private static void inverses() {
        inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
        for (int i = MAXN; i >= 1; i--) { inv[i - 1] = (inv[i] * i) % MOD; }
    }

    private static long choose(int n, int r) {
        return (((fac[n] * inv[r]) % MOD) * inv[n - r]) % MOD;
    }

    public static void main(String[] args) {
        factorial();
        inverses();
        //query
        pw.close();
    }

}
