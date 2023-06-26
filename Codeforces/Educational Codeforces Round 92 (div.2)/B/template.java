import java.io.*;
import java.math.*;
import java.util.*;
import java.lang.*;
import java.util.stream.Collectors;
import static java.lang.Math.min;
import static java.lang.Math.max;
import static java.lang.Math.abs;
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
           int z=r.nextInt();
           int[] a=new int[n+1];
           for(int i=1; i<=n; i++){
               a[i]=r.nextInt();
           }
           int[] f=new int[min(k/2, z)+1];
           for(int i=1; i<=k+1; i++){
               f[0]+=a[i];
           }
           int ans=f[0];
           for(int i=1; i<=min(k/2, z); i++){
               int maxx=-1;
               for(int j=1; j<=1+k-2*i; j++){
                   f[i]+=a[j];
                   if(a[j]+a[j+1]>maxx){
                       maxx=a[j]+a[j+1];
                   }
               }
               f[i]+=i*maxx;
               if(ans<f[i]){
                   ans=f[i];
               }
           }
           pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}