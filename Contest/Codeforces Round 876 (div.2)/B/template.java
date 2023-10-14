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

    public static class Pair<F, SC> implements Comparable{
        public F First;
        public SC Second;

        public Pair(F first, SC second) {
            First = first;
            Second = second;
        }

        public F getFirst() {
            return First;
        }

        public void setFirst(F first) {
            First = first;
        }

        public SC getSecond() {
            return Second;
        }

        public void setSecond(SC second) {
            Second = second;
        }

        @Override
        public int compareTo(Object o) {
            if((int)this.getFirst()-(int)((Pair)o).getFirst()!=0)
                return (int)this.getFirst()-(int)((Pair)o).getFirst();
            else return -((int)this.getSecond()-(int)((Pair)o).getSecond());
        }
    }


    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
            int n=r.nextInt();
            long ans=0;
            Vector<Pair<Integer, Integer>> v=new Vector<>();
            for(int i=1; i<=n; i++){
                int a=r.nextInt();
                int b=r.nextInt();
                v.add(new Pair<>(a, b));
            }
            Collections.sort(v);
            int now=0;
            Deque<Integer> dq=new ArrayDeque<>();
            for(int i=0; i<n; i++){
                if(v.get(i).getFirst()<=now){
                    continue;
                }else{
                    dq.addLast(v.get(i).getFirst());
                    now=Math.max(now, dq.size());
                    ans+=v.get(i).getSecond();
                    while(!dq.isEmpty() && dq.getFirst()<=dq.size()){
                        dq.pollFirst();
                    }
                }
            }
            pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}
