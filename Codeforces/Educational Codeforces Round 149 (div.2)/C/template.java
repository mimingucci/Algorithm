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
           String s=r.next();
           int n=s.length();
           boolean hasOne=false;
           boolean hasZero=false;
           char pre='0';
           for(int i=0; i<n; i++){
              if(s.charAt(i)!='?'){
                  pw.print(s.charAt(i));
                  pre=s.charAt(i);
                  if(s.charAt(i)=='0'){
                      hasZero=true;
                  }else{
                      hasOne=true;
                  }
              }else{
                  if(hasOne==false && hasZero==false){
                      pw.print('0');
                      pre='0';
                  }else{
                      if(pre=='0'){
                          pw.print('0');
                      }else{
                          pw.print('1');
                      }
                  }
              }
           }
           pw.println();
        }
        pw.close(); // flushes the output once printing is done
    }
}
