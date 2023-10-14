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
const ii mod=1000000007;
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
       ii n;
       cin>>n;
       ii ans=1;
       if(n==1){
        cout<<0<<'\n';
       }else{
        ans=(n)*(n-1);
        ans%=mod;
        for(ii i=n; i>=1; i--){
            ans=ans*i;
            ans%=mod;
        }
        
        cout<<ans%mod<<'\n';
       }

    }
	return 0;
        
}

