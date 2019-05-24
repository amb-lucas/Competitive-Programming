
const int LIM = 2e5;
int N, t[LIM<<1];

void build(){
	for(int i=N-1; i; i--) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int val){
	p += N;
	for(t[p]=val; p>1; p>>= 1){
		t[p>>1] = t[p] + t[p^1];
	}
}

int query(int l, int r){
	int ans = 0;
	for(l+=N, r+=N; l<=r; l>>=1, r>>=1){
		if(l&1) ans += t[l++];
		if(!(r&1)) ans += t[r--];
	}
	return ans;
}
