#include <bits/stdc++.h>
using namespace std;

struct Tree {

	struct Edge {
		int to, id;
	};

	int N;
	vector<bool> used;
	vector<vector<Edge>> adj;
	vector<int> deg;

	Tree(int V){
		N = V;
		adj.resize(N);
		deg = vector<int>(N, 0);
	}

	void addEdge(int a, int b){

		Edge E;
		E.id = used.size();
		used.push_back(0);

		E.to = b;
		adj[a].push_back(E);

		E.to = a;
		adj[b].push_back(E);

		deg[a]++;
		deg[b]++;
	}

	void print(){
		for(int i=0; i<N; i++){
			cout << i << ":";
			for(Edge e: adj[i]) cout << ' ' << e.to;
			cout << '\n';
		}
	}
};

vector<int> treeToPrufer(Tree T){

	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i=0; i<T.N; i++)
		if(T.deg[i] == 1) pq.push(i);

	vector<int> seq;

	for(int i=0, on, to; i<T.N-2; i++){

		on = pq.top();
		pq.pop();

		while(T.used[T.adj[on].back().id])
			T.adj[on].pop_back();

		T.used[T.adj[on].back().id] = 1;
		to = T.adj[on].back().to;
		T.adj[on].pop_back();

		seq.push_back(to);

		T.deg[on]--;
		if(--T.deg[to] == 1) pq.push(to);
	}

	return seq;
}

Tree pruferToTree(vector<int> seq){

	Tree T(seq.size()+2);

	vector<int> deg(seq.size()+2, 0);
	for(int u: seq) deg[u]++;

	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0; i<T.N; i++)
		if(deg[i] == 0) pq.push(i);

	for(int u: seq){
		T.addEdge(pq.top(), u);
		pq.pop();
		if(--deg[u] == 0) pq.push(u);
	}

	int a = pq.top();
	pq.pop();
	int b = pq.top();
	pq.pop();
	T.addEdge(a, b);

	return T;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	Tree T(N);
	for(int i=0, a, b; i<N-1; i++){
		cin >> a >> b;
		T.addEdge(a, b);
	}

	vector<int> v = treeToPrufer(T);
	for(int u: v) cout << u << ' ';
	cout << '\n';

	Tree U = pruferToTree(v);
	U.print();

	return 0;
}
