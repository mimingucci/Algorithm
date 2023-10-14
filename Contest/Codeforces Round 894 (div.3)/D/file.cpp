#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define sort(A) sort(A.begin(), A.end())
#define input(A) for(auto &x : A)cin>>x
#define output(A) for(auto &x : A)cout<<x<<" "
#define dbg(v) cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';
#define bit(n, i) ((n>>i)&1)
#define PI (2 * acos(0.0))

int sum(int n){
    if(n%2==0){
        return (n+1)*(n/2);
    }else{
        return (n+1)*(n/2)+(n+1)/2;
    }
}

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       int left=2;
       int right=2648956421;
       while(left<right-1){
        int mid=left+right>>1;
        if(sum(mid-1)+mid>=n){
            right=mid;
        }else{
            left=mid;
        }
       }
       int ans=(int)10000000000000;
        for(int i=max(left-10, (int)1); i<=min(right+10,(int) 2648956421); i++){
            if(sum(i-1)>n)continue;
            ans=min(ans, max((int) 0, n-sum(i-1))+i);
        }
        cout<<ans<<'\n';
    } 
}