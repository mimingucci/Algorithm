#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
    	int64_t n;
    	cin>>n;
    	if(n<4 || n%2!=0){
    		cout<<-1<<'\n';
    		continue;
    	}
        int64_t minn, maxx;
        for(int64_t i=0; i<5; i++){
        	if((n-i*4)%6==0){
        		minn=(n-i*4)/6+i;
        		break;
        	}
        }
        for(int64_t i=0; i<5; i++){
        	if((n-i*6)%4==0){
        		maxx=(n-i*6)/4+i;
        		break;
        	}
        }
        cout<<minn<<" "<<maxx<<'\n';
    }
	return 0;
} 
