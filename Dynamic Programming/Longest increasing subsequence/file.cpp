#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)cin>>a[i];
    int length[n];
    for(int i=0; i<n; i++){
    	length[i]=1;
    	for(int j=0; j<i; j++){
           if(a[j]<a[i]){
           	length[i]=max(length[i], length[j]+1);
           }
    	}
    }
    cout<<*max_element(begin(length), end(length));
	return 0;
}