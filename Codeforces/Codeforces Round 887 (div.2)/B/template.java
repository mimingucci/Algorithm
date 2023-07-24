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
            long k=r.nextLong();
            if(n+5<k){
                pw.println(0);
                continue;
            }
            long left=Long.MIN_VALUE;
            long right=Long.MAX_VALUE;
            long prev=n;
            long pre=0;
            long plusv=0;
            long plus=1;
            for(long i=1; i<k; i++){
                long x=-pre/plus;
                long c[]=new long[3];
                c[0]=(x-1)*plus+pre;
                c[1]=x*plus+pre;
                c[2]=(x+1)*plus+pre;
                int index=-1;
                long minn=Long.MAX_VALUE;
                for(int j=0; j<3; j++){
                    if(c[j]>=0 && c[j]<=minn){
                        index=j;
                        minn=c[j];
                    }
                }
                if(index==0){
                    x--;
                }else{
                    if(index==2){
                        x++;
                    }
                }
                if(plus>0){
                    left=max(left, x);
                }else{
                    right=min(right, x);
                }
                long y=(pre-prev)/(plusv-plus);
                c[0]=(y-1)*(plusv-plus)-(pre-prev);
                c[1]=(y)*(plusv-plus)-(pre-prev);
                c[2]=(y+1)*(plusv-plus)-(pre-prev);
                index=-1;
                minn=Long.MAX_VALUE;
                for(int j=0; j<3; j++){
                    if(c[j]>=0 && c[j]<=minn){
                        index=j;
                        minn=c[j];
                    }
                }
                if(index==0){
                    y--;
                }else{
                    if(index==2){
                        y++;
                    }
                }
                if(plusv-plus>0){
                    left=max(left, y);
                }else{
                    right=min(right, y);
                }
                x=prev-pre;
                prev=pre;
                pre=x;
                y=plusv-plus;
                plusv=plus;
                plus=y;
                if(left>right)break;
            }
            pw.println(max(0l, right-left+1));
        }
        pw.close(); // flushes the output once printing is done
    }
}




