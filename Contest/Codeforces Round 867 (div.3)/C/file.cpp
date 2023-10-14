#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii int64_t
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
    	ii n;
        cin>>n;
        ii ans=3*n+2+n-1+n-2;
        ii r=2*(n-1)-2;
        cout<<ans+1+(r/2)*(r/2+1)<<'\n';
    }
	return 0;
}