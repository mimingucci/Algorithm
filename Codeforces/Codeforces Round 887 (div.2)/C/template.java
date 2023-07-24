import java.io.*;
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
            long k=r.nextLong();
            long[] a=new long[(int)n];
            for(int i=0; i<(int) n; i++)a[i]=r.nextLong();
            long left=0;
            long right=n*k+1;
            while(left<right-1){
                long mid = left + right >> 1;
                long cnt=n;
                long now=mid;
                for(int i=0; i<(int) k; i++){
                    while(cnt>0 &&  a[(int)cnt-1]>now)--cnt;
                    now-=cnt;
                }
                if(now==0){
                    left=mid;
                }else{
                    right=mid;
                }
            }
            pw.println(right);
        }
        pw.close(); // flushes the output once printing is done
    }
}




