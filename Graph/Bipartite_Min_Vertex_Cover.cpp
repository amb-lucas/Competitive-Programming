struct bMinVC{

	typedef vector<int> vi;
	typedef vector<vector<int>> vvi;

	vi A, B;
	vi match, matched;
	vvi adj;

	bMinVC(vi a, vi b, vi m, vvi ad): A(a), B(b), match(m), adj(ad) {}

	void GetMatched(){
		matched.resize(B.size());
		for(int i=0; i<A.size(); i++){
			if(match[i]!=-1) matched[match[i]] = i;
		}
	}

	vector<bool> mark, marked;

	void dfs(int on){
		if(mark[on]) return;
		mark[on] = 1;
		for(int u: adj[on]){
			marked[u] = 1;
			dfs(matched[u]);
		}
	}

	vi solve(){
		GetMatched();
		mark = vector<bool>(A.size(), 0);
		marked = vector<bool>(B.size(), 0);

		for(int i=0; i<A.size(); i++)
			if(match[i] == -1) dfs(i);

		vi ans;
		for(int i=0; i<A.size(); i++)
			if(mark[i] == 0) ans.push_back(A[i]);
		for(int j=0; j<B.size(); j++)
			if(marked[j]) ans.push_back(B[j]);

		return ans;
	}
};
