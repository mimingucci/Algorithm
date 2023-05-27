#include <bits/stdc++.h>
using namespace std;

int main()
{ 
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    double c;
    cin>>c;
    double l=0;
    double r=1e4;
    cout<<setprecision(16);
    for(int i=0; i<100; i++){
    	double m=(l+r)/2;
    	if(pow(m, 4)+m>=c){
    		r=m;
    	}else{
    		l=m;
    	}
    }
    cout<<l*l;
    
    return 0;
    
}