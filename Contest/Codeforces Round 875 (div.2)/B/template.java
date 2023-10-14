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
            int[] a=new int[n];
            int[] b=new int[n];
            Set<Integer> sett=new HashSet<>();
            for(int i=0; i<n; i++){
                a[i]=r.nextInt();
                sett.add(a[i]);
            }
            for(int i=0; i<n; i++){
                b[i]=r.nextInt();
                sett.add(b[i]);
            }
            Map<Integer, Integer> mapp=new HashMap<>();
            int[] conA=new int[2*n+10];
            int[] conB=new int[2*n+10];
            conA[a[0]]++;
            for(int i=1; i<n; i++){
                if(a[i]!=a[i-1]){
                    if(mapp.get(a[i-1])==null) {
                        mapp.put(a[i - 1], conA[a[i - 1]]);
                    }else{
                        mapp.put(a[i - 1], Math.max(conA[a[i - 1]], mapp.get(a[i-1])));
                    }
                    conA[a[i-1]]=0;
                    conA[a[i]]++;
                }else{
                    conA[a[i]]++;
                }
            }
            if(mapp.get(a[n-1])==null){
                mapp.put(a[n-1], conA[a[n-1]]);
            }else{
                mapp.put(a[n - 1], Math.max(conA[a[n - 1]], mapp.get(a[n-1])));
            }
            conB[b[0]]++;
            Map<Integer, Integer> mappp=new HashMap<>();
            for(int i=1; i<n; i++){
                if(b[i]!=b[i-1]){
                    if(mappp.get(b[i-1])==null) {
                        mappp.put(b[i - 1], conB[b[i - 1]]);
                    }else{
                        mappp.put(b[i - 1], Math.max(conB[b[i - 1]], mappp.get(b[i-1])));
                    }
                    conB[b[i-1]]=0;
                    conB[b[i]]++;
                }else{
                    conB[b[i]]++;
                }
            }
            if(mappp.get(b[n-1])==null){
                mappp.put(b[n-1], conB[b[n-1]]);
            }else{
                mappp.put(b[n - 1], Math.max(conB[b[n - 1]], mappp.get(b[n-1])));
            }
            int ans=0;
            for(int x : sett){
                ans=Math.max(ans, (mapp.get(x)==null ? 0 : mapp.get(x))+(mappp.get(x)==null ? 0 : mappp.get(x)));
            }
            pw.println(ans);
        }
        pw.close(); // flushes the output once printing is done
    }
}