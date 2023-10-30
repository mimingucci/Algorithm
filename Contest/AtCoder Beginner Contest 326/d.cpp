
/*
author: mimingucci
created on: 10/28/2023 7:41:20 PM
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int int64_t
const int INF=(int)1<<62;
const int MAXN= 1e6;
set<std::vector<int>> cauhinh;
std::vector<int> a{1, 2, 3};
int n;
string r, c;
void sinhhoanvi(std::vector<int> now, std::vector<bool> used){
    if(now.size()==n){
        cauhinh.insert(now);
        return;
    }
    for(int i=0; i<n; i++){
        if(!used[i]){
            now.push_back(a[i]);
            used[i]=true;
            sinhhoanvi(now, used);
            used[i]=false;
            now.pop_back();
        }
    }
}
main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>r>>c;
    std::vector<int> row(n);
    std::vector<int> col(n);
    for(int i=0; i<n; i++){
        row[i]=r[i]-'A'+1;
    }
    for(int i=0; i<n; i++){
        col[i]=c[i]-'A'+1;
    }
    while(a.size()<n)a.push_back(0);
    sinhhoanvi(std::vector<int> (0), std::vector<bool> (n, false));
    std::vector<std::vector<int>> firstX[4];
    for(auto i : cauhinh){
        auto now=i;
        int f=-1;
        for(int j=0; j<n; j++){
            if(f==-1 && i[j]>0){
                f=i[j];
            }
        }
        firstX[f].push_back(i);
    }
    std::vector<int> pos_now(n, 0);
    bool isOk=false;
    int sz=firstX[0].size();
    std::vector<std::vector<int>> grid(n, std::vector<int> (n));
    for(int i=0; i<sz; i++){
        for(int j=0; j<n; j++){
            grid[0][j]=firstX[row[0]][j];
        }
        for(int j=0; j<sz; j++){
            for(int k=0; k<n; k++){
                grid[1][k]=firstX[row[1]][k];
            }
            for(int k=0; k<sz; k++){
                for(int h=0; h<n; h++){
                    grid[2][h]=firstX[row[2]][h];
                }
                
            }
        }
    }
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */