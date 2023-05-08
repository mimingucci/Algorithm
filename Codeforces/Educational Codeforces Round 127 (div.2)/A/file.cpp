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
    	string s;
    	cin>>s;
        bool isOk=true;
        int cntA=0;
        int cntB=0;
        for(int i=0; i<s.size(); i++){
        	if(s[i]=='a'){
        		if(cntB==0){
        			++cntA;
        		}else{
        			if(cntB==1){
        				isOk=false;
        				break;
        			}else{
        				cntB=0;
        				++cntA;
        			}
        		}
        	}
        	if(s[i]=='b'){
        		if(cntA==0){
        			++cntB;
        		}else{
        			if(cntA==1){
        				isOk=false;
        				break;
        			}else{
        				cntA=0;
        				++cntB;
        			}
        		}
        	}
        }
        if(cntA==0 && cntB==1){
        	isOk=false;
        }
        if(cntA==1 && cntB==0){
        	isOk=false;
        }
        if(isOk){
        	cout<<"YES"<<'\n';
        }else{
        	cout<<"NO"<<'\n';
        }
    }
    return 0;
}