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
           int n=r.nextInt();
           int k=r.nextInt();
           int x=r.nextInt();
           if(x>1){
               pw.println("YES");
               pw.println(n);
               for(int i=0; i<n; i++){
                   pw.print(1+" ");
               }
               pw.println();
               continue;
           }else{
               if(k==1){
                   pw.println("NO");
                   continue;
               }else{
                   if(n%2==0){
                       pw.println("YES");
                       pw.println(n/2);
                       for(int i=0; i<n/2; i++){
                           pw.print(2+" ");
                       }
                       pw.println();
                       continue;
                   }else{
                       if(n==1){
                           pw.println("NO");
                           continue;
                       }else{
                           if(k<3){
                               pw.println("NO");
                               continue;
                           }else{
                               pw.println("YES");
                               pw.println(1+(n-3)/2);
                               pw.print(3+" ");
                               for(int i=0; i<(n-3)/2; i++){
                                   pw.print(2+" ");
                               }
                               pw.println();
                               continue;
                           }
                       }
                   }
               }
           }
        }
        pw.close(); // flushes the output once printing is done
    }
}