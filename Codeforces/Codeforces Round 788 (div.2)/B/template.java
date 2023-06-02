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
            String s=r.next();
            int ss[]=new int[26];
            int k=r.nextInt();
            for(int i=0; i<k; i++) {
                String a = r.next();
                ss[(int)a.charAt(0)-97]=1;
            }
            int ans=0;
            int pre=0;
            for(int i=0; i<n; i++){
                if(ss[(int)s.charAt(i)-97]==1){
                    ans=Math.max(ans, i-pre);
                    pre=i;
                }
            }
            pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}
