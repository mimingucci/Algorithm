#include <bits/stdc++.h>
using namespace std;
#define ii int64_t
ii gcd(ii a, ii b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
    	ii a, b, c, d;
    	cin>>a>>b>>c>>d;
        if(a==0 || c==0){
        	if(a==0 && c==0){
        		cout<<0<<'\n';
        	}else{
        		cout<<1<<'\n';
        	}
        }else{
        	ii f=gcd(a, b);
        	ii sc=gcd(c, d);
        	a/=f;
        	b/=f;
        	c/=sc;
        	d/=sc;
        	if(a==c && b==d){
        		cout<<0<<'\n';
        		continue;
        	}
        	ii x1=((b*c)/d)/a;
        	ii y1=((a*d)/c)/b;
        	ii x2=((a*d)/b)/c;
        	ii y2=((b*c)/a)/d;
        	if(x1*a*d==b*c || y1*b*c==a*d || x1*c*b==a*d || y2*d*a==b*c){
        		cout<<1<<'\n';
        	}else{
        		cout<<2<<'\n';
        	}
        }
    }   
	return 0;
}