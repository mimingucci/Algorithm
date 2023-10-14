#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int64_t n, q;
    cin>>n>>q;
    int64_t a[n+1];
    int64_t sum=0;
    vector<bool> isChanged;
    bool isToo=false;
    int64_t z;
    for(int64_t i=1; i<=n; i++)
    { 
       cin>>a[i];
       sum+=a[i];
    }
    while(q--){
        int64_t t;
        cin>>t;
        if(t==1){
            int64_t i, x;
            cin>>i>>x;
            if(!isToo){
              sum=sum+x-a[i];
              cout<<sum<<'\n';
              a[i]=x;
            }else{
               if(isChanged[i]){
                 sum=sum+x-a[i];
                 cout<<sum<<'\n';
                 a[i]=x;
               }else{
                 isChanged[i]=true;
                 sum=sum+x-z;
                 cout<<sum<<'\n';
                 a[i]=x;
               }
            }
        }else{
            int64_t x;
            isToo=true;
            cin>>x;
            sum=x*n;
            z=x;
            cout<<sum<<'\n';
            isChanged=vector<bool>(n+1, false);
        }
    }
	return 0;
} 
