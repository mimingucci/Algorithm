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
           int m=r.nextInt();
           String s=r.next();
           int[] next=new int[n+1];
           int[] last=new int[n+1];
           Arrays.fill(next, n);
           Arrays.fill(last, -1);
           for(int i=n-1; i>=0; i--){
               if(s.charAt(i)=='1'){
                   next[i]=i;
               }else{
                   next[i]=next[i+1];
               }
           }
           if(s.charAt(0)=='0'){
               last[0]=0;
           }
           for(int i=0; i<n; i++){
               if(s.charAt(i)=='0'){
                   last[i+1]=i;
               }else{
                   last[i+1]=last[i];
               }
           }
           Map<Integer, Set<Integer>> ans=new HashMap<>();
           for(int i=0; i<m; i++){
               int left=r.nextInt();
               int right=r.nextInt();
               --left;
               left=next[left];
               right=last[right];
               if(left>right){
                   left=-1;
                   right=-1;
               }
               if(ans.get(left)==null){
                   Set<Integer> now=new HashSet<>();
                   now.add(right);
                   ans.put(left, now);
               }else{
                   ans.get(left).add(right);
               }
           }
           int cnt=0;
           for(var x : ans.entrySet()){
               cnt+=x.getValue().size();
           }
           pw.println(cnt);
        }
        pw.close(); // flushes the output once printing is done
    }
}




