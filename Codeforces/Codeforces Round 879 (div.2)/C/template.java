import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.lang.*;
import java.util.stream.Collectors;

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
           String S=r.next();
           String T=r.next();
           int de=0;
           int re=0;
           for(int i=0; i<n; i++){
               if(S.charAt(i)==T.charAt(i))++de;
           }
           for(int i=0; i<n; i++){
                if(S.charAt(i)==T.charAt(n-1-i))++re;
           }
           if(de==0 && re==0){
               pw.println(n+n-1);
               continue;
           }
           if(de==n){
               pw.println(0);
               continue;
           }
           if(re==n){
               pw.println(2);
               continue;
           }
           if(de>re){
               int con=n-de;
               if(con%2==0){
                   pw.println(2*con);
               }else{
                   pw.println(con+con-1);
               }
               continue;
           }else{
               if(re>de) {
                   int con = n - re;
                   if (con % 2 == 0) {
                       pw.println(2 * con - 1);
                   } else {
                       pw.println(con + con);
                   }
                   continue;
               }else{
                   int ans=0;
                   int con1=n-de;
                   int con2=n-re;
                   if(con1%2==0){
                       ans=con1*2;
                   }else{
                       ans=2*con1-1;
                   }
                   if (con2 % 2 == 0) {
                       ans=Math.min(2 * con2 - 1, ans);
                   } else {
                       ans=Math.min(2*con2, ans);
                   }
                   pw.println(ans);
               }
           }

        }
        pw.close(); // flushes the output once printing is done
    }
}