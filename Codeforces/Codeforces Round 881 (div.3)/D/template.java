import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.lang.*;
import java.util.stream.Collectors;

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

    static Vector<Integer>[] adj;

    static boolean[] vistied;

    static long[] ans;

    public static long dfs(int u){
        vistied[u]=true;
        int cnt=0;
        for(int i=0; i<adj[u].size(); i++){
            if(vistied[adj[u].get(i)]){
                continue;
            }
            ++cnt;
            ans[u]+=dfs(adj[u].get(i));
        }

        if(cnt==0){
            ans[u]=1;
            return 1;
        }else{
            return ans[u];
        }

    }


    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
           int n=r.nextInt();
           adj=new Vector[n+1];
           vistied=new boolean[n+1];
           ans=new long[n+1];
           for(int i=0; i<=n; i++)adj[i]=new Vector<Integer>();
           for(int i=0; i<n-1; i++){
               int x=r.nextInt();
               int y=r.nextInt();
               adj[x].add(y);
               adj[y].add(x);
           }
           dfs(1);
           int q=r.nextInt();
           for(int i=0; i<q; i++){
               int x=r.nextInt();
               int y=r.nextInt();
               pw.println(ans[x]*ans[y]);
           }
        }
        pw.close(); // flushes the output once printing is done
    }
}