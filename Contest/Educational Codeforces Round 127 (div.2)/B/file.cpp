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
int main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        std::vector<int> v(n+1);
        int cntThree=0;
        int cntTwo=0;
        bool isOk=true;
        for(int i=1; i<=n; i++)cin>>v[i];
        for(int i=2; i<=n; i++){
            if(v[i]-v[i-1]>=4){
                isOk=false;
                break;
            }else{
                if(v[i]-v[i-1]==3){
                    ++cntThree;
                }else{
                    if(v[i]-v[i-1]==2){
                        ++cntTwo;
                    }
                }
            }
        }
        if(!isOk){
            cout<<"NO"<<'\n';
        }else{
            if(cntThree>=2){
                cout<<"NO"<<'\n';
            }else{
                if(cntThree==1){
                    if(cntTwo>0){
                        cout<<"NO"<<'\n';
                    }else{
                        cout<<"YES"<<'\n';
                    }
                }else{
                    if(cntTwo<=2){
                        cout<<"YES"<<'\n';
                    }else{
                        cout<<"NO"<<'\n';
                    }
                }
            }
        }
    }
    return 0;
}