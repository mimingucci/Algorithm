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
           String s1=r.next();
           String s2=r.next();
           if(s1.length()>s2.length()){
               s2="0".repeat(s1.length()-s2.length())+s2;
           }
           if(s2.length()>s1.length()){
               s1="0".repeat(s2.length()-s1.length())+s1;
               String tmp=s1;
               s1=s2;
               s2=tmp;
           }
           int[] a=new int[s1.length()];
           int[] b=new int[s1.length()];
           for(int i=0; i<s1.length(); i++){
               a[i]=s1.charAt(i)-'0';
           }
            for(int i=0; i<s1.length(); i++){
                b[i]=s2.charAt(i)-'0';
            }
            int sum=0;
            for(int i=0; i<s1.length(); i++){
                sum+=Math.abs(a[i]-b[i]);
            }
            int i=0;
            while(i<s1.length() && a[i]==b[i]){
                ++i;
            }
            if(i>=s1.length()){
                pw.println(0);
                continue;
            }
            int tmp=Math.abs(a[i]-b[i]);
            for(int j=i+1; j<s1.length(); j++){
                tmp+=9;
            }
            sum=Math.max(sum, tmp);
            pw.println(sum);
        }
        pw.close(); // flushes the output once printing is done
    }
}