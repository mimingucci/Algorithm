#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int maxx=1e9;
    int f[102][201];
    int n;
    cin>>n;
    std::vector<pair<int, int>> data;
    data.push_back({0, 0});
    while(data.size()<101){
       int x, y;
       cin>>x>>y;
       data.push_back({x, y});
       if(x==n){
        break;
       }
    }
    if(data.back().first<n)
       data.push_back({n, maxx});
    int sz=data.size()-1;
    for (int i = 0; i <= sz; i++) {
        for (int j = 0; j <= 200; j++) {
            f[i][j] = maxx;
        }
    }
    f[0][100] = 0;

    for (int i = 1; i <= sz; i++) {
        int d = data[i].first - data[i - 1].first;

        for (int j = d; j <= 200; j++)
            f[i][j - d] = f[i - 1][j];

        for (int j = 1; j <= 200; j++)
            f[i][j] = min(f[i][j], f[i][j - 1] + data[i].second);
    }

    int ans = maxx;
    for (int i = 100; i <= 200; i++)
        ans = min(ans, f[sz][i]);

    if (ans >= maxx)
        cout << "Impossible" << '\n';
    else
        cout << ans << '\n';
}


