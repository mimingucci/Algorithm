#define pi pair<int, int>
#define s second
#define f first
#define trav(a, b) for(auto &a : b)
struct DSU{
	vector<int> e;
	DSU(int n){
		e=vector<int> (n, -1);
	}
	int get(int x){
		return e[x]<0? x : e[x]=get(e[x]);
	}
	bool same_set(int a, int b){
		return get(a)==get(b);
	}
	int size(int x){
		return -e[get(x)];
	}

	bool unite(int a, int b){
		a=get(a);
		b=get(b);
		if(a==b){
			return false;
		}
		if(size(a)>size(b)){
			swap(a, b);
		}
		e[a]+=e[b];
		e[b]=a;
		return true;
	}
};

template <class T> T kruskal(int N, vector<pair<T, pi>> ed) {
	sort(all(ed));// sort all edges in acending of weight
	T ans = 0;
	DSU D;
	D.init(N);  // edges that unite are in MST
	trav(a, ed) if (D.unite(a.s.f, a.s.s)) ans += a.f;
	return ans;
}