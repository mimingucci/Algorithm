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
           long[] a=new long[(int) n];
           a[0]=0l;
           boolean isOk=true;
           for(int i=1; i<n; i++){
               a[i]=r.nextLong();
               if(a[i]>n*(n+1)/2){
                   isOk=false;
               }
           }
           if(!isOk){
               pw.println("NO");
               continue;
           }
           boolean[] used=new boolean[(int) n+1];
           Arrays.fill(used, false);
           long xxx=-1;
           int cnt=0;
           for(int i=(int)n-1; i>=1; i--){
               long x=a[i]-a[i-1];
               if(x>=2*n || x<1){
                   isOk=false;
               }else{
                   if(x>n){
                       xxx=x;
                       ++cnt;
                   }else {
                       if (used[(int) x]) {
                           xxx = x;
                           ++cnt;
                       } else {
                           used[(int) x] = true;
                       }
                   }
               }
           }
           if(!isOk){
               pw.println("NO");
               continue;
           }
           Vector<Long> remain=new Vector<>();
           for(long i=1; i<=n; i++){
               if(used[(int) i]==false){
                   remain.add(i);
               }
           }
           if(remain.size()>2 || remain.size()==0){
               pw.println("NO");
               continue;
           }else{
               if(remain.size()==1){
                       if ( xxx==-1 ) {
                           pw.println("YES");
                       } else {
                           pw.println("NO");
                       }

               }else {
                   if (remain.get(0) + remain.get(1) != xxx || cnt>1) {
                       pw.println("NO");
                   } else {
                       pw.println("YES");
                   }
               }
           }
        }
        pw.close(); // flushes the output once printing is done
    }
}




