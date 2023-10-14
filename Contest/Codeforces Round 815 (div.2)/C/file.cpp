#include <bits/stdc++.h>
using namespace std;
#define ii int64_t
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int a[n][m];
        string s;
        int total=0;
        for(int i=0; i<n; i++){
            cin>>s;
            for(int j=0; j<m; j++){
                a[i][j]=s[j]-'0';
                total+=a[i][j];
            }
        }
        if(total==0){
            cout<<0<<'\n';
        }else{
            int minn=4;
            for(int i=0; i<n-1; i++){
                for(int j=0; j<m-1; j++){
                    int cnt=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
                    minn=min(minn, cnt);
                }
            }
            if(minn>=3){
                cout<<total-(minn-2)<<'\n';
            }else{
                cout<<total<<'\n';
            }
        }	
        
    }
	return 0;
}