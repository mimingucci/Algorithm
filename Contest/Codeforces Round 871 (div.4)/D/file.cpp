#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vdl vector<double long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vpil vector<pair<int, long long>>
#define vpli vector<pair<long long, int>>
#define ii int64_t
#define sort(A) sort(A.begin(), A.end())
#define input(A) for(auto &x : A)cin>>x
#define output(A) for(auto &x : A)cout<<x<<" "
#define dbg(v) cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';
#define bit(n, i) ((n>>i)&1)
int main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
       int64_t a, b;
       cin>>a>>b;
       if(b>a){
        cout<<"NO"<<'\n';
        continue;
       }
       bool isOk=false;
       for(int64_t i=0; i<=30; i++){
        if(isOk){
            break;
        }
        int64_t tmp=a;
        for(int64_t j=0; j<i; j++)tmp*=2;
        for(int64_t j=0; j<=30; j++){
            if(tmp==b && j>=i){
                isOk=true;
                break;
            }
            if(tmp%3==0){
                tmp/=3;
            }else{
                break;
            }
        }
       }
       if(isOk){
        cout<<"YES"<<'\n';
       }else{
        cout<<"NO"<<'\n';
       }
    }
    return 0;    
}