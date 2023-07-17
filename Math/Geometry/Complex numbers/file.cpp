#include <bits/stdc++.h>
using namespace std;
#define x real()
#define y imag()
typedef double T;
typedef complex<T> P;
T cross(P a, P b) { return a.x*b.y-a.y*b.x; }
T cross(P p, P a, P b) { return cross(a-p,b-p); }
P dir(T ang) { return polar((T)1,ang); }
P unit(P p) { return p/abs(p); }
T dot(P a, P b) { return a.x*b.x+a.y*b.y; }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	P a={1, 2};
	P b={2, -1};
	P v = {4,2};
	// Hàm arg trả về góc hợp bởi vector v và trục x (đơn vị radian)(*180/pi độ)
    cout << arg(v) << "\n"; // 0.463648
    // Hàm polar(s, a) trả về vector có độ dài s và góc với trục Ox là a radian
    // Để quay một vector một góc x radian ta nhân vector đó với polar(1, x) 
    v *= polar(1.0,0.5);
    cout << arg(v) << "\n"; // 0.963648
	return 0;
}
