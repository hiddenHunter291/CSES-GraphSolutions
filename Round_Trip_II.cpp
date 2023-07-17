#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int cycle_start = -1;
bool dfs(int u, vector<int>& vis, vector<vector<int>>& graph, vector<int>& parent) {
  vis[u] = 1;
  for(int v : graph[u]) {
    if(vis[v] == 0) {
      parent[v] = u;
      return dfs(v, vis, graph, parent);
    } else if(vis[v] == 1) {
      parent[v] = u;
      cycle_start = v;
      return true;
    }
  }
  vis[u] = 2;
  return false;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n);
  vector<int> vis(n, 0);
  vector<int> parent(n, -1);
  vector<int> cycle;
  for(int i = 0; i < m; ++i) {
    int from, to;
    cin >> from >> to;
    from -= 1, to -= 1;
    graph[from].push_back(to);
  }
  for(int i = 0; i < n; ++i) {
    if(vis[i] == 0 && dfs(i, vis, graph, parent))
      break;
  }
  if(cycle_start == -1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cycle.push_back(cycle_start);
  int v = parent[cycle_start];
  while(v ^ cycle_start) {
    cycle.push_back(v);
    v = parent[v];
  }
  cycle.push_back(cycle_start);
  reverse(cycle.begin(), cycle.end());
  cout << cycle.size() << endl;
  for(int node : cycle) {
    cout << node+1 << " ";
  }
  cout << endl;
  return 0;
}
