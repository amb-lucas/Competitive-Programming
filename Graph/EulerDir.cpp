struct Euler {

	int N;
	vector<vector<int>> adj;
	vector<int> in;

	Euler(int V = 0){
		N = V;
		in = vector<int>(N, 0);
		adj = vector<vector<int>>(N);
	}

	void addEdge(int a, int b){
        in[b]++;
		adj[a].push_back(b);
	}

	pair<int, int> startingPoint(){
		int cnt = 0, st, end;
		for(int i=0; i<N; i++){
		    if(in[i]+1 == adj[i].size()){
		        st = i;
		        if(cnt++) return {-1, -1};
		    }
		    else if(in[i]-1 == adj[i].size()){
		        end = i;
		    }
		    else if(in[i] != adj[i].size()) return {-1, -1};
		}
		
		if(cnt) return {st, end};
		for(int i=0; i<N; i++) if(adj[i].size()) return {i, i};
	}

	vector<int> cycle;

	bool dfs(int on, int rt = -1){
		
		if(rt == -1){
		    rt = on;
		    cycle.clear();
		}
		else if(on == rt) return 1;
		
		if(adj[on].size()){
		    cycle.push_back(adj[on].back());
		    adj[on].pop_back();
		    return dfs(cycle.back(), rt);
		}
		
		return 0;
	}

	vector<int> findPath(){
	    
        pair<int, int> pii = startingPoint();
        int end = pii.second;
        int on = pii.first;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<adj[i].size(); j++){
                if(adj[i][j] == end) {
                    swap(adj[i][j], adj[i][0]);
                    break;
                }
            }
        }
		
		vector<int> path;
		deque<int> dq;
		
		path.push_back(on);
		
		while(on != -1){
		    
			while(dfs(on)){
				for(int i=cycle.size()-1; i>=0; i--)
					dq.push_front(cycle[i]);
			}
			for(int a: cycle) dq.push_back(a);
			
			if(dq.empty()) on = -1;
			else{
				path.push_back(dq.front());
				on = dq.front();
				dq.pop_front();
			}
		}
		
		return path;
	}
};
