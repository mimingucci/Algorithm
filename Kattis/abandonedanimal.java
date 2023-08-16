import java.io.*;
import java.math.BigInteger;
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
        int n=r.nextInt();
        Map<Integer, Set<String>> data=new HashMap<>();
        for(int i=0; i<n; i++)data.put(i, new HashSet<>());
        int k=r.nextInt();
        for(int i=0; i<k; i++){
             int index=r.nextInt();
             String item=r.next();
             data.get(index).add(item);
        }
        int m=r.nextInt();
        if(m<=0){
            pw.println("ambiguous");
        }else {
            String[] sequence = new String[m];
            Map<String, Integer> lastOccur=new HashMap<>();
            for (int i = 0; i < m; i++) {
                sequence[i] = r.next();
            }
            int[][] a=new int[m][2];
            for(int i=0; i<m; i++)Arrays.fill(a[i], -1);
            boolean multi = false;
            int now = 0;
            for (int i = 0; i < n; i++) {
                if(data.get(i).size()==0)continue;;
                if (now < m) {
                    Set<String> used = new HashSet<>();
                    while (now < m) {
                        if (data.get(i).contains(sequence[now]) && !used.contains(sequence[now])) {
                            a[now][0] = i;
                            used.add(sequence[now]);
                            lastOccur.put(sequence[now], now);
                            ++now;
                        } else {
                            break;
                        }
                    }
                }
                for (String x : data.get(i)) {
                    if (lastOccur.get(x)!=null && a[lastOccur.get(x)][0] > -1 && a[lastOccur.get(x)][0] != i && a[lastOccur.get(x)][1] == -1) {
                        a[lastOccur.get(x)][1] = i;
                    }
                }
            }
            if (now < m) {
                pw.println("impossible");
            } else {
                if (a[m - 1][1] > -1) {
                    multi = true;
                }
                if (multi) {
                    pw.println("ambiguous");
                } else {
                    now = a[m - 1][0];
                    for (int i = m - 2; i >= 0; i--) {
                        if (a[i][1] > -1 && a[i][1] <= now) {
                            multi = true;
                            break;
                        } else {
                            now = a[i][0];
                        }
                    }
                    if (multi) {
                        pw.println("ambiguous");
                    } else {
                        pw.println("unique");
                    }
                }
            }
        }
        pw.close(); // flushes the output once printing is done
    }
}
