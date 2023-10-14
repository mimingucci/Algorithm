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
           int n=r.nextInt();
           int m=r.nextInt();
           int k=r.nextInt();
           int H=r.nextInt();
           int[]  h=new int[n];
           for(int i=0; i<n; i++)h[i]=r.nextInt();
           int ans=0;
           for(int i=0; i<n; i++){
               boolean isOk=false;
               for(int j=1; j<=m-1; j++){
                   if(j*k+h[i]==H || j*k+H==h[i]){
                       isOk=true;
                       break;
                   }
               }
               if(isOk)++ans;
           }
           pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}




