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
const int MAXN=5001;
std::vector<int> a(MAXN);
std::vector<std::vector<bool>> solved(MAXN, std::vector<bool> (MAXN));
std::vector<std::vector<int>> f(MAXN, std::vector<int> (MAXN));
std::vector<int> prefix(MAXN);

int sum(int l, int r){
    return prefix[r]-prefix[l-1];
}

int solve(int l, int r){
    if(solved[l][r])return f[l][r];
    if(l==r)return a[l];
    solved[l][r]=true;
    return f[l][r]=max(a[l]+sum(l+1, r)-solve(l+1, r), a[r]+sum(l, r-1)-solve(l, r-1));
}

main()
{ 
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        prefix[i]=prefix[i-1]+a[i];
    }
    cout<<solve(1, n);
}


