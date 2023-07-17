//Bellman Ford algorithm (dynamic programming approach)
//with conditions to handle -ve cycles, used for negative edge weight also
#include<vector>
#include<iostream>
using namespace std;

struct Edge {
  int from, to, cost;
};

const long long INF = 1e18;

void dfs(int u, vector<vector<int>>& a, vector<bool>& vis) {
  vis[u] = true;
  for(int v : a[u]) {
    if(!vis[v]) {
      dfs(v, a, vis);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  vector<vector<int>> a(n);
  vector<vector<int>> b(n);
  vector<bool> vis1(n), vis2(n);
  vector<long long> distance(n, INF);
  distance[0] = 0;
  for(int i = 0; i < m; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    from -= 1, to -= 1;
    a[from].push_back(to);
    b[to].push_back(from);
    struct Edge e;
    e.from = from;
    e.to = to;
    e.cost = (-1) * cost;
    edges.push_back(e);
  }
  dfs(0, a, vis1);
  dfs(n-1, b, vis2);
  int flag;
  for(int i = 1; i <= n; ++i) {
    flag = 1;
    for(Edge e : edges) {
      int from = e.from;
      int to = e.to;
      int cost = e.cost;
      if(vis1[from] && vis2[to] && distance[to] > distance[from] + cost) {
        distance[to] = distance[from] + cost;
        flag = 0;
      }
    }
  }
  if(!flag) {
    cout << -1 << endl;
  } else {
    cout << (-1) * distance[n-1] << endl;
  }
  return 0;
}
