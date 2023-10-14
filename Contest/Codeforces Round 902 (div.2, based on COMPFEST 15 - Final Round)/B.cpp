#include<bits/stdc++.h>
using namespace std;
#define int int64_t
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n, p;
		cin>>n>>p;
		vector<pair<int, int>> arr(n);
		for(int i=0; i<n; i++){
			int sc;
			cin>>sc;
			arr[i].second=sc;
		}
		for(int i=0; i<n; i++){
			int f;
			cin>>f;
			arr[i].first=f;
		}
		sort(begin(arr), end(arr), [&](pair<int, int> a, pair<int, int> b){
			if(a.first==b.first){
				return a.second>b.second;
			}else{
				return a.first<b.first;
			}
		});
		int ans=p;
		int now=0;
		int pivot=0;
		while(pivot<n-1){
			if(arr[now].first>p){
				ans+=p*(n-1-pivot);
                break;
			}
			while(pivot<n-1 && arr[now].second>0){
				arr[now].second--;
				pivot++;
				ans+=arr[now].first;
			}
			if(pivot==n-1)break;
			++now;
		}
		ans=min(ans, p*n);
		cout<<ans<<'\n';
	}
}