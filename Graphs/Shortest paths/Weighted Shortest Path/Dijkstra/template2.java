import java.io.*;
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

    static class Pair<K, V> {
        public K a;
        public V b;

        public Pair(K a, V b) {
            this.a = a;
            this.b = b;
        }
    }

    public static void main(String[] args) {
        int n=r.nextInt();
        int m=r.nextInt();
        List<Edge>[] edges=new List[n+1];
        for(int i=0; i<=n; i++)edges[i]=new ArrayList<>();
        for(int i=1; i<=m; i++){
            int a=r.nextInt();
            int b=r.nextInt();
            long w=r.nextLong();
            edges[a].add(new Edge(b, w));
            edges[b].add(new Edge(a, w));
        }
        long[] d=new long[n+1];
        int[] trace=new int[n+1];
        boolean[] processing=new boolean[n+1];
        Arrays.fill(d, Long.MAX_VALUE);
        Arrays.fill(processing, false);
        Arrays.fill(trace, -1);
        PriorityQueue<Pair<Long, Integer>> pq =
                new PriorityQueue<>(Comparator.comparingLong(i -> i.a));
        d[1]=0;
        pq.add(new Pair<>(0l, 1));
        while(!pq.isEmpty()){
            int a=pq.poll().b;
            if(processing[a]){
                continue;
            }
            processing[a]=true;
            for(var x : edges[a]){
                int b=x.getV();
                long w=x.getW();
                if(d[a]+w<d[b]){
                    d[b]=d[a]+w;
                    trace[b]=a;
                    pq.add(new Pair<>(d[b], b));
                }
            }
        }
        List<Integer> ans=new ArrayList<>();
        int now=n;
        if(trace[now]!=-1) {
            while (now != -1) {
                ans.add(now);
                now=trace[now];
            }
        }
        Collections.reverse(ans);
        if(ans.size()==0 || ans.get(0)!=1){
            pw.println(-1);
        }else{
            for(int i : ans){
                pw.print(i+" ");
            }
        }
        pw.close(); // flushes the output once printing is done
    }
}




