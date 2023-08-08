import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.lang.*;

import static java.lang.Math.*;

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

    public static int query(int left, int right){
        if(left==right){
            return 0;
        }
        System.out.println("? " + left + " " + right);
        System.out.flush();
        int before = r.nextInt();
        System.out.flush();
        return before;
    }

    public static int solve(int left, int right) {
        if (left == right) return left;
        int mid = left + right >> 1;
        int left_side = solve(left, mid);
        int right_side = solve(mid + 1, right);
        int before = query(left_side, right_side-1);
        int after = query(left_side, right_side);
        if (before == after) {
            return right_side;
        } else {
            return left_side;
        }
    }

    public static void main(String[] args) {
        int t = r.nextInt();
        while ((t--) > 0) {
            int n = r.nextInt();
            int ans = solve(1, n);
            System.out.println("! " + ans);
            System.out.flush();
        }
        pw.close(); // flushes the output once printing is done
    }
}




