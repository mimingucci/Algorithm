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

    private static final int MAXN = (int) 1e3;

    private static final long INF = (long) 1e9;

    static int n;
    static int m;

    static Vector<Integer> adj[]=new Vector[MAXN+10];

    static long[] a=new long[MAXN+10];

    static Set<Integer> before;

    static boolean[] calcu=new boolean[MAXN+10];

    static long[] ans=new long[MAXN+10];

    public static void dfs(int u){
        if(before.contains(u)){
            calcu[u]=true;
            ans[u]=INF;
        }else{
            if(adj[u].size()==0){
                ans[u]=a[u];
                calcu[u]=true;
            }else{
                int v=adj[u].get(0);
                if(calcu[v]){
                    ans[u]=ans[v]+a[u];
                }else{
                    before.add(u);
                    dfs(v);
                    ans[u]=ans[v]+a[u];
                }
                calcu[u]=true;
            }
        }
    }



    public static void main(String[] args) {
        n=r.nextInt();
        m=r.nextInt();
        Arrays.fill(ans, INF);
        Set<Integer> culminating=new HashSet<>();
        for(int i=1; i<=n; i++)culminating.add(i);
        Arrays.fill(calcu, false);
        for(int i=1; i<=n; i++){
            adj[i]=new Vector<>();
        }
        for(int i=1; i<=n; i++)a[i]=r.nextLong();
        for(int i=1; i<=m; i++){
            int f=r.nextInt();
            int sc=r.nextInt();
            adj[sc].add(f);
            if(culminating.contains(f)){
                culminating.remove(f);
            }
        }
        for(int i=1; i<=n; i++){
            if(calcu[i]==false) {
                before = new HashSet<>();
                dfs(i);
            }
        }
        for(int i=1; i<=n; i++){
            if(culminating.contains(i))
            if(ans[i]>=INF){
                culminating.remove(i);
            }
        }
        Vector<Integer> culminate=new Vector<>(culminating);
        Vector<Long> finall=new Vector<>();
        int sz=culminate.size();
        for(int i=0; i<sz-1; i++){
            for(int j=i+1; j<sz; j++){
               Set<Integer> sett=new HashSet<>();
               int now=culminate.get(i);
               sett.add(now);
               while(adj[now].size()>0){
                   now=adj[now].get(0);
                   sett.add(now);
               }
               now=culminate.get(j);
               while(!sett.contains(now) && adj[now].size()>0){
                   now=adj[now].get(0);
               }
               long l=0l;
               if(sett.contains(now)){
                   l=ans[now];
               }
               finall.add(ans[culminate.get(i)]+ans[culminate.get(j)]-l);
            }
        }
        Collections.sort(finall);
        pw.println(finall.get(0));
        pw.close(); // flushes the output once printing is done
    }
}




