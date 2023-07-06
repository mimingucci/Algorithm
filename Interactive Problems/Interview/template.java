import java.io.*;
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

    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
            long n=r.nextLong();
            long[] a=new long[(int)n+1];
            long sum[]=new long[(int)n+1];
            sum[0]=0l;
            for(int i=1; i<=(int)n; i++){
                a[i]=r.nextLong();
                sum[i]=sum[i-1]+a[i];
            }
            int left=1;
            int right=(int)n;
            int cnt=0;
            while(left!=right && cnt<30){
                ++cnt;
                int mid= left + right >> 1;
                System.out.print("? "+(mid-left+1)+" ");
                for(int i=left; i<=mid; i++){
                    System.out.print(i+" ");
                }
                System.out.println();
                System.out.flush();
                long s=r.nextLong();
                System.out.flush();
                long sums=sum[mid]-sum[left-1];
                if(sums==s){
                    left=mid+1;
                }else{
                    if(right==left+1 && cnt<30){
                        System.out.print("? 1 "+right);
                        System.out.println();
                        System.out.flush();
                        long ss=r.nextLong();
                        System.out.flush();
                        if(ss==a[right]){
                            break;
                        }else{
                            left=right;
                            break;
                        }
                    }else{
                        right=mid;
                    }
                }
            }
            System.out.println("! "+left);
            System.out.flush();
        }
        pw.close(); // flushes the output once printing is done
    }
}




