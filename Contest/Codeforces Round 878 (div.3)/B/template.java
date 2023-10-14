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

    static int cnt(int n){
        int  cnt=0;
        while(n>0){
            n>>=1;
            ++cnt;
        }
        return cnt;
    }

    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
           int n=r.nextInt();
           int k=r.nextInt();
           int cnt=cnt(n);
           if(k>=cnt){
               pw.println(n+1);
               continue;
           }
           int ans=1;
           for(int i=1; i<=k; i++)ans<<=1;
           pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}
