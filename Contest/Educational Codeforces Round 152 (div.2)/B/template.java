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
           int k=r.nextInt();
           int[] a=new int[n+1];
           for(int i=1; i<=n; i++)a[i]=r.nextInt();
           int[] ans=new int[n+1];
           Map<Integer, Vector<Integer>> mapp=new TreeMap<>();
           for(int i=1; i<=n; i++){
               int du=a[i]%k;
               if(mapp.get(du)==null){
                   Vector<Integer> c=new Vector<>();
                   c.add(i);
                   mapp.put(du, c);
               }else{
                   mapp.get(du).add(i);
               }
           }
           Vector<Integer> zeros=new Vector<>();
           Vector<Vector> others=new Vector<>();
           for(var s : mapp.entrySet()){
               if(s.getKey()==0){
                   for(int i : s.getValue()){
                       zeros.add(i);
                   }
               }else{
                   others.add(s.getValue());
               }
           }
           for(int i : zeros){
               pw.print(i+" ");
           }
           for(int i=others.size()-1; i>=0; i--){
               for(int j=0; j< others.get(i).size(); j++){
                   pw.print(others.get(i).get(j)+" ");
               }
           }
           pw.println();
        }
        pw.close(); // flushes the output once printing is done
    }
}




