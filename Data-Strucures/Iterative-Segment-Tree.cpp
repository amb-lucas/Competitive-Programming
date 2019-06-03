#include <bits/stdc++.h>
using namespace std;

const int LIM = 2e5;
int N, t[LIM<<1];

// QUERIES WITH [l, r)
// to use [l, r] -> r+=N+1

// SINGLE-ELEMENT MODIFY, RANGE QUERY

void build(){
	for(int i=N-1; i; i--)
		t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int val){
	p += N;
	for(t[p]=val; p>1; p>>= 1)
		t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r){
	int res = 0;
	for (l+=N, r+=N; l<r; l>>=1, r>>=1){
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
	}
	return res;
}


// RANGE MODIFY, SINGLE-ELEMENT ACCESS

void build(){
	for(int i=N-1; i; i--)
		t[i] = 0;
}

int query(int p){
	int ans = 0;
	for(p += N; p; p >>=1)
		ans += t[p];
	return ans;
}

void modify(int l, int r, int val){
	for (l += n, r += n; l < r; l >>= 1, r >>= 1){
  		if(l&1) t[l++] += val;
    	if(r&1) t[--r] += val;
	}
}
