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

    public static class Edge{
        private int v;
        private long w;

        public Edge(int v, long w) {
            this.v = v;
            this.w = w;
        }

        public int getV() {
            return v;
        }

        public void setV(int v) {
            this.v = v;
        }

        public long getW() {
            return w;
        }

        public void setW(long w) {
            this.w = w;
        }
    }

    public static void dijkstra(int n, int s, List<Edge>[] e, long[] d, int[] trace){
        boolean[] isUsed=new boolean[n];
        Arrays.fill(isUsed, false);
        Arrays.fill(d, Long.MAX_VALUE);
        d[s]=0;
        trace[s]=-1;
        for(int i=0; i<n; i++){
            int u=-1;
            long maxx=Long.MAX_VALUE;
            for(int j=0; j<n; j++){
                if(d[j]<maxx && !isUsed[j]){
                    maxx=d[j];
                    u=j;
                }
            }
            isUsed[u]=true;
            for(Edge ee : e[u]){
                if(d[ee.getV()]>d[u]+ee.getW()){
                    d[ee.getV()]=d[u]+ee.getW();
                    trace[ee.getV()]=u;
                }
            }
        }
    }

    public static List<Integer> trace_path(int[] trace, int s, int u){
        if(u!=s && trace[u]==-1){
            return new ArrayList<>();
        }
        List<Integer> path=new ArrayList<>();
        while(u!=-1){
            path.add(u);
            u=trace[u];
        }
        Collections.reverse(path);
        return path;
    }

    public static void main(String[] args) {
        pw.close(); // flushes the output once printing is done
    }
}


