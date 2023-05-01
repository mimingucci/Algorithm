#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
    	int n, m;
        cin>>n>>m;
        std::vector<int> v(n+1);
        int sum=0;
        for(int i=1; i<=n; i++)
        {
                cin>>v[i];
                sum+=v[i];
        }
        std::vector<int> degree(n+1, 0);
        std::vector<pair<int, int>> adj;
        for(int i=1; i<=m; i++){
            int x, y;
            cin>>x>>y;
            adj.push_back({x, y});
            degree[x]++;
            degree[y]++;
        }
        if(m%2==0){
            cout<<0<<'\n';
            continue;
        }
        int ans=-1;
        for(auto it : adj){
            if(degree[it.first]%2==0 && degree[it.second]%2==0){
                ans=max(ans, sum-v[it.first]-v[it.second]);
            }
        }
        for(int i=1; i<=n; i++){
            if(degree[i]%2==1){
                ans=max(ans, sum-v[i]);
            }
        }
        cout<<sum-ans<<'\n';
    }
	return 0;
}