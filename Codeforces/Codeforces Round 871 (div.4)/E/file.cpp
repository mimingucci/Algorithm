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
int64_t grid[1007][1007];
int64_t row_num;
int64_t col_num;
int64_t res;
int64_t curr_size;
bool visited[1007][1007];
void floodfill(int64_t r, int64_t c, int color) {
    if ((r < 0 || r >= row_num || c < 0 || c >= col_num)  // if out of bounds
        || grid[r][c] ==0                            // wrong color
        || visited[r][c]  // already visited this square
    )
        return;
 
    visited[r][c] = true;  // mark current square as visited
    curr_size+=grid[r][c];           // increment the size for each square we visit
 
    floodfill(r, c + 1, color);
    floodfill(r, c - 1, color);
    floodfill(r - 1, c, color);
    floodfill(r + 1, c, color);
}
 
int main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
       cin>>row_num>>col_num;
       for(int64_t i=0; i<row_num; i++)
        for(int64_t j=0; j<col_num; j++)
            cin>>grid[i][j];
 
        res=0;
        curr_size=0;
        fill(*visited, *visited+1007*1007, false);
        for (int64_t i = 0; i < row_num; i++) {
        for (int64_t j = 0; j < col_num; j++) {
            if (!visited[i][j] && grid[i][j]!=0) {
                curr_size = 0;
                /*
                 * start a flood fill if the square hasn't already been visited,
                 * and then store or otherwise use the component size
                 * for whatever it's needed for
                 */
                floodfill(i, j, grid[i][j]);
                res=max(res, curr_size);
            }
        }
    }
        cout<<res<<'\n';
    }
    return 0;    
}