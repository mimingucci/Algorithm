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

    public static class Point{
        double x;
        double y;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }

    public static class Triangle implements Comparable{
        Point A;
        Point B;
        Point C;
        Double Area;

        public Triangle(Point a, Point b, Point c) {
            A = a;
            B = b;
            C = c;
            Area=area(A, B, C);
        }

        @Override
        public int compareTo(Object o) {
            double compare=this.Area-((Triangle)o).Area;
            if(compare<0){
                return -1;
            }else{
                if(compare>0){
                    return 1;
                }else{
                    return 0;
                }
            }
        }
    }

    static double area(Point A, Point B, Point C){
        return ((double)1/2)*Math.abs((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y));
    }

    static boolean inTriangle(Point p, Triangle t){
        if(area(p, t.A, t.B)+area(p, t.A, t.C)+area(p, t.B, t.C)==t.Area){
            return true;
        }else{
            return false;
        }
    }

    public static void main(String[] args) {
        int n=r.nextInt();
        Triangle[] a=new Triangle[n];
        for(int i=0; i<n; i++){
            double xA=r.nextDouble();
            double yA=r.nextDouble();
            double xB=r.nextDouble();
            double yB=r.nextDouble();
            double xC=r.nextDouble();
            double yC=r.nextDouble();
            Point A=new Point(xA, yA);
            Point B=new Point(xB, yB);
            Point C=new Point(xC, yC);
            a[i]=new Triangle(A, B, C);
        }
        Arrays.sort(a);
        int[] f=new int[n];
        for(int i=0; i<n; i++){
            f[i]=1;
            for(int j=0; j<i; j++){
                if(f[j]>=f[i]){
                    if(a[j].Area<=a[i].Area && inTriangle(a[j].A, a[i]) && inTriangle(a[j].B, a[i]) && inTriangle(a[j].C, a[i])){
                        f[i]=f[j]+1;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans=Math.max(ans, f[i]);
        }
        pw.println(ans);
        pw.close(); // flushes the output once printing is done
    }
}
