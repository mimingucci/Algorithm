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

int solution(vector<int> &A) {
    map<int, int> cnt;
    for(int i : A){
        cnt[i]++;
    }   
    vector<int> a;
    map<int, int> s;
    for(auto it : cnt){
        a.push_back(it.second);
        s[it.second]=1;
    }
    int ans=0;
    sort(a);
    int n=a.size();
    int now=a.back();
    for(int i=n-1; i>0; i--){
        if(i>0){
            if(a[i]==a[i-1]){
                if(now==0){
                    ans+=a[i];
                    s[0]=1;
                    continue;
                }
                while(s.find(now)!=s.end()){
                    --now;
                    if(now<0){
                        now=0;
                        s[now]=1;
                        break;
                    }
                }
                ans+=a[i]-now;
                s[now]=1;
            }
        }
    }
    return ans;
}

int main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int a[]{1000, 1000, 2, 2, 2, 5, 5, 5, 0, 0};
    vector<int> A;
    for(int i=0; i<10; i++)A.push_back(a[i]);
    cout<<solution(A);
    return 0;    
}

