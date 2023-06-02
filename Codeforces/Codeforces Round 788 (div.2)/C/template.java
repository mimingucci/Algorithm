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


    public static final int mod=1000000000+7;

    static int[] a;
    static int[] b;
    static int[] c;

    static Vector<Integer>[] adj;

    static boolean[] visited;

    public static void dfs(int u){
        visited[u]=true;
        for(int v : adj[u]){
            if(!visited[v]){
                dfs(v);
            }
        }
    }

    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
            int n=r.nextInt();
            adj=new Vector[n+1];
            for(int i=0; i<=n; i++)adj[i]=new Vector<>();
            a=new int[n+1];
            b=new int[n+1];
            c=new int[n+1];
            visited=new boolean[n+1];
            Arrays.fill(visited, false);
            for(int i=1; i<=n; i++)a[i]=r.nextInt();
            for(int i=1; i<=n; i++) {
                b[i] = r.nextInt();
                adj[a[i]].add(b[i]);
                adj[b[i]].add(a[i]);
            }
            Set<Integer> sett=new HashSet<>();
            for(int i=1; i<=n; i++) {
                c[i] = r.nextInt();
                if(c[i]!=0)
                sett.add(c[i]);
            }
            int ans=1;
            for(int i : sett){
                if(!visited[i]){
                    dfs(i);
                }
            }
            for(int i=1; i<=n; i++){
                if(adj[i].get(0)==i)continue;
                if(!visited[i]){
                    dfs(i);
                    ans*=2;
                    ans%=mod;
                }
            }
            pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}
