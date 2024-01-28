/*
author: mimingucci
created on: 1/26/2024 9:58:16 PM
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

//link: https://community.topcoder.com/stat?c=problem_statement&pm=18153

template <typename Iterator>
inline bool next_combination(const Iterator first, Iterator k, const Iterator last)
{
   /* Credits: Thomas Draper */
   if ((first == last) || (first == k) || (last == k))
      return false;
   Iterator itr1 = first;
   Iterator itr2 = last;
   ++itr1;
   if (last == itr1)
      return false;
   itr1 = last;
   --itr1;
   itr1 = k;
   --itr2;
   while (first != itr1)
   {
      if (*--itr1 < *itr2)
      {
         Iterator j = k;
         while (!(*itr1 < *j)) ++j;
         std::iter_swap(itr1,j);
         ++itr1;
         ++j;
         itr2 = k;
         std::rotate(itr1,j,last);
         while (last != j)
         {
            ++j;
            ++itr2;
         }
         std::rotate(k,itr2,last);
         return true;
      }
   }
   std::rotate(first,k,last);
   return false;
}

class RandomizedParking{
    public:
        double solve(string start, int K){
            cout<<fixed<<setprecision(16);
            int n=start.size();
            if(K==1){
                std::map<int, int> cnt;
                for(int i=0; i<n; i++){
                    int now=i;
                    int step=0;
                    while(start[now]=='X'){
                        ++now;
                        step++;
                        now%=n;
                    }
                    cnt[step]++;
                }
                double ans=0;
                for(int i=0; i<n; i++){
                    ans+=i*((double)cnt[i]/(double)n);
                }
                return ans;
            }
            double answer=0;
            std::vector<int> periods;
            for(int i=0; i<n; i++)if(start[i]=='.')periods.push_back(i);
            do
             {
                std::vector<bool> avaiable(n, true);
                double ans=0;
                for(int i=0; i<n; i++){
                    if(start[i]=='X')avaiable[i]=false;
                }
                std::vector<int> pos;
                for(int i=0; i<K-1; i++)pos.push_back(periods[i]);
                std::vector<std::vector<double>> dp(pos.size()+1, std::vector<double> (1<<pos.size(), 0));
                for(int i=0; i<pos.size(); i++){
                    avaiable[pos[i]]=false;
                    int now=pos[i]-1;
                    int cnt=1;
                    if(now<0)now+=n;
                    while(!avaiable[now]){
                        ++cnt;
                        --now;
                        if(now<0)now+=n;
                    }
                    dp[0][1<<i]=(double)cnt/(double)n;
                    avaiable[pos[i]]=true;
                }
                std::vector<std::vector<int>> v(pos.size()+1);
                for(int i=1; i<(1<<pos.size()); i++){
                    v[__builtin_popcount(i)].push_back(i);
                }
                for(int i=1; i<pos.size(); i++){
                    for(int k=0; k<pos.size(); k++)
                    for(int j : v[i]){
                        if((j>>k)&1)continue;
                        int now=pos[k]-1;
                        int cnt=1;
                        if(now<0)now+=n;
                        auto check=[&](int kk)->bool{
                            bool ok=false;
                            for(int ii=0; ii<pos.size(); ii++){
                                if(((j>>ii)&1) && (pos[ii]==kk))ok=true;
                            }
                            return ok;
                        };
                        while(start[now]=='X' || check(now)){
                            ++cnt;
                            --now;
                            if(now<0)now+=n;
                        }
                        dp[i][j+(1<<k)]+=((double)cnt/(double)n)*dp[i-1][j];
                    }
                }
                ans+=dp[pos.size()-1][(1<<pos.size())-1];
                for(int i=0; i<K-1; i++)avaiable[periods[i]]=false;     
                std::map<int, int> cnt;
                double x=0;
                for(int i=0; i<n; i++){
                    int now=i;
                    int step=0;
                    while(!avaiable[now]){
                        ++now;
                        ++step;
                        now%=n;
                    }
                    cnt[step]++;
                }    
                for(int i=0; i<n; i++){
                    x+=i*((double)cnt[i]/(double)n);
                }
                answer+=ans*x;
             } while (next_combination(periods.begin(), periods.begin()+K-1, periods.end()));
             return answer;
        }
};

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    RandomizedParking a;
    cout<<a.solve("..X..X..X....XX...", 9);
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */