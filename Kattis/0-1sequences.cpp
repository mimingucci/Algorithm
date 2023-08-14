#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int MOD=1e9+7;

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>s;
    int one=0;
    int branch=1;
    int inversion=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='1'){
            one=(one+branch)%MOD;
        }else{
            if(s[i]=='0'){
               inversion=(inversion+one)%MOD;
            }else{
               inversion = (2 * inversion + one) % MOD;
               one = (2 * one + branch) % MOD;
               branch = 2 * branch % MOD;
            }
        }
    }
    cout<<inversion;
}


