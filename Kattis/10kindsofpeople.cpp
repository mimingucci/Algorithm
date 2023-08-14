#include <bits/stdc++.h>
using namespace std;
#define int int64_t

string a[1001];

int status[1001][1001];

int row;
int column;

int x[] = {1, -1, 0, 0};

int y[] = {0, 0, 1, -1};

void floodfill(int r, int c, int now) {
    status[r][c] = now;
    for (int i = 0; i < 4; i++) {
        if (r + x[i] < 0 || r + x[i] >= row) continue;
        if (c + y[i] < 0 || c + y[i] >= column) continue;
        if (status[r + x[i]][c + y[i]] > 0) continue;
        if (a[r + x[i]][c + y[i]] != a[r][c]) continue;
        floodfill(r + x[i], c + y[i], now);
    }
}

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    cin>>row;
    cin>>column;
    for (int i = 0; i < row; i++) {
        cin>>a[i];
    }
    int now = 1;
    int n;
    cin>>n;
    while (n--) {
        int r1, c1, r2, c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;
        c1--;
        r2--;
        c2--;
        if (status[r1][c1] == 0 && status[r2][c2] > 0) {
            cout<<"neither"<<'\n';
            continue;
        }
        if (status[r1][c1] > 0 && status[r2][c2] == 0) {
            cout<<"neither"<<'\n';
            continue;
        }
        if (status[r1][c1] == 0 && status[r2][c2] == 0) {
            floodfill(r1, c1, now);
            now++;
        }
        if (status[r1][c1] != status[r2][c2]) {
            cout<<"neither"<<'\n';
        } else {
            if (a[r1][c1] == '0') {
                cout<<"binary"<<'\n';
            } else {
                cout<<"decimal"<<'\n';
            }
        }
    }
}