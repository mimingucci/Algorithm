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

    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
            long n=r.nextLong();
            Vector<Long> factors=new Vector<>();
            for(long i=1; i<=1000; i++){
                if(n%i==0){
                    factors.add(i);
                }
            }
            long maxx=1;
            long now=1;
            for(int i=1; i<factors.size(); i++){
                if(factors.get(i)-factors.get(i-1)==1){
                    ++now;
                    maxx=max(maxx, now);
                }else{
                    now=1;
                    maxx=max(maxx, now);
                }
            }
            pw.println(maxx);
        }
        pw.close(); // flushes the output once printing is done
    }
}




