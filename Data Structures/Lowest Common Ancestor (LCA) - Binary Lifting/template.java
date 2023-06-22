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

    static int n;

    static int[] h;

    static int[][] up;

    static Vector<Integer>[] g;

    static int[] lg2;

    public static void preprocess(){
        lg2=new int[n+1];
        lg2[1]=0;
        for(int i=2; i<=n; i++){
            lg2[i]=lg2[i/2]+1;
        }
    }
    public static void dfs(int u){
        for(int x : g[u]){
            if(x==up[u][0])continue;
            h[x]=h[u]+1;
            up[x][0]=u;
            for(int j=1; j<20; j++){
                up[x][j]=up[up[x][j-1]][j-1];
            }
            dfs(x);
        }
    }

    public static int lca(int u, int v){
        if(h[u]!=h[v]){
            if(h[u]<h[v]){
                u=u+v;
                v=u-v;
                u=u-v;
                int k=h[u]-h[v];
                for(int i=0; (1<<i)<=k; i++){
                    if((k >> i & 1) > 0){
                        u=up[u][i];
                    }
                }
            }
        }
        if(u==v){
            return u;
        }
        int k=lg2[h[u]];
        for(int i=k; i>=0; i--){
            if(up[u][i]!=up[v][i]){
                u=up[u][i];
                v=up[v][i];
            }
        }
        return up[u][0];
    }

    public static void main(String[] args) {
        n=r.nextInt();
        h=new int[n+1];
        up=new int[n+1][20];
        g=new Vector[n+1];
        for(int i=0; i<=n; i++)g[i]=new Vector<>();
        int k=r.nextInt();
        for(int i=0; i<k; i++){
            int x=r.nextInt();
            int y=r.nextInt();
            g[x].add(y);
            g[y].add(x);
        }
        dfs(1);
        preprocess();
        int q=r.nextInt();
        for(int i=0;  i<q; i++){
            int u=r.nextInt();
            int v=r.nextInt();
            pw.println(lca(u, v));
        }
        pw.close(); // flushes the output once printing is done
    }
}