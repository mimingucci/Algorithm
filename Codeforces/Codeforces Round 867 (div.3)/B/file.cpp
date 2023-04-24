#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii int64_t
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
    	int n;
        cin>>n;
        vector<ii> a(n);
        for(int i=0; i<n; i++)cin>>a[i];
        sort(begin(a), end(a));
        cout<<max(a[0]*a[1], a[n-1]*a[n-2])<<'\n';
    }
	return 0;
}