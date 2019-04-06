const int MAXN = 1e5 + 5;
const int MLOG = log2(MAXN) + 10;

// <3 Mendes

int par[MLOG][MAXN];
int h[MAXN];

void dfs(int v, int p = -1, int dep = 0) {
  h[v] = dep;
  par[0][v] = p;
  for (int u : adj[v]) {
    if (u == p) continue;
    dfs(u, v, dep + 1);
  }
}

void preLCA() {
  for (int i = 1; i < MLOG; ++i) {
    for (int j = 0; j < n; ++j) {
      if (par[i - 1][j] != -1) {
        par[i][j] = par[i - 1][par[i - 1][j]];
      }
    }
  }
}

int LCA(int u, int v) {
  if (h[u] > h[v]) swap(u, v);
  int dist = h[v] - h[u];
  for (int i = 0; i < MLOG; ++i) {
    if (dist & (1 << i)) {
      v = par[i][v];
    }
  }
  if (u == v) return u;
  for (int i = MLOG - 1; i >= 0; --i) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][u];
}
