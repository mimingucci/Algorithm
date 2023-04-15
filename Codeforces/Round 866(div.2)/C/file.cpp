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
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ii t;
    cin>>t;
    while(t--){
    	ii n;
    	int first=-1;
    	int last=-1;
    	cin>>n;
    	unordered_map<int, int> s;
    	int a[n];
    	for(int i=0; i<n; i++){
    		cin>>a[i];    		
    		if(s.count(a[i])){
               s[a[i]]++;
    		}else{
    			s[a[i]]=1;
    		}
    	}
    	if(n==1){
    		if(a[0]>0){
    			cout<<"Yes"<<'\n';
    		}else{
    			cout<<"No"<<'\n';
    		}
    		continue;
    	}
    	int k=0;
    	while(true){
    		if(s.count(k)){
    			++k;
    		}else{
    			break;
    		}
    	}
    	
    	if(!s.count(k+1)){
           bool isOk=false;
           for(auto it : s){
           	if(it.first<k && it.second>1){
           		isOk=true;
           		break;
           	}
           	if(it.first>k+1){
           		isOk=true;
           		break;
           	}
           }
           if(isOk){
           	cout<<"Yes"<<'\n';
           }else{
           	cout<<"No"<<'\n';
           }
           continue;
    	}
    	if(s[k+1]==1){
    		cout<<"Yes"<<'\n';
    		continue;
    	}
    	int l=0;
    	int r=n-1;
    	bool used[k+1];
    	fill(used, used+(k+1), false);
    	int cnt=0;
    	while((a[l]!=k+1 || a[r]!=k+1) && (l<=r) && l<n && r>=0){
    		if(a[l]!=k+1 && a[r]!=k+1){
               if(a[l]<=k && used[a[l]]==false){
                  ++cnt;
                  used[a[l]]=true;
               }
               if(a[r]<=k && used[a[r]]==false){
                  ++cnt;
                  used[a[r]]=true;
               }
               l=l+1;
               r=r-1;
    		}else{
               if(a[l]!=k+1){
                  if(a[l]<=k && used[a[l]]==false){
                  	++cnt;
                  	used[a[l]]=true;
                  }
                  l=l+1;
               }
               if(a[r]!=k+1){
                  if(a[r]<=k && used[a[r]]==false){
                  	++cnt;
                  	used[a[r]]=true;
                  }
                  r=r-1;
               }
    		}
    	}
    	if(cnt==k+1 || cnt==k){
    		cout<<"Yes"<<'\n';
    	}else{
    		cout<<"No"<<'\n';
    	}
    }
	return 0;
}