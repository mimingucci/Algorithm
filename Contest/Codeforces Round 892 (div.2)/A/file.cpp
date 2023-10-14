#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define sort(A) sort(A.begin(), A.end())
#define input(A) for(auto &x : A)cin>>x
#define output(A) for(auto &x : A)cout<<x<<" "
#define dbg(v) cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';
#define bit(n, i) ((n>>i)&1)

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        std::vector<int> a(n);
        input(a);
        sort(a);
        if(a.back()==a[0]){
            cout<<-1<<'\n';
        }else{
            std::vector<int> b;
            std::vector<int> c;
            for(int i=0; i<n; i++){
                if(a[i]==a.back()){
                    c.push_back(a[i]);
                }else{
                    b.push_back(a[i]);
                }
            }
            cout<<b.size()<<" "<<c.size()<<'\n';
            output(b);
            cout<<'\n';
            output(c);
            cout<<'\n';
        }
    }
}


