#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <class T> class MinSegmentTree{
	private:
		const T DEFAULT=0;
		std::vector<T> segment;
		int len;
	public:
       MinSegmentTree(int length){
        	len=length;
        	segment.resize(2*len, DEFAULT);
       }

	void set(int index, int value){
            index+=len;
            segment[index]=value;
            for(index/=2; index>=1; index/=2){
            	segment[index]=segment[2*index] + segment[2*index+1];
            }
	}

	T range_sum(int start, int end){
		T ans=DEFAULT;
		for(start+=len, end+=len; start<=end; start/=2, end/=2){
			if(start%2==1){
                       ans+=segment[start++];
			}
			if(end%2==0){
			  ans+=segment[end--];
			}
		}
		return ans;
	}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int len, q;
    cin>>len>>q;
    MinSegmentTree<ll> segment(len);
    for(int i=1; i<=len; i++){
    	int  v;
    	cin>>v;
    	segment.set(i, v);
    }
    for(int i=0; i<q; i++){
    	int type, arg1, arg2;
    	cin>>type>>arg1>>arg2;
    	if(type==1){
           segment.set(arg1, arg2);
    	}else{
           cout<<segment.range_sum(arg1, arg2)<<'\n';
    	}
    }
	return 0;
} 