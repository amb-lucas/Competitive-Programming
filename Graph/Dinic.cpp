typedef long long ll;

const ll INF = 1e9+7;
const int LIMV = 50;

struct Dinic {

	struct Edge {
		int to;
		ll cap;
		Edge(int a, ll c): to(a), cap(c) {}
	};

	int nv;
	vector<vector<int>> edges;
	vector<Edge> E;
	vector<int> d, pt;

	Dinic(int n = LIMV){
		edges.resize(n);
		this->nv = n;
	}

	void addEdge(int from, int to, ll cap = 1){
		edges[from].push_back(E.size());
		E.push_back(Edge(to, cap));
		edges[to].push_back(E.size());
		E.push_back(Edge(from, 0));
	}

	bool bfs(int src, int sink){
		
		d = vector<int>(nv, nv);
		d[src] = 0;

		queue<int> q;
		q.push(src);

		while(!q.empty()){
			
			int on = q.front();
			q.pop();

			for(int e: edges[on]){
				if(E[e].cap == 0) continue;

				int to = E[e].to;
				if(d[to] > d[on]+1){
					d[to] = d[on]+1;
					q.push(to);
				}
			}
		}

		return d[sink] < nv;
	}

	ll dfs(int on, int sink, ll flow = INF){

		if(flow == 0) return 0;
		if(on == sink) return flow;

		for(;pt[on] < edges[on].size(); pt[on]++){
			
			int cur = edges[on][pt[on]];
			if(d[on]+1 != d[E[cur].to]) continue;

			ll got = dfs(E[cur].to, sink, min(flow, E[cur].cap));
			if(got){
				E[cur].cap -= got;
				E[cur^1].cap += got;
				return got;
			}
		}

		return 0;
	}

	ll maxFlow(int src, int sink){
		ll ans = 0, flow;
		while(bfs(src, sink)){
			pt = vector<int>(nv,0);
			while(flow = dfs(src, sink)) ans += flow;
		}
		return ans;
	}
};
