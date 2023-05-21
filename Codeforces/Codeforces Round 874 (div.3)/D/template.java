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

    
    public static void in(int[] a, int start, int end){
        start=Math.max(start, 0);
        end=Math.max(end, 0);
        if(start>end){
            for(int i=start; i>=end; i--){
                pw.print(a[i]+" ");
            }
        }else{
            for(int i=start; i<=end; i++){
                pw.print(a[i]+" ");
            }
        }
    }



    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
            int n=r.nextInt();
            int[] a=new int[n+1];
            for(int i=1; i<=n; i++)a[i]=r.nextInt();
            int right=1;
            int left=1;
            if(n==1){
                pw.println(1);
            }else{
                if(n==2){
                    pw.println(a[2]+" "+a[1]);
                    continue;
                }
                if(a[1]==n){
                    if(a[n]==n-1){
                        pw.print(a[n]+" ");
                        in(a, 1, n-1);
                        pw.println();
                        continue;
                    }
                    while(a[right+1]!=n-1)++right;
                    left=right;
                    while(left>2 && a[left-1]>a[1])--left;
                    in(a, right+1, n);
                    in(a, right, left);
                    if(left-1>=1)
                    in(a, 1, left-1);
                }else{
                    if(a[n]==n){
                        if(a[n-1]<a[1]){
                            pw.print(a[n]+" ");
                            in(a, 1, n-1);
                            pw.println();
                            continue;
                        }
                    }
                    while(a[right+1]!=n)++right;
                    left=right;
                    while(left>2 && a[left-1]>a[1])--left;
                    in(a, right+1, n);
                    in(a, right, left);
                    if(left-1>=1)
                    in(a, 1, left-1);
                }
                pw.println();
            }
        }
        pw.close(); // flushes the output once printing is done
    }
}
