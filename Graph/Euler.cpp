
struct Euler {

	struct aresta{
		int to, id;
		bool turn;
	};

	int N;
	vector<vector<aresta>> adj;
	vector<bool> used;

	Euler(int V = 0){
		N = V;
		adj.resize(N);
	}

	void addEdge(int a, int b){

		aresta A;
		A.id = used.size();
		used.push_back(0);

		A.to = b;
		A.turn = 0;
		adj[a].push_back(A);

		A.to = a;
		A.turn = 1;
		adj[b].push_back(A);
	}

	int startingPoint(){
		int cnt = 0, st;
		for(int i=0; i<N; i++)
			if(adj[i].size()&1) cnt++, st = i;
		if(cnt>2) return -1;
		if(cnt == 2) return st;
		for(int i=0; i<N; i++) if(adj[i].size()) return i;
	}

	vector<aresta> cycle;

	bool dfs(int on, int rt = -1){
		
		if(rt == -1) rt = on, cycle.clear();
		else if(on == rt) return 1;

		while(adj[on].size()){
			if(used[adj[on].back().id]) adj[on].pop_back();
			else{
				cycle.push_back(adj[on].back());
				used[adj[on].back().id] = 1;
				adj[on].pop_back();
				return dfs(cycle.back().to, rt);
			}
		}
		return 0;
	}

	vector<int> findPath(){

		int on = startingPoint();
		vector<int> path;
		deque<aresta> dq;

		path.push_back(on);

		while(on != -1){

			while(dfs(on)){
				for(int i=cycle.size()-1; i>=0; i--)
					dq.push_front(cycle[i]);
			}
			for(aresta a: cycle) dq.push_back(a);

			if(dq.empty()) on = -1;
			else{
				path.push_back(dq.front().to);
				on = dq.front().to;
				dq.pop_front();
			}
		}

		return path;
	}
};
