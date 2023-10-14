/*
author: mimingucci
created on: 9/8/2023 4:55:31 AM
*/
#include <bits/stdc++.h>
using namespace std;
const int INF=(int)1e8;

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
         int n;
         cin>>n;
         std::vector<int> d(201, INF);
         for(int i=0; i<n; i++){
         	int x, s;
         	cin>>x>>s;
         	d[x]=min(d[x], s);
         }
         int left=1;
         int right=1000;
         while(left<right-1){
         	int mid=left+right>>1;
         	bool isOk=true;
         	for(int i=1; i<=min(mid, int(200)); i++){
         		if(mid-1+mid-i>=i-1+d[i]){
         			isOk=false;
         			break;
         		}
         	}
         	if(isOk){
         		left=mid;
         	}else{
         		right=mid-1;
         	}
         }
         bool isOk=true;
         for(int i=1; i<=min(200, right); i++){
         		if(right-1+right-i>=i-1+d[i]){
         			isOk=false;
         			break;
         		}
         }
         if(isOk){
         	cout<<right<<'\n';
         }else{
         	cout<<left<<'\n';
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