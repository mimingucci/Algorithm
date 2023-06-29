import java.io.*;
import java.math.*;
import java.util.*;
import java.lang.*;
import java.util.stream.Collectors;

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
           String s=r.next();
           int n=s.length();
           int m=r.nextInt();
           String left=r.next();
           String right=r.next();
           Map<Integer, Integer>[] mapp=new Map[n];
           for(int i=0; i<n; i++){
               mapp[i]=new HashMap<>();
           }
           for(int i=n-1; i>=0; i--){
               if(i==n-1){
                   mapp[i].put(s.charAt(i)-'0', i);
               }else{
                   for(var x : mapp[i+1].entrySet()){
                       mapp[i].put(x.getKey(), x.getValue());
                   }
                   mapp[i].put(s.charAt(i)-'0', i);
               }
           }
           boolean isOk=false;
           int now=0;
           for(int i=0; i<m; i++){
               if(now>=n){
                   isOk=true;
                   break;
               }
               int leftt=left.charAt(i)-'0';
               int rightt=right.charAt(i)-'0';
               int maxx=Integer.MIN_VALUE;
               for(int j=leftt; j<=rightt; j++){
                   if(mapp[now].get(j)==null){
                       isOk=true;
                       break;
                   }else{
                       maxx=max(maxx, mapp[now].get(j));
                   }
               }
               if(isOk){
                   break;
               }else {
                   now = maxx + 1;
               }
           }
           if(isOk){
               pw.println("YES");
           }else{
               pw.println("NO");
           }
        }
        pw.close(); // flushes the output once printing is done
    }
}