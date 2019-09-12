
const int LIM = 1e5;
const int LIMLG = 30;

int par[LIM][LIMLG], dpt[LIM];
vector<int> adj[LIM];

void dfs(int v, int p, int l=0){ // chamar como dfs(root, root)

	dpt[v] = l;
	par[v][0] = p;
	for(int k=1; k<LIMLG; k++) par[v][k] = par[par[v][k-1]][k-1];

	for(int u: adj[v]){
		if(u!=p) dfs(u, v, l+1);
	}
}

int lca(int a, int b) {
  
	if(dpt[b]>dpt[a]) swap(a, b);

	for(int i=LIMLG-1; i>=0; i--) {
		if(dpt[a]-(1<<i) >= dpt[b]) a = par[a][i];
	}

	if(a == b) return a;
	for(int i=LIMLG-1; i>=0; i--){
		if(par[a][i] != par[b][i]){
			a = par[a][i];
			b = par[b][i];
		}
	}

	return par[a][0];
}
