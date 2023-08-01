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
           for(int i=0; i<n; i++) {
               a[i] = r.nextInt();
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
            if(maxx>=abs(minn)) {
                while (a[0] <= 0) {
                    ans.add(new Pair<>(1, maxx_index + 1));
                    a[0] += maxx;
                }
                ans.add(new Pair<>(1, maxx_index + 1));
                a[0] += maxx;
                while (a[0] < abs(minn)) {
                    ans.add(new Pair<>(1, 1));
                    a[0] += a[0];
                }
                for (int i = 1; i < n; i++) {
                    if (a[i] < 0) {
                        ans.add(new Pair<>(i + 1, i));
                        ans.add(new Pair<>(i + 1, i));
                        a[i] += 2 * a[i - 1];
                    } else {
                        ans.add(new Pair<>(i + 1, i));
                        a[i] += a[i - 1];
                    }
                }
                pw.println(ans.size());
                for (var x : ans) {
                    pw.println(x.getFirst() + " " + x.getSecond());
                }
            }else{
                while (a[n-1] > 0) {
                    ans.add(new Pair<>(n, minn_index + 1));
                    a[n-1] += minn;
                }
                ans.add(new Pair<>(n, minn_index + 1));
                a[n-1] += minn;
                while (abs(a[n-1]) < abs(maxx)) {
                    ans.add(new Pair<>(n, n));
                    a[n-1] += a[n-1];
                }
                for (int i = n-2; i >= 0; i--) {
                    if (a[i] > 0) {
                        ans.add(new Pair<>(i + 1, i+2));
                        ans.add(new Pair<>(i + 1, i+2));
                        a[i] += 2 * a[i + 1];
                    } else {
                        ans.add(new Pair<>(i + 1, i+2));
                        a[i] += a[i + 1];
                    }
                }
                pw.println(ans.size());
                for (var x : ans) {
                    pw.println(x.getFirst() + " " + x.getSecond());
                }
            }
        }
        pw.close(); // flushes the output once printing is done
    }
}




