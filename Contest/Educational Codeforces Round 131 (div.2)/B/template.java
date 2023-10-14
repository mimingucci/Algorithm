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
           pw.println(2);
           int pivot=1;
           int m=n;
           int start=1;
           boolean used[]=new boolean[n+1];
           Arrays.fill(used, false);
           while(start<=m){
               used[start]=true;
               pw.print(start+" ");
               start*=2;
           }
           for(int i=1; i<=n; i++){
               if(used[i]==false){
                   start=i;
                   while(start<=m){
                       if(used[start]==false)
                       pw.print(start+" ");
                       used[start]=true;
                       start*=2;
                   }
               }
           }
           pw.println();
        }
 
        pw.close(); // flushes the output once printing is done
    }
}