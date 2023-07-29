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
          int[] a=new int[n];
          for(int i=0; i<n; i++)a[i]=r.nextInt();
          int[] upp=new int[n];
          int[] downn=new int[n];
          int left=0;
          int right=0;
        while(true){
            if(right+1>=n){
                break;
            }
            if(left==right){
                if(a[left]==0){
                    if(a[right+1]>0){
                        ++right;
                    }else{
                        break;
                    }
                }else{
                    if(a[right+1]>=a[left]){
                        ++right;
                    }else{
                        break;
                    }
                }
            }else{
                if(a[right+1]>=a[right]){
                    ++right;
                }else{
                    break;
                }
            }
        }
        upp[left]=right;
        for(int i=1; i<n; i++) {
            if (right < i) {
                right = i;
            }
            left=i;
            while(true){
                if(right+1>=n){
                    break;
                }
                if(left==right){
                    if(a[left]==0){
                        if(a[right+1]>0){
                            ++right;
                        }else{
                            break;
                        }
                    }else{
                        if(a[right+1]>=a[left]){
                            ++right;
                        }else{
                            break;
                        }
                    }
                }else{
                    if(a[right+1]>=a[right]){
                        ++right;
                    }else{
                        break;
                    }
                }
            }
            upp[i]=right;
        }
          left=0;
          right=0;
          while(true){
              if(right+1>=n){
                  break;
              }
              if(left==right){
                  if(a[left]==0){
                      break;
                  }else {
                      if (a[right + 1] <= a[left]) {
                          ++right;
                      } else {
                          break;
                      }
                  }
              }else{
                  if(a[right]==0)break;
                  if(a[right+1]<=a[right]){
                      ++right;
                  }else{
                      break;
                  }
              }
          }
          downn[left]=right;
          for(int i=1; i<n; i++) {
              if (right < i) {
                  right = i;
              }
              left=i;
              while(true){
                  if(right+1>=n){
                      break;
                  }
                  if(left==right){
                      if(a[left]==0){
                          break;
                      }else {
                          if (a[right + 1] <= a[left]) {
                              ++right;
                          } else {
                              break;
                          }
                      }
                  }else{
                      if(a[right]==0)break;
                      if(a[right+1]<=a[right]){
                          ++right;
                      }else{
                          break;
                      }
                  }
              }
              downn[i]=right;
          }
          int[] f=new int[n+1];
          f[n]=0;
          for(int i=n-1; i>=0;  i--){
              int cnt=Integer.MAX_VALUE;
              cnt=min(cnt, 1+f[upp[i]+1]);
              cnt=min(cnt, 1+f[downn[i]+1]);
              if(a[upp[i]]==2 && upp[i]>i){
                  cnt=min(cnt, f[upp[i]]);
              }
              if(a[downn[i]]==2 && downn[i]>i){
                  cnt=min(cnt, f[downn[i]]);
              }
              if(downn[i]+1<n && a[downn[i]+1]==2 && a[downn[i]]>0){
                  cnt=min(cnt, f[downn[i]+1]);
              }
              f[i]=cnt;
          }
          pw.println(f[0]);
        pw.close(); // flushes the output once printing is done
    }
}




