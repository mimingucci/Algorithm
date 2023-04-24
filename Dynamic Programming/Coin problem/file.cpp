#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin>>n>>k;
    int coins[n];
    for(int i=0; i<n; i++)cin>>coins[i];
    int value[k+1];
    value[0]=0;
    for(int i=1; i<=k; i++){
    	value[i]=INT_MAX;
    	for(int c : coins){
    	   if(i-c>=0)
           value[i]=min(value[i], value[i-c]+1);
    	}
    }
    cout<<value[k]<<'\n';
	return 0;
}