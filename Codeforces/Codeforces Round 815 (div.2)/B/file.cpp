#include <bits/stdc++.h>
using namespace std;
#define ii int64_t
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
    	int n;
        cin>>n;
        ii maxI=-1; 
        ii maxII=-1;
        ii minI=1e9+1;
        ii minII=1e9+1;
        vector<ii> a(n);
        for(int i=0; i<n; i++){
        	cin>>a[i];
        }
        sort(begin(a), end(a));
        cout<<a.back()+a[n-2]-a.front()-a[1]<<'\n';

    }
	return 0;
}