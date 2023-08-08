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
        int t = r.nextInt();
        while ((t--) > 0) {
           int n=r.nextInt();
           long k=r.nextLong();
           long[] a=new long[n+1];
           long left=Long.MIN_VALUE;
           for(int i=1; i<=n; i++) {
               a[i] = r.nextLong();
               left=max(left, a[i]);
           }
           long[] optimal=new long[n+1];
           optimal[n]=a[n];
           for(int i=n-1; i>=1; i--){
               if(a[i]<=optimal[i+1]){
                   optimal[i]=optimal[i+1]+1;
               }else{
                   optimal[i]=a[i];
               }
           }
           long right=Long.MIN_VALUE;
           for(int i=1; i<=n; i++)right=max(right, optimal[i]);
           long ans=left;
           while(left<=right){
               long mid=left+(right-left)/2;
               boolean isOk=false;
               for(int i=n; i>=1; i--){
                   long maxx=mid;
                   long steps=0;
                   for(int j=i; j<=n; j++){
                       if(a[j]==maxx){
                           break;
                       }
                       if(optimal[j]>=maxx && a[j]<maxx){
                           steps+=abs(a[j]-maxx);
                           maxx--;
                       }else{
                           if(a[j]>maxx){
                               break;
                           }else{
                               if(optimal[j]<maxx){
                                   steps=Long.MAX_VALUE;
                                   break;
                               }
                           }
                       }
                   }
                   if(steps<=k){
                       isOk=true;
                       break;
                   }
               }
               if(isOk){
                   ans=max(ans, mid);
                   left=mid+1;
               }else{
                   right=mid-1;
               }
           }
           pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}




