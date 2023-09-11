/*
author: mimingucci
created on: 9/9/2023 12:38:28 PM
*/
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int MAXN= 1e6;
int lazy[4*MAXN];
int seg[4*MAXN];
int arr[MAXN];

void build(int index, int l, int r){
	if(l==r){
		seg[index]=arr[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*index, l, mid);
	build(2*index, mid+1, r);
	seg[index]=seg[2*index]+seg[2*index+1];
}

void update(int index, int l, int r, int lx, int rx, int val){
	if(lazy[index]!=0){
		seg[index]+=(r-l+1)*lazy[index];
		if(l!=r){
			lazy[2*id]+=lazy[index];
			lazy[2*id+1]+=lazy[index];
	    }
	    lazy[index]=0;
	}
	if(l>rx || r<lx){
		return;
	}
	if(l>=lx && r<=rx){
        seg[index]+=(r-l+1)*val;
        if(l!=r){
        	lazy[2*index]+=val;
        	lazy[2*index+1]+=val;
        }
        return;
	}
	int mid=(l+r)/2;
	update(2*index, l, mid, lx, rx, val);
	update(2*index+1, mid+1, r, lx, rx, val);
	seg[index]=seg[2*index]+seg[2*index+1];
}

int query(int index, int l, int r, int lx, int rx) {
  if (lazy[index] != 0) {
    seg[index] += (r - l + 1) * lazy[index];
    if (l != r) 
    {
      lazy[2 * index] += lazy[index];
      lazy[2 * index + 1] += lazy[index];
    }
    lazy[index] = 0;
  }
  if (r < lx || l > rx) {
    return 0;
  }

  if ((lx <= l) && (r <= rx)) {
    return seg[index];
  }
  int mid = (l + r) / 2;

  int q1 = query(2 * index, l, mid, lx, rx);

  int q2 = query(2 * index + 1, mid + 1, r, lx, rx);

  return (q1 + q2);
}

