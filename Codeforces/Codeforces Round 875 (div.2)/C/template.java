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


    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
           int n=r.nextInt();
           boolean[] drawn=new boolean[n+1];
           Deque<Pair<Integer, Integer>> dq=new ArrayDeque<>();
           int cnt=1;
           for(int i=1; i<n; i++){
               int x=r.nextInt();
               int y=r.nextInt();
               if(x==1 || y==1){
                   drawn[x]=true;
                   drawn[y]=true;
                   continue;
               }
               if(drawn[x] || drawn[y]){
                   drawn[x]=true;
                   drawn[y]=true;
                   continue;
               }

               dq.addLast(new Pair<>(x, y));

           }
           while(!dq.isEmpty()){
               ++cnt;
               Deque<Pair<Integer, Integer>> dqq=new ArrayDeque<>();
               while(dq.size()>0){
                   Pair p=dq.pollFirst();
                   if(drawn[(Integer)p.getFirst()] || drawn[(Integer)p.getSecond()]){
                       drawn[(Integer)p.getFirst()]=true;
                       drawn[(Integer)p.getSecond()]=true;
                   }else{
                       dqq.addLast(p);
                   }
               }
               dq=dqq;
           }
           pw.println(cnt);
        }
        pw.close(); // flushes the output once printing is done
    }
}