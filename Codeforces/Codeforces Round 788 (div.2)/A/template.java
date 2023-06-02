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
            for(int i=0; i<n; i++){
                a[i]=r.nextInt();
            }
            int left=0;
            int right=n-1;
            while(left<right){
                while(left+1<n && a[left]<0){
                    ++left;
                }
                if(left>=right)break;
                while(right-1>=0 && a[right]>0)--right;
                if(right<=left)break;
                a[left]=-a[left];
                a[right]=-a[right];
                ++left;
                --right;
            }
            boolean isOk=true;
            for(int i=1; i<n; i++){
                if(a[i-1]>a[i]){
                    isOk=false;
                    break;
                }
            }
            if(isOk){
                pw.println("YES");
            }else{
                pw.println("NO");
            }
        }
        pw.close(); // flushes the output once printing is done
    }
}