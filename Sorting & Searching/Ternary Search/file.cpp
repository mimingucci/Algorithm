#include <bits/stdc++.h>
using namespace std;
double ternary_search(double l, double r){
	double epsinon=1e-9;
	while(r-l>epsinon){
		double x=f(l+(r-l)/3);
		double y=f(r-(r-l)/3);
		if(x<y){
           l=l+(r-l)/3;
		}else{
			r=r-(r-l)/3;
		}
	}
	return f(l);
}