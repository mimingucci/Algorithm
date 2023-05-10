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
           String s=r.next();
           Vector<Integer> v=new Vector<>();
           int cntOne=0;
           int cntZero=0;
           for(int i=0; i<n; i++){
               if(s.charAt(i)=='1'){
                   if(cntOne==0){
                       if(cntZero>0){
                           v.add(cntZero);
                           cntZero=0;
                       }
                       ++cntOne;
                   }else{
                       ++cntOne;
                   }
               }else{
                   if(cntZero==0){
                       if(cntOne>0){
                           v.add(cntOne);
                           cntOne=0;
                       }
                       ++cntZero;
                   }else{
                       ++cntZero;
                   }
               }
           }
           if(cntZero>0){
               v.add(cntZero);
           }
           if(cntOne>0){
               v.add(cntOne);
           }
           int l=-1;
           int r=-1;
           int ans=0;
           for(int i=0; i<v.size(); i++){
               if(v.get(i)%2!=0){
                   if(l!=-1){
                       if(i-l==1){
                           ++ans;
                           l=-1;
                       }else{
                           ans+=i-l;
                           l=-1;
                       }
                   }else{
                       l=i;
                   }
               }
           }
           pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}
