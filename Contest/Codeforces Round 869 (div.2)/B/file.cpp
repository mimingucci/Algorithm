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


int sum(int begin, int to){
    if((to-begin+1)%2==0){
        return (to+begin)*((to-begin+1)/2);
    }else{
        return (to+begin)*((to-begin+1)/2)+(to+begin)/2;
    }
}


int main()
{ 
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(sum(1, n)%n==0 && n>1){
            cout<<-1<<'\n';
        }else{
            if(n%2!=0){
                for(int i=2; i<=n-1; i+=2){
                    cout<<i<<" "<<i-1<<" ";
                }
                cout<<n<<'\n';
            }else{
                for(int i=2; i<=n; i+=2){
                    cout<<i<<" "<<i-1<<" ";
                }
                cout<<'\n';
            }
        }
    }    
	return 0;
        
}

