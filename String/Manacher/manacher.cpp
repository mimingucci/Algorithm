/*
author: mimingucci
created on: 3/19/2024 12:53:51 PM
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

int D_odd[MAXN];
int D_even[MAXN];
string S;
int N;

void Calc_D_odd() {
    int L = 1;
    int R = 0;
    for(int i = 1 ; i <= N ; i++) {
        if(i > R) D_odd[i] = 0;
        else D_odd[i] = min(R - i, D_odd[L + (R - i)]);
        while(i - D_odd[i] - 1 > 0 && i + D_odd[i] + 1 <= N && S[i - D_odd[i] - 1] == S[i + D_odd[i] + 1]) {
            D_odd[i]++;
        }
        
        if(i + D_odd[i] > R) {
            R = i + D_odd[i];
            L = i - D_odd[i];
        }
    }
}

void Calc_D_even() {
    int L = 1;
    int R = 0;
    for(int i = 1 ; i < N ; i++) {
        int j = i + 1;
        if(j > R) D_even[i] = 0;
        else D_even[i] = min(R - j + 1, D_even[L + (R - j)]);
        while(i - D_even[i] > 0 && j + D_even[i] <= N && S[i - D_even[i]] == S[j + D_even[i]]) {
            D_even[i]++;
        }
        if(i + D_even[i] > R) {
            R = i + D_even[i];
            L = j - D_even[i];
        }
    }
}

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    cin >> S;
    N = S.length();
    S = ' ' + S; // for 1-base
    Calc_D_odd();
    Calc_D_even();
    for(int i = 1 ; i < N ; i++) {
        cout << D_odd[i] * 2 + 1 << ' ' << D_even[i] * 2 << ' ';
    }
    cout << D_odd[N] * 2 + 1;
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */