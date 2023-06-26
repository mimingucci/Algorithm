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
           String s=r.next();
           int[] a=new int[10];
           int n=s.length();
           for(int i=0; i<n; i++){
               a[s.charAt(i)-'0']++;
           }
           int ans=n-2;
           for(int i=0; i<10; i++){
               if(n-a[i]<ans){
                   ans=n-a[i];
               }
           }
           Vector<Integer> b=new Vector<>();
           for(int i=0; i<10; i++){
               if(a[i]>1){
                   b.add(i);
               }
           }
           for(int i=0; i<b.size(); i++){
               for(int j=0; j<b.size(); j++){
                   if(i!=j){
                       int cnt=0;
                       for(int k=0; k<n; k++){
                           if(cnt%2==0){
                               if(s.charAt(k)-'0'==b.get(i)){
                                   ++cnt;
                               }
                           }else{
                               if(s.charAt(k)-'0'==b.get(j)){
                                   ++cnt;
                               }
                           }
                       }
                       cnt/=2;
                       if(n-cnt*2<ans){
                           ans=n-cnt*2;
                       }
                   }
               }
           }
           pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}