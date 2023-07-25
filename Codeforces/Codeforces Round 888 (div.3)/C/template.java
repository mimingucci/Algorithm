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
           int k=r.nextInt();
           int[] c=new int[n];
           for(int i=0; i<n; i++)c[i]=r.nextInt();
           if(c[0]==c[n-1]){
               int cnt=0;
               for(int i=0; i<n; i++){
                   if(c[i]==c[0])++cnt;
               }
               if(cnt>=k){
                   pw.println("YES");
                   continue;
               }else{
                   pw.println("NO");
                   continue;
               }
           }
           int left=-1;
           int right=-1;
           int cnt=0;
           for(int i=0; i<n; i++){
               if(c[i]==c[0])++cnt;
               if(cnt==k){
                   left=i;
                   break;
               }
           }
           if(left==-1){
               pw.println("NO");
               continue;
           }
           for(int i=n-1; i>=0; i--){
               if(c[i]==c[n-1])++cnt;
               if(cnt==2*k){
                   right=i;
                   break;
               }
           }
           if(right==-1){
               pw.println("NO");
               continue;
           }
           if(left>=right){
               pw.println("NO");
               continue;
           }
           if(c[0]==c[n-1]){
               boolean isOk=false;
               for(int i=left; i<right; i++){
                   if(c[i]==c[i+1]){
                       isOk=true;
                       break;
                   }
               }
               if(isOk){
                   pw.println("YES");
               }else{
                   pw.println("NO");
               }
           }else{
               pw.println("YES");
           }
        }
        pw.close(); // flushes the output once printing is done
    }
}




