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
ii cnt;
int cntnone;
int maxx;
unordered_map<int, int> ma;
vector<ii> graph[100005];
bool visited[100005];
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

bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
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


struct DSU{
    vector<int> e;
    DSU(int n){
        e=vector<int> (n, -1);
    }
    int get(int x){
        return e[x]<0 ? x : e[x]=get(e[x]);
    }
    bool isSame(int x, int y){
        return get(x)==get(y);
    }
    int size(int x){
        return -e[get(x)];
    }
    bool unite(int x, int y){
        x=get(x);
        y=get(y);
        if(x==y)return false;
        if(e[x]>e[y])swap(x, y);
        e[x]+=e[y];
        e[y]=x;
        --cnt;
        maxx=max(maxx, -e[x]);
        return true;
    }
};

bool isPowerOfTwo(unsigned int n) {
    return n && !(n & (n - 1));
}

void prime_divisor(int n){
    for(int i=2; i*i<=n; i++){
        while(n%i==0){
            ma[i]++;
            n/=i;
        }
    }
    if(n>1){
        ma[n]++;
    }
}


int main()
{ 
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        char a[n+1][k+1];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                cin>>a[i][j];
            }
        }
        bool isOk[n+1];
        fill_n(isOk, n+1, true);
        int res=0;
        for(int i=1; i<=k; i++){
            char x=a[1][i];
            int tmp=1;
            for(int j=2; j<=n; j++){
                if(a[j][i]==x && isOk[j]){
                   ++tmp;
                }else{
                isOk[j]=false;
            }
            }
            res=tmp;
        }
        cout<<res<<'\n';
    }    
	return 0;
        
}

