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

    static final long MAXX=10000000000000000l;

    static Set<Long> adj[];
    static long[] a;
    static long[] price;

    static boolean[] optimal;

    static void dfs(long u, Set<Long> passed){
        passed.add(u);
        long minn=0;
        for(long v :  adj[(int)u]){
           if(passed.contains(v) || optimal[(int) v]){
                   minn += price[(int) v];
           }else{
               dfs(v, passed);
               minn+=price[(int) v];
           }
        }
        if(adj[(int) u].size()>0) {
            price[(int) u] = min(price[(int) u], minn);
        }
        optimal[(int) u]=true;
    }

    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
           long n=r.nextLong();
           long k=r.nextLong();
           adj=new HashSet[(int) n+1];
           price=new long[(int) n+1];
           optimal=new boolean[(int) n+1];
           Arrays.fill(optimal, false);
           for(int i=0; i<=(int) n; i++)adj[i]=new HashSet<>();
           a=new long[(int) n + 1];
           for(int i=1; i<=(int) n; i++) {
               a[i] = r.nextLong();
               price[i]=a[i];
           }
           for(int i=1; i<=(int) k; i++){
               long x=r.nextLong();
               price[(int) x]=0l;
               optimal[(int) x]=true;
           }
           for(int i=1; i<=(int) n; i++){
               long s=r.nextLong();
               if(s==0){
                   optimal[(int) s]=true;
               }else{
                   for(long j=0; j<s; j++){
                       long x=r.nextLong();
                       adj[(int) i].add(x);
                   }
               }
           }
           for(int i=1; i<=n; i++){
               if(!optimal[i]){
                   dfs(i, new HashSet<>());
               }
               pw.print(price[i]+" ");
           }
           pw.println();
        }
        pw.close(); // flushes the output once printing is done
    }
}




