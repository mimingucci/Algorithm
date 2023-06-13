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

    static int[] pi={1, 10, 100, 1000, 10000};

    static int sum(int[] a, int n){
        int sum=0;
        int maxx=0;
        for(int i=n-1; i>=0; i--){
            if(a[i]>=maxx){
                sum+=pi[a[i]];
            }else{
                sum-=pi[a[i]];
            }
            maxx=Math.max(maxx, a[i]);
        }
        return sum;
    }

    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
            String s=r.next();
            int n=s.length();
            int[] a=new int[n];
            for(int i=0; i<n; i++){
                a[i]=(int)s.charAt(i)-65;
            }
            int posA=-1;
            int posB=-1;
            int posC=-1;
            int posD=-1;
            int posE=-1;
            for(int i=0; i<n; i++){
                if(posA==-1 && a[i]==0)posA=i;
                if(posB==-1 && a[i]==1)posB=i;
                if(posC==-1 && a[i]==2)posC=i;
                if(posD==-1 && a[i]==3)posD=i;
                if(posE==-1 && a[i]==4)posE=i;
            }
            int ans=sum(a, n);
            if(posA!=-1){
                for(int i=1; i<=4; i++){
                    a[posA]=i;
                    ans=Math.max(ans, sum(a, n));
                }
                a[posA]=0;
            }
            if(posB!=-1){
                for(int i=2; i<=4; i++){
                    a[posB]=i;
                    ans=Math.max(ans, sum(a, n));
                }
                a[posB]=1;
            }
            if(posC!=-1){
                for(int i=3; i<=4; i++){
                    a[posC]=i;
                    ans=Math.max(ans, sum(a, n));
                }
                a[posC]=2;
            }
            if(posD!=-1){
                for(int i=4; i<=4; i++){
                    a[posD]=i;
                    ans=Math.max(ans, sum(a, n));
                }
                a[posD]=3;
            }
            posA=-1;
            posB=-1;
            posC=-1;
            posD=-1;
            posE=-1;
            for(int i=n-1; i>=0; i--){
                if(posA==-1 && a[i]==0)posA=i;
                if(posB==-1 && a[i]==1)posB=i;
                if(posC==-1 && a[i]==2)posC=i;
                if(posD==-1 && a[i]==3)posD=i;
                if(posE==-1 && a[i]==4)posE=i;
            }
            if(posE!=-1){
                for(int i=3; i>=0; i--){
                    a[posE]=i;
                    ans=Math.max(ans, sum(a, n));
                }
                a[posE]=4;
            }
            if(posD!=-1){
                for(int i=2; i>=0; i--){
                    a[posD]=i;
                    ans=Math.max(ans, sum(a, n));
                }
                a[posD]=3;
            }
            if(posC!=-1){
                for(int i=1; i>=0; i--){
                    a[posC]=i;
                    ans=Math.max(ans, sum(a, n));
                }
                a[posC]=2;
            }
            if(posB!=-1){
                for(int i=0; i>=0; i--){
                    a[posB]=i;
                    ans=Math.max(ans, sum(a, n));
                }
                a[posB]=1;
            }
            pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}