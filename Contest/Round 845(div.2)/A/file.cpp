#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vdl vector<double long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vpil vector<pair<int, long long>>
#define vpli vector<pair<long long, int>>
#define ii int64_t
#define sort(A) sort(A.begin(), A.end())
#define input(A) for(auto &x : A)cin>>x
#define output(A) for(auto &x : A)cout<<x<<" "
#define dbg(v) cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';
#define bit(n, i) ((n>>i)&1)
const ii mod=1e9+7;
long long gcd(long long a, long long b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
long long lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

bool isPrime(ll n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (ll i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
        return false;

    return true;
}

int nextPrime(ll n)
{

    if (n <= 1)
        return 2;

    bool prime = false;

    while(!prime)
    {
        n++;
        if(isPrime(n))
        {
            prime = true;
        }
    }
    return n;
}

int add(int a, int b) {
	while (b > 0) {
		int carry = a & b;
		a ^= b;
		b = carry << 1;
	}
	return a;
}


int prod(int a, int b) {
	int c = 0;
	while (b > 0) {
		if ((b & 1) == 1) {
			c = add(c, a);  // Use the addition function we coded previously
		}
		a <<= 1;
		b >>= 1;
	}
	return c;
}

bool check(int x){
    if(x==pow((int)sqrt(x), 2)){
        return true;
    }else{
        return false;
    }
}

ii c(ii a, ii b){
    ii ret = 1;
    a %= mod;
    b %= mod - 1;
    while (b > 0) //vòng lặp phân tích b thành cơ số 2
    {
        if (b % 2 > 0)  //ở vị trí có số 1 thì nhân với a^(2^i) tương ứng. Tất cả các phép nhân đều có phép mod p theo sau.
            ret = ret * a % mod;
        a = a * a % mod;  //tính tiếp a^(2^(i+1)), a^1 -> a^2 -> a^4 -> a^8 -> a^16 v.v...
        b /= 2;
    }
    return (ii) ret;
}
int main()
{ 
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    ii t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       int even=0;;
       int odd=0;
       int ans=0;
       for(int i=1; i<=n; i++){
          int x;
          cin>>x;
          if(x%2==0){
            if(even>0){
                ++even;
                odd=0;
            }else{
                ans+=max(odd-1, 0);
                odd=0;
                even=1;
            }
          }else{
             if(odd>0){
                ++odd;
                even=0;
             }else{
                  ans+=max(even-1, 0);
                  even=0;
                  odd=1;
             }
          }
       }
       if(even>0){
        ans+=max(even-1, 0);
       }
       if(odd>0){
        ans+=max(odd-1, 0);
       }
       cout<<ans<<'\n';
    }

	return 0;
        
}
