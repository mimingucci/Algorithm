#include <bits/stdc++.h>
using namespace std;
#define ii int64_t
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
    	int a, b;
    	cin>>a>>b;
    	if(a==1 && b==1){
    		cout<<"Tonya"<<'\n';
    	}else{
    		if(a%2==0 && b%2==0){
    			cout<<"Tonya"<<'\n';
    		}else{
    			if(a%2!=0 && b%2!=0){
    				cout<<"Tonya"<<'\n';
    			}else{
    				cout<<"Burenka"<<'\n';
    			}
    		}
    	}
    }
	return 0;
}