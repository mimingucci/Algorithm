public class XYPoint {

    int x, y;

    XYPoint(int x, int y) {

        this.x = x;
        this.y = y;
    }

    static int ccw(XYPoint a, XYPoint b, XYPoint c){
        return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
    }

}

public class ConvexHull {
    //it will store all the Convex Hull Points

    private Stack < XYPoint > hull = new Stack < XYPoint > ();

    public ConvexHull(XYPoint[] pts) {

        int N = pts.length;
        XYPoint[] points = new XYPoint[N];
        for (int trev = 0; trev < N; trev++)
            points[trev] = pts[trev];

        //it will sort all the points
        Arrays.sort(points);

        hull.push(points[0]);

        int jj1;
        for (jj1 = 1; jj1 < N; jj1++)
            if (!points[0].equals(points[jj1])) break;
        if (jj1 == N) return;

        int jj2;
        for (jj2 = jj1 + 1; jj2 < N; jj2++)
            if (XYPoint.ccw(points[0], points[jj1], points[jj2]) != 0) break;
        hull.push(points[jj2 - 1]);

        for (int i = jj2; i < N; i++) {
            XYPoint top = hull.pop();
            while (XYPoint.ccw(hull.peek(), top, points[i]) <= 0) {
                top = hull.pop();
            }
            hull.push(top);
            hull.push(points[i]);
        }

    }

    public Iterable < XYPoint > hull() {
        Stack < XYPoint > stk = new Stack < XYPoint > ();
        for (XYPoint p: hull) stk.push(p);
        return stk;
    }
}