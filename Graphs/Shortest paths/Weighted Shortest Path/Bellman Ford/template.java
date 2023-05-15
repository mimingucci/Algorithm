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
        private int u;
        private int v;
        private long w;

        public Edge(int u, int v, long w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }

        public int getU() {
            return u;
        }

        public void setU(int u) {
            this.u = u;
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

    public static void bellmanFord(int n, int s, List<Edge> e, List<Long> d, List<Integer> trace){
        d.add(s, 0l);
        for(int i=1; i<n; i++){
            for(Edge ee : e){
                if(d.get(ee.getU())!=Long.MAX_VALUE && d.get(ee.getV())>d.get(ee.getU())+ee.getW()){
                    d.add(ee.getV(), d.get(ee.getU())+ee.getW());
                    trace.add(ee.getV(), ee.getU());
                }
            }
        }
    }

    public static List<Integer> trace_path(List<Integer> trace, int s, int u){
        if(u!=s && trace.get(u)==-1){
            return new ArrayList<>();
        }
        List<Integer> path=new ArrayList<>();
        while(u!=-1){
            path.add(u);
            u=trace.get(u);
        }
        Collections.reverse(path);
        return path;
    }

    //find path negative infinity
    public static void checkNotShortestPath(int n, List<Edge> e, List<Long> d, List<Integer> trace){
        for(int i=0; i<n; i++){
            for(Edge ee : e){
                if(d.get(ee.getU())!=Long.MAX_VALUE && d.get(ee.getV())>d.get(ee.getU())+ee.getW()){
                    d.add(ee.getV(), Long.MIN_VALUE);
                    trace.add(ee.getV(), ee.getU());
                }
            }
        }
    }

    public static void main(String[] args) {
        pw.close(); // flushes the output once printing is done
    }
}

