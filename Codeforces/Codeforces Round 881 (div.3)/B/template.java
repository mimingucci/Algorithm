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
           int[] a=new int[n];
           long ans=0l;
           for(int i=0; i<n; i++){
               a[i]=r.nextInt();
               ans+=Math.abs(a[i]);
           }
           int neg=0;
           int pos=0;
           int now=-1;
           for(int i=0; i<n; i++){
               if(now==-1){
                   if(a[i]<0){
                       now=1;
                       ++neg;
                   }
               }else{
                   if(a[i]<=0){
                       continue;
                   }else{
                       now=-1;
                   }
               }
           }
           now=-1;
            for(int i=0; i<n; i++){
                if(now==-1){
                    if(a[i]>0){
                        now=1;
                        ++pos;
                    }
                }else{
                    if(a[i]>=0){
                        continue;
                    }else{
                        now=-1;
                    }
                }
            }
            pw.println(ans+" "+Math.min(pos+1, neg));
        }
        pw.close(); // flushes the output once printing is done
    }
}