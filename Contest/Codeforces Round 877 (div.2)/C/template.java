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

    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
            int n=r.nextInt();
            int m=r.nextInt();
            int x=(2*m)+1;
            while(x<=n*m){
                for(int i=0;i<m;i++)
                    pw.print((x+i)+" ");
                pw.println();
                x+=2*m;
            }
            for(int i=1;i<=m;i++)pw.print(i+" ");
            pw.println();
            for(int i=3*m+1;i<=4*m;i++)pw.print(i+" ");
            pw.println();
            x=m+1;
            while(x<=n*m) {
                if (x == 3 * m + 1) {
                    x += 2 * m;
                    continue;
                }
                for (int i = 0; i < m; i++)
                    pw.print((x+i)+" ");
                pw.println();
                x += 2 * m;
            }
            pw.println();
        }
        pw.close(); // flushes the output once printing is done
    }
}
