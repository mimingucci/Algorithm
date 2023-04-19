#include <bits/stdc++.h>
using namespace std;

int first_true(int lo, int hi, function<bool(int)> f){
	hi++;
	while(lo<hi){
		int mid=lo+(hi-lo)/2;
		if(f(mid)){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	return lo;
}
int main(){
	cout << first_true(2, 10, [](int x) { return true; }) << '\n';
	return 0;
}