/*
author: mimingucci
created on: 10/2/2023 8:20:27 PM
*/
#include <bits/stdc++.h>
using namespace std;

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    //find all prime numbers less than n
    int n;
    cin>>n;
    if(n<=2){
    	exit(0);
    }
    std::vector<bool> prime(n, true);
    prime[0]=false;
    prime[1]=false;
    for(int i=2; i*i<n; i++){
       if(prime[i]){
       	for(int j=i; j*i<n; j++){
       		prime[j*i]=false;
       	}
       }
    }
    for(int i=2; i<n; i++){
    	if(prime[i]){
    		cout<<i<<" ";
    	}
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */