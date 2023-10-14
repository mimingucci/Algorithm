#include <bits/stdc++.h>
using namespace std;
int generator()
{
    static int val = 0;
    return ++val;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
    int64_t n, q;
    cin>>n>>q;
    vector<int64_t> rows(n+1, 0);
    vector<int64_t> cols(n+1, 0);
    int64_t a[n];
    generate_n(a, n, generator);
    set<int64_t> freeRows(a, a+n);
    set<int64_t> freeCols(a, a+n);

    while(q--){
    	int64_t t;
    	cin>>t;
        if(t==1){
        	int64_t x, y;
        	cin>>x>>y;
        	rows[x]++;
        	cols[y]++;
            freeRows.erase(x);
            freeCols.erase(y);
        }
        if(t==2){
        	int64_t x, y;
        	cin>>x>>y;
        	rows[x]--;
        	cols[y]--;
            if(rows[x]==0){
                freeRows.insert(x);
            }
            if(cols[y]==0){
                freeCols.insert(y);
            }
        }
        if(t==3){
        	int64_t x1, y1, x2, y2;
        	cin>>x1>>y1>>x2>>y2;
        	bool isOk=true;
        	auto it=freeRows.lower_bound(x1);
        	if(it!=freeRows.end() && *it<=x2){
                it=freeCols.lower_bound(y1);
                if(it!=freeCols.end() && *it<=y2){
                    cout<<"No"<<'\n';
                }else{
                    cout<<"Yes"<<'\n';
                }
            }else{
                cout<<"Yes"<<'\n';
            }
        }
    }
	return 0;
}