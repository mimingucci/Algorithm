#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{ 
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll w, h, n;
    cin>>w>>h>>n;
    ll l=0;
    ll r=1;
    while((r/w)*(r/h)<n){
    	r*=2;
    }
    while(r>l+1){
    	ll m=(l+r)/2;
    	if((m/w)*(m/h)>=n){
    		r=m;
    	}else{
    		l=m;
    	}
    }
    cout<<r<<endl;   
    return 0;
}