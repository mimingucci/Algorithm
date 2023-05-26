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
           String s=r.next();
           if(n%2!=0){
               pw.println(-1);
               continue;
           }
           int open=0;
           int close=0;
           for(int i=0; i<n; i++){
               if(s.charAt(i)=='('){
                   ++open;
               }else{
                   ++close;
               }
           }
           if(open!=close){
               pw.println(-1);
               continue;
           }
           Vector<Integer> a=new Vector<>();
           int[] ans=new int[n];
           Arrays.fill(ans, 2);
           for(int i=0; i<n; i++){
               if(s.charAt(i)=='('){
                   a.add(i);
               }else{
                   if(!a.isEmpty()){
                       ans[i]=1;
                       ans[a.lastElement()]=1;
                       a.removeElementAt(a.size()-1);
                   }
               }
           }
           int cnt=0;
           for(int i=0; i<n; i++){
               if(ans[i]==2){
                   ++cnt;
                   break;
               }
           }
           if(cnt>0){
               a.removeAllElements();
               Arrays.fill(ans, 2);
               for(int i=0; i<n; i++){
                   if(s.charAt(i)==')'){
                       a.add(i);
                   }else{
                       if(!a.isEmpty()){
                           ans[i]=1;
                           ans[a.lastElement()]=1;
                           a.removeElementAt(a.size()-1);
                       }
                   }
               }
           }
           int maxx=0;
           for(int i=0; i<n; i++){
               if(ans[i]==2){
                   maxx=2;
                   break;
               }else{
                   maxx=1;
               }
           }
           pw.println(maxx);
           for(int i=0; i<n; i++){
               pw.print(ans[i]+" ");
           }
           pw.println();
        }
        pw.close(); // flushes the output once printing is done
    }
}
