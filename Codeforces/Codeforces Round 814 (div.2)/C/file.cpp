#include <bits/stdc++.h>
using namespace std;
#define ii int64_t
int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		ii n, q;
		cin>>n>>q;
		vector<ii> a(n);
		vector<ii> big(n, 0);
		unordered_map<ii, ii> mapp;
		ii x, y;
		for(ii i=0; i<n; i++){
			cin>>a[i];
			mapp[a[i]]=i;
			if(i==0){
				big[i]=a[i];
			}else{
				big[i]=max(a[i], big[i-1]);
			}
		}
		for(ii i=1; i<=q; i++){
			cin>>x>>y;
			if(mapp[n]==0){
				if(x==1){
					cout<<y<<'\n';
				}else{
					cout<<0<<'\n';
				}
				continue;
			}
			if(x==mapp[n]+1){
				cout<<max((ii)0, y-(mapp[n]-1))<<'\n';
			}else{
				ii f=upper_bound(begin(big), end(big), a[x-1])-begin(big);
				if(f<x-1){
					cout<<0<<'\n';
				}else{
					if(y<x-1){
						cout<<0<<'\n';
					}else{
						if(y<f){
							cout<<y-max((ii)0, x-2)<<'\n';
						}else{
							cout<<f-(x-1)-(x==1)<<'\n';
						}
					}
				}
			}
		}
	}
	return 0;
}