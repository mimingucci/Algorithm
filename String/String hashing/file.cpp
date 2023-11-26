/*
author: mimingucci
created on: 11/26/2023 7:14:05 PM
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

class HashedString {
  private:
	// change M and B if you want
	static const long long M = 1e9 + 9;//(1LL << 61) - 1
	static const long long B;

	// pow[i] contains B^i % M
	static vector<long long> pow;

	// p_hash[i] is the hash of the first i characters of the given string
	vector<long long> p_hash;

  public:
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() < s.size()) { pow.push_back((pow.back() * B) % M); }

		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
		}
	}

	long long getHash(int start, int end) {
		long long raw_val =
		    (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
		return (raw_val % M + M) % M;
	}
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<long long> HashedString::pow = {1};
const long long HashedString::B = uniform_int_distribution<long long>(0, M - 1)(rng);

main()
{ 
    cin.tie(0)->sync_with_stdio(0);
    string n, h;
    cin>>n>>h;
    HashedString hs1(n);
    HashedString hs2(h);
    for(int i=n.size()-1; i<h.size(); i++){
    	if(hs1.getHash(0, n.size()-1)==hs2.getHash(i-n.size()+1, i)){
    		cout<<i-n.size()+1<<" ";
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