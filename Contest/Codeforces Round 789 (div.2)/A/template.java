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
        int t;
        t=r.nextInt();
        while((t--)>0){
           int n;
           n=r.nextInt();
           Vector<Integer> v=new Vector<>(n);
           for(int i=0; i<n; i++){
               int x;
               x=r.nextInt();
               v.add(i, x);
           }
           Collections.sort(v);
           int cnt=0;
           if(v.firstElement()==0){
               for(int i=1; i<n; i++){
                   if(v.get(i)>0)++cnt;
               }
               pw.println(cnt);
           }else{
               boolean isOk=true;
               Set<Integer> sett=new HashSet<>(v.stream().toList());
               if(sett.size()<v.size()){
                   pw.println(n);
               }else{
                   pw.println(n+1);
               }
           }
        }
        pw.close(); // flushes the output once printing is done
    }
}