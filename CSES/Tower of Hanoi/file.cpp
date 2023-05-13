#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define vdl vector<double long>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define vpil vector<pair<int, long long>>
#define vpli vector<pair<long long, int>>
#define il int64_t
#define sort(A) sort(A.begin(), A.end())
#define input(A) for(auto &x : A)cin>>x
#define output(A) for(auto &x : A)cout<<x<<" "
#define dbg(v) cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << '\n';
#define bit(n, i) ((n>>i)&1)
vector<pair<il, il>> path; 
 
void thaphanoi(il from, il to, il middle, il n){
      if(n==1){
         path.push_back({from, to});
      }else{
      	thaphanoi(from, middle, to, n-1);
      	thaphanoi(from, to, middle, 1);
      	thaphanoi(middle, to, from, n-1);
      }
}
 
int main()
{ 
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    il n;
    cin>>n;
    thaphanoi(1, 3, 2, n);
    cout<<path.size()<<'\n';
    for(auto it : path){
    	cout<<it.first<<" "<<it.second<<'\n';
    }
	return 0;
}