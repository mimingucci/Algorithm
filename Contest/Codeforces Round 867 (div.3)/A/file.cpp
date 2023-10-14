#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii int64_t
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
    	int n, t;
        cin>>n>>t;
        int a[n+1];
        int b[n+1];
        for(int i=1; i<=n; i++)cin>>a[i];
        for(int i=1; i<=n; i++)cin>>b[i];
        int ans=-1;
        int index=-1;
        for(int i=1; i<=n; i++){
            if(i-1+a[i]<=t){
                if(b[i]>ans){
                    ans=b[i];
                    index=i;
                }
            }
        }
        cout<<index<<'\n';
    }
	return 0;
}