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
           int[] a=new int[n];
           int[] b=new int[n];
           for(int i=0; i<n; i++) {
               a[i] = r.nextInt();
               b[i]=a[i];
           }
           Vector<Pair<Integer, Integer>> ans=new Vector<>();
           boolean isOk=true;
           boolean hasNeg=false;
           boolean hasPos=false;
           for(int i=1; i<n; i++){
               if(a[i]<a[i-1]){
                   isOk=false;
               }
               if(a[i]>0 || a[i-1]>0)hasPos=true;
               if(a[i]<0 || a[i-1]<0)hasNeg=true;
           }
           if(isOk){
               pw.println(0);
               continue;
           }
           if(hasPos && !hasNeg){
               for(int i=1; i<n; i++){
                   ans.add(new Pair<>(i+1, i));
               }
               pw.println(ans.size());
               for(var x : ans){
                   pw.println(x.getFirst()+" "+x.getSecond());
               }
               continue;
           }
            if(!hasPos && hasNeg){
                for(int i=n-1; i>=1; i--){
                    ans.add(new Pair<>(i, i+1));
                }
                pw.println(ans.size());
                for(var x : ans){
                    pw.println(x.getFirst()+" "+x.getSecond());
                }
                continue;
            }
            int maxx_index=-1;
            int minn_index=-1;
            int maxx=Integer.MIN_VALUE;
            int minn=Integer.MAX_VALUE;
            for(int i=0; i<n; i++){
                maxx=max(maxx, a[i]);
                if(maxx==a[i])maxx_index=i;
                minn=min(minn, a[i]);
                if(minn==a[i])minn_index=i;
            }
            Vector<Pair<Integer, Integer>>  ans1=new Vector<>();
            while(a[maxx_index]<abs(a[minn_index])){
                a[maxx_index]+=a[maxx_index];
                ans.add(new Pair<>(maxx_index+1, maxx_index+1));
            }
            for(int i=0; i<n; i++){
                if(a[i]<0){
                    a[i]+=a[maxx_index];
                    ans.add(new Pair<>(i+1, maxx_index+1));
                }
            }
            for(int i=1; i<n; i++){
                ans.add(new Pair<>(i+1, i));
            }
            while(abs(b[minn_index])<b[maxx_index]){
                b[minn_index]+=b[minn_index];
                ans1.add(new Pair<>(minn_index+1, minn_index+1));
            }
            for(int i=0; i<n; i++){
                if(b[i]>0){
                    b[i]+=b[minn_index];
                    ans1.add(new Pair<>(i+1, minn_index+1));
                }
            }
            for(int i=n-1; i>=1; i--){
                ans1.add(new Pair<>(i, i+1));
            }
            if(ans1.size()<ans.size()){
                pw.println(ans1.size());
                for(var x : ans1){
                    pw.println(x.getFirst()+" "+x.getSecond());
                }
            }else{
                pw.println(ans.size());
                for(var x : ans){
                    pw.println(x.getFirst()+" "+x.getSecond());
                }
            }
        }
        pw.close(); // flushes the output once printing is done
    }
}




