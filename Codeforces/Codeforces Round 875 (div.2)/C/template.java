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


    static Vector<Pair<Integer, Integer>>[] adj;
    static int[] drawn;
 
    static int[] f;
 
    static void solve(int u, int pre){
        for(var x : adj[u]){
            if(x.getFirst()==pre){
                continue;
            }
            drawn[x.getFirst()]=x.getSecond();
            f[x.getFirst()]=f[u]+((x.getSecond()<drawn[u])? 1 : 0);
            solve(x.getFirst(), u);
        }
    }
    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
            int n=r.nextInt();
            drawn=new int[n];
            drawn[0]=n;
            f=new int[n];
            adj=new Vector[n];
            for(int i=0; i<n; i++)adj[i]=new Vector<>();
            for(int i=0; i<n-1; i++){
                int x=r.nextInt();
                int y=r.nextInt();
                --x;
                --y;
                adj[x].add(new Pair<>(y, i));
                adj[y].add(new Pair<>(x, i));
            }
            solve(0, -1);
            int ans=0;
            for(int i=0; i<n; i++){
                ans=Math.max(ans, f[i]);
            }
            pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}