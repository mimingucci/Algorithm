import java.io.*;
import java.math.BigInteger;
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

    static long sum(int a, int  b){
        if(a>b){
            return 0;
        }
        if(a==b){
            return a;
        }
        if((b-a+1)%2==0){
            return (long)(a+b)*(long)((b-a+1)/2);
        }else{
            return (long)(a+b)*(long)((b-a+1)/2)+(long)(a+b)/2;
        }
    }

    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
           int n=r.nextInt();
           int k=r.nextInt();
           int q=r.nextInt();
           int[] a=new int[n+1];
           for(int i=1; i<=n; i++)a[i]=r.nextInt();
           int left=0;
           int right=0;
           long ans=0;
           for(int i=1; i<=n; i++){
               if(a[i]>q){
                   if(left==0){
                       continue;
                   }
                   if(k<=right-left+1){
                       ans+=(long)(right+2-left)*(long)(right-left+1-k+1);
                       ans-=sum(k, right-left+1);
                   }
                   left=0;
                   right=0;
               }else{
                   if(left==0){
                       left=i;
                       right=i;
                   }else{
                       ++right;
                   }
               }
           }
           if(left!=0){
               if(k<=right-left+1){
                   ans+=(long)(right+2-left)*(long)(right-left+1-k+1);
                   ans-=sum(k, right-left+1);
               }
           }
           pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}
