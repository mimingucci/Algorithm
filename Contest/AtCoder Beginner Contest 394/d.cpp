/*
 * author:  mimingucci
 * created: [Sat] Feb 22, 2025 19:19:54
 */
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int INF = int(1) << 62;
const int MAXN = 1e6;
const int MOD = 998244353; // 1e9+7

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    stack<char> st;
    bool flag = true;
    for (char c : s) {
        if (st.empty()) {
            if (c == '>' || c == ']' || c == ')') {
                flag = false;
                break;
            }
            st.push(c);
        } else {
            if ((st.top() == '(' && c == ')') || (st.top() == '[' && c == ']') || (st.top() == '<' && c == '>')) {
                st.pop();
            } else {
                st.push(c);
            }
        }
    }
    if (flag && st.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
