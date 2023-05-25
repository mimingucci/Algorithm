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
           String s=r.next();
           int incre=0;
           int decre=0;
           int inc=0;
           int dec=0;
           for(int i=0; i<n; i++){
               if(s.charAt(i)=='<'){
                   if(inc==0){
                       decre=Math.max(dec, decre);
                       dec=0;
                       ++inc;
                       incre=Math.max(incre, inc);
                   }else{
                       ++inc;
                       incre=Math.max(incre, inc);
                   }
               }else{
                   if(dec==0){
                       incre=Math.max(incre, inc);
                       inc=0;
                       ++dec;
                       decre=Math.max(decre, dec);
                   }else{
                       ++dec;
                       decre=Math.max(decre, dec);
                   }
               }

           }
            pw.println(Math.max(decre, incre)+1);
        }
        pw.close(); // flushes the output once printing is done
    }
}
