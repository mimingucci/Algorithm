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
const ii MAX_N=2e5 + 17;
ii n, m;
vector<ii> adj[MAX_N];
bool visited[100001];
namespace Solution1{
     void solve(){
     	cout<<1<<'\n';
     }
}
namespace Solution2{

     void solve(){
     	cout<<2<<'\n';
     }
}
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

 
ll countNumbersWith4(ll n)
{
   if (n < 4)
      return 0;
 
   ll d = log10(n);
 
   ll *a = new ll[d+1];
   a[0] = 0, a[1] = 1;
   for (ll i=2; i<=d; i++)
      a[i] = a[i-1]*9 + ceil(pow(10,i-1));
   ll p = ceil(pow(10, d));
 
   ll msd = n/p;
   if (msd == 4)
      return (msd)*a[d] + (n%p) + 1;
 
   if (msd > 4)
      return (msd-1)*a[d] + p + countNumbersWith4(n%p);
   return (msd)*a[d] + countNumbersWith4(n%p);
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

ld dfs(int v = 0, int p = -1){
	ld sum = 0;
	for(auto u : adj[v])
		if(u != p)
			sum += dfs(u, v) + 1;
	return sum ? sum / (adj[v].size() - (p != -1)) : 0;
}


int main()
{ 
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ii t;
    cin>>t;
    while(t--){
    	char a[110];
    	fill(a, a+110, 'x');
    	string b;
    	cin>>b;
    	for(ii i=1; i<=b.size(); i++){
    		a[i]=b[i-1];
    	}
    	if(b.size()==1){
    		if(a[1]=='_'){
    			cout<<2<<'\n';
    		}else{
    			cout<<1<<'\n';
    		}
    		continue;
    	}

    	ii cnt=0;
    	ii l=-1; ii r=-1;
    	for(ii i=1; i<=b.size(); i++){
           if(a[i]=='_'){
             if(l!=-1){
             	
             	r++;
             }else{
             	l=i;
             	r=i;
             }
           }else{
             if(l!=-1){
                if(a[l-1]=='^'){
                   cnt+=(r-l);
                   l=-1;
                   r=-1;
                }else{
                	cnt+=(r-l+1);
                	l=-1;
                	r=-1;
                }
             }else{
                continue;
             }
           }
    	}
    	if(b.back()=='_' && l!=-1 && a[l-1]=='^'){
    		cnt+=(r-l+1);
    	}
    	if(b.back()=='_' && l!=-1 && a[l-1]!='^'){
    		cnt+=(r-l+2);
    	}
    	cout<<cnt<<'\n';

    }
	return 0;
}