#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int n, k;
vector<double> a;
bool check(double x){
    int cnt=0;
    for(int i=0; i<n; i++){
    	cnt+=floor(a[i]/x);
    }
    return cnt>=k;
}
int main()
{ 
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    a.resize(n);
    for(int i=0; i<n; i++)cin>>a[i];
    double l=0;
    double r=1e8;
    cout<<setprecision(20);
    for(int i=0; i<100; i++){
    	double m=(l+r)/2;
    	if(check(m)){
    		l=m;
    	}else{
            r=m;
    	}
    }
    cout<<l<<endl;
    return 0;
}