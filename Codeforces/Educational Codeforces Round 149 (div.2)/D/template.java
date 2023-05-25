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
           Pair<Integer, Integer> data[]=new Pair[n];
           if(s.charAt(0)=='('){
               data[0]=new Pair<>(1, 0);
           }else{
               data[0]=new Pair<>(0, 1);
           }
           for(int i=1; i<n; i++){
               if(s.charAt(i)=='('){
                   data[i]=new Pair<>(data[i-1].getFirst()+1, data[i-1].getSecond());
               }else{
                   data[i]=new Pair<>(data[i-1].getFirst(), data[i-1].getSecond()+1);
               }
           }
           int cnt=0;
           int[] ans=new int[n];
           int now=0;
               if(s.charAt(0)=='('){
                   for(int i=0; i<n; i++){
                       if(data[i].getFirst()==(data[n-1].getSecond()-data[i].getSecond())){
                           cnt=data[i].getFirst();
                           for(int j=0; j<=i; j++){
                               if(s.charAt(j)=='('){
                                   ans[j]=1;
                               }
                           }
                           for(int j=i+1; j<n; j++){
                               if(s.charAt(j)==')'){
                                   ans[j]=1;
                               }
                           }
                           break;
                       }
                   }
               }
            if(s.charAt(0)==')'){
                for(int i=0; i<n; i++){
                    if(data[i].getSecond()==(data[n-1].getFirst()-data[i].getFirst())){
                        cnt=data[i].getSecond();
                        for(int j=0; j<=i; j++){
                            if(s.charAt(j)==')'){
                                ans[j]=1;
                            }
                        }
                        for(int j=i+1; j<n; j++){
                            if(s.charAt(j)=='('){
                                ans[j]=1;
                            }
                        }
                        break;
                    }
                }
            }
            now=0;
            while(now<n){
                if(ans[now]==0){
                    break;
                }else{
                    ++now;
                }
            }
            if(now<n){
                int need=(n-cnt*2)/2;
                if(s.charAt(now)=='('){
                    int i=now;
                    while(need>0){
                        if(s.charAt(i)=='(' && ans[i]==0){
                            ans[i]=2;
                            --need;
                        }
                        ++i;
                    }

                }else{
                    int i=now;
                    while(need>0){
                        if(s.charAt(i)==')' && ans[i]==0){
                            ans[i]=2;
                            --need;
                        }
                        ++i;
                    }
                }
            }
            if(now>=n){
                pw.println(1);
                for(int i=0; i<n; i++){
                    pw.print(1+" ");
                }
                pw.println();
            }else{
                pw.println(2);
                for(int i=0; i<n; i++){
                    if(ans[i]>0){
                        pw.print(ans[i]+" ");
                    }else{
                        pw.print(2+" ");
                    }
                }
                pw.println();
            }
        }
        pw.close(); // flushes the output once printing is done
    }
}
