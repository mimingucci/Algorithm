#include <bits/stdc++.h>
using namespace std;
#define ii int64_t
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
    	ii n, k;
    	cin>>n>>k;
    	if(k%4==0){
    		cout<<"NO"<<'\n';
    	}else{
    		if(k%4==1 || k%4==3){
    			cout<<"YES"<<'\n';
    			for(ii i=1; i<=n; i+=2){
    				cout<<i<<" "<<i+1<<'\n';
    			}
    		}else{
    			cout<<"YES"<<'\n';
    			ii cnt=0;
    			for(ii i=1; i<=n; i+=2){
    				if(cnt%2==0){
    					cout<<i+1<<" "<<i<<'\n';
    				}else{
    					cout<<i<<" "<<i+1<<'\n';
    				}
    				++cnt;
    			}
    		}
    	}
    }
	return 0;
}