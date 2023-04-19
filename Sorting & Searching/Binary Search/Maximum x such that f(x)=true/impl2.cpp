#include <bits/stdc++.h>
using namespace std;

int last_true(int lo, int hi, function<bool(int)> f) {
	lo--;
	for (int dif = hi - lo; dif > 0; dif /= 2) {
		while (lo + dif <= hi && f(lo + dif)) { lo += dif; }
	}
	return lo;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cout<<last_true(2, 10, [](int x){return true;});
	return 0;
}