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
            int[] a=new int[n+1];
            int positionOne=-1;
            int positionTwo=-1;
            int positionN=-1;
            for(int i=1; i<=n; i++){
                a[i]=r.nextInt();
                if(a[i]==1){
                    positionOne=i;
                }else{
                    if(a[i]==2){
                        positionTwo=i;
                    }else{
                        if(a[i]==n){
                            positionN=i;
                        }
                    }
                }
            }
            if(positionOne<positionN && positionTwo<positionN){
                if(positionOne>positionTwo){
                    pw.println(positionOne+" "+positionN);
                }else{
                    pw.println(positionTwo+" "+positionN);
                }
                continue;
            }
            if(positionN<positionOne && positionN<positionTwo){
                if(positionOne>positionTwo){
                    pw.println(positionTwo+" "+positionN);
                }else{
                    pw.println(positionOne+" "+positionN);
                }
                continue;
            }
            pw.println(1+" "+1);
        }
        pw.close(); // flushes the output once printing is done
    }
}
