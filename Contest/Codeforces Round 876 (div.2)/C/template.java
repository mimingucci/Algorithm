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
            int[] a=new int[n];
            for(int i=0; i<n; i++)a[i]=r.nextInt();
            if(a[n-1]==1){
                pw.println("NO");
                continue;
            }
            int cnt=0;
            pw.println("YES");
            for(int i=n-1; i>=1; i--){
                if(a[i]==0){
                    if(a[i-1]==0){
                        pw.print(0+" ");
                    }
                }else{
                    ++cnt;
                    pw.print(0+" ");
                    if(a[i-1]==0){
                        pw.print(cnt+" ");
                        cnt=0;
                    }
                }
            }
            if(a[0]==0){
                    pw.print(0+" ");
            }else{
                if(a[1]==1){
                    ++cnt;
                    pw.print(0+" "+cnt);
                }else{
                    pw.print(0+" "+1);
                }
            }
            pw.println();
        }
        pw.close(); // flushes the output once printing is done
    }
}
