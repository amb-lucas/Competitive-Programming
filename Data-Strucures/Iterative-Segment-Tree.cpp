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


// RANGE MODIFY, RANGE QUERY

int h = sizeof(int)*8 - __builtin_clz(N);
int d[LIM]; 

void apply(int p, int value){
	t[p] += value;
	if(p<N) d[p] += value;
}

void build(int p){
	while(p > 1){
		p >>= 1;
		t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
	}
}

void push(int p){
	for(int s=h; s>0; s--){
		int i = p>>s;
		if(d[i]!=0){
			apply(i<<1, d[i]);
			apply(i<<1|1, d[i]);
			d[i] = 0;
		}
	}
}

void inc(int l, int r, int val){
	l += N, r += N;
	int ll = l, rr = r;
	for(; l<r; l>>=1, r>>=1){
		if(l&1) apply(l++, val);
		if(r&1) apply(--r, val);
	}
	build(ll);
	build(rr-1);
}

int query(int l, int r){
	l += N, r += N;
	push(l);
	push(r-1);
	int ans = -2e9;
	for(; l<r; l>>=1, r>>=1){
		if(l&1) ans = max(ans, t[l++]);
		if(r&1) ans = max(t[--r], ans);
	}
	return ans;
}
