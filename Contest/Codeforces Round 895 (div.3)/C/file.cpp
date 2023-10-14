/*
author: mimingucci
created on: 9/8/2023 10:39:15 PM
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
         int l, r;
         cin>>l>>r;
         if(r<=3){
            cout<<-1<<'\n';
            continue;
         }
         bool isOk=false;
         for(int i=l; i<=r; i++){
            if(i%2==0 && i-2>1){
                cout<<2<<" "<<i-2<<'\n';
                isOk=true;
                break;
            }
            if(i%3==0 && i-3>1){
                cout<<3<<" "<<i-3<<'\n';
                isOk=true;
                break;
            }
            if(i%5==0 && i-5>1){
                cout<<5<<" "<<i-5<<'\n';
                isOk=true;
                break;
            }
            if(int(sqrt(i))*int(sqrt(i))==i && int(sqrt(i))>1 && i/int(sqrt(i))>1){
                cout<<int(sqrt(i))<<" "<<i-int(sqrt(i))<<'\n';
                isOk=true;
                break;
            }
         }
         if(isOk)continue;
         for(int i=2; i<=int(sqrt(l)); i++){
            if(l%i==0){
                cout<<i<<" "<<l-i<<'\n';
                isOk=true;
                break;
            }
         }
         if(isOk==false)
         cout<<-1<<'\n';
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */