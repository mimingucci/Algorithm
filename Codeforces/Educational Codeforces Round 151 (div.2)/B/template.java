import java.io.*;
import java.math.*;
import java.util.*;
import java.lang.*;
import java.util.stream.Collectors;

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

    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
           long xa=r.nextLong();
           long ya=r.nextLong();
           long xb=r.nextLong();
           long yb=r.nextLong();
           long xc=r.nextLong();
           long yc=r.nextLong();
           long ans=1;
           if((xb>=xa && xc>=xa) || (xb<=xa && xc<=xa))
           ans+=min(abs(xb-xa), abs(xc-xa));
           if((yb>=ya && yc>=ya) || (yb<=ya && yc<=ya))
           ans+=min(abs(yb-ya), abs(yc-ya));
            pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}