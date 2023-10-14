import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.lang.*;
import java.util.stream.Collectors;

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
           int m=r.nextInt();
           int[] left=new int[m];
           int[] right=new int[m];
           for(int i=0; i<m; i++){
               int x=r.nextInt();
               int y=r.nextInt();
               left[i]=x-1;
               right[i]=y;
           }
           int q=r.nextInt();
           int x[]=new int[q];
           for(int i=0; i<q; i++){
               x[i]=r.nextInt();
           }
           int li=0;
           int ri=q+1;
           while(ri>li){
               int mid=ri + li >> 1;
               int[] s=new int[n+1];
               for(int i=0; i<mid; i++){
                   s[x[i]]=1;
               }
               for(int i=1; i<=n; i++)s[i]+=s[i-1];
               boolean isOk=false;
               for(int i=0; i<m; i++){
                   if(s[right[i]]-s[left[i]]>(right[i]-left[i])/2){
                       isOk=true;
                       break;
                   }
               }
               if(isOk){
                   ri=mid;
               }else{
                   li=mid+1;
               }
           }
           if(li>q){
               pw.println(-1);
           }else{
               pw.println(li);
           }
        }
        pw.close(); // flushes the output once printing is done
    }
}