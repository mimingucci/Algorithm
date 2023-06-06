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

    public static void main(String[] args) {
        int t=r.nextInt();
        while((t--)>0){
           String a=r.next();
           String b=r.next();
           char[] aa=new char[a.length()+1];
           char[] bb=new char[b.length()+1];
           int diff=0;
           for(int i=1; i<=a.length(); i++){
               aa[i]=a.charAt(i-1);
               bb[i]=b.charAt(i-1);
               if(aa[i]!=bb[i])++diff;
           }
           boolean[] isBlocked=new boolean[a.length()+1];
           int time=r.nextInt();
           int q=r.nextInt();
            int[] lock=new int[q+1+time];
           for(int i=1; i<=q; i++){
               if(lock[i-1]!=0){
                   if(aa[lock[i-1]]!=bb[lock[i-1]])++diff;
               }
               isBlocked[lock[i-1]]=false;
               int type=r.nextInt();
               if(type==1){
                   int pos=r.nextInt();
                   lock[i+time-1]=pos;
                   isBlocked[pos]=true;
                   if(aa[pos]!=bb[pos])--diff;
               }
               if(type==2){
                   int x, y, m, n;
                   x=r.nextInt();
                   y=r.nextInt();
                   m=r.nextInt();
                   n=r.nextInt();
                   if(y!=n){
                       if(aa[y]!=bb[y]){
                           --diff;
                       }
                       if(aa[n]!=bb[n]){
                           --diff;
                       }
                   }
                   if(x==1 && m==1){
                      char tmp=aa[y];
                      aa[y]=aa[n];
                      aa[n]=tmp;
                   }
                   if(x==1 && m==2){
                       char tmp=aa[y];
                       aa[y]=bb[n];
                       bb[n]=tmp;
                   }
                   if(x==2 && m==1){
                       char tmp=bb[y];
                       bb[y]=aa[n];
                       aa[n]=tmp;
                   }
                   if(x==2 && m==2){
                       char tmp=bb[y];
                       bb[y]=bb[n];
                       bb[n]=tmp;
                   }
                   if(y!=n){
                       if(aa[y]!=bb[y])++diff;
                       if(aa[n]!=bb[n])++diff;
                   }
               }
               if(type==3){
                   if(diff==0){
                       pw.println("YES");
                   }else{
                       pw.println("NO");
                   }
               }
           }
        }
        pw.close(); // flushes the output once printing is done
    }
}
