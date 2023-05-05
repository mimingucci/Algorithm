#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
int main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        bool hasZero=false;
        int a[n+1];
        for(int i=1; i<=n; i++)cin>>a[i];
        for(int i=1; i<=n/2; i++){
            if(a[i]==0 && a[n-i+1]==0){
                hasZero=true;
            }else{
                ans=gcd(abs(a[i]-a[n-i+1]), ans);
            }
        }
    if(ans==0 && hasZero){
        cout<<0<<'\n';
    }else{
        cout<<ans<<'\n';
    }
    }
    return 0;    
}