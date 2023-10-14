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
    public static boolean check(int n, int[] occur, int t){
        long need=0;
        long sum=0;
        for(int i=1; i<=n; i++){
           if(t>=occur[i]){
               sum+=(t-occur[i])/2;
           }else{
               need+=occur[i]-t;
           }
        }
        if(need<=sum){
            return true;
        }
        return false;
    }
 
 
    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
            int n=r.nextInt();
            int m=r.nextInt();
            int[] a=new int[m];
            for(int i=0; i<m; i++)a[i]=r.nextInt();
            int[] occur=new int[n+1];
            for(int i=0; i<m; i++){
                occur[a[i]]++;
            }
            int left=0;
            int right=2*m;
            int res=-1;
            while(left<=right){
                int mid=(left+right)/2;
                if(check(n, occur, mid)){
                    res=mid;
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
            pw.println(res);
        }
 
        pw.close(); // flushes the output once printing is done
    }
}