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


int main()
{ 
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    ii t;
    cin>>t;
    while(t--){
       ii n;
       cin>>n;
       vector<ii> a(n+1);
       vector<ii> b(n+1);
       for(ii i=1; i<=n; i++)cin>>a[i];
       for(ii i=1; i<=n; i++)cin>>b[i];
       ii ans=0;
       ii l=-1, r=-1;
       bool isOk=false;
       for(ii i=1; i<=n; i++){
        if(a[i]!=b[i]){
            // isOk=true;
            if(isOk){
                ++r;
            }else{
                if(i-1>=1 && b[i]>=b[i-1]){
                    if(l==-1){
                        l=i-1;
                        r=i;
                    }else{
                        r=i;
                    }
                }else{
                    l=i;
                    r=i;
                }
            }
            isOk=true;
        }else{
           if(l==-1){
             l=i;
             r=i;
           }else{
             if(a[i-1]==b[i-1]){
                if(b[i]>=b[i-1]){
                    ++r;
                }else{
                    if(isOk){
                        break;
                    }else{
                        l=i;
                        r=i;
                    }
                }
             }else{
                if(isOk){
                    if(b[i]>=b[i-1]){
                        ++r;
                    }else{
                        break;
                    }
                }
             }
           }
        }
       }
       cout<<l<<" "<<r<<'\n';
    }

	return 0;
        
}

