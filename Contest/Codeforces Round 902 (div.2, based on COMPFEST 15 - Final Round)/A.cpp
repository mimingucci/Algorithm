#include<bits/stdc++.h>
using namespace std;
#define int int64_t
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum=0;
		for(int i=1; i<n; i++){
			int x;
			cin>>x;
			sum+=x;
		}
		cout<<-sum<<'\n';
	}
}