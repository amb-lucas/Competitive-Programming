
const int BLOCKSZ = 300;
struct query {
	int l, r, id;
	bool operator < (query A){
		if(l/BLOCKSZ == A.l/BLOCKSZ) return r<A.r;
		return l/BLOCKSZ < A.l/BLOCKSZ;
	}
};

vector<query> q(Q);
vector<int> ans(Q);

for(int i=0; i<Q; i++){
    scanf("%d %d",&q[i].l, &q[i].r);
    q[i].id = i;
}
sort(q.begin(), q.end());

int j = q[0].l, k = q[0].r;
for(int i=j; i<=k; i++) add(i);

for(query qu: q){

    while(j>qu.l) add(--j);
    while(k<qu.r) add(++k);
    while(j<qu.l) remove(j++);
    while(k>qu.r) remove(k--);

    ans[qu.id] = solve();
}
