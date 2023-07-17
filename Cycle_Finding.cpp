//Bellman Ford algorithm (dynamic programming approach)
//with conditions to handle -ve cycles, used for negative edge weight also
#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

struct Edge {
  int from, to, cost;
};

const long long INF = 1e18;

int main() {
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;
  vector<long long> distance(n+1, INF);
  vector<int> parent(n+1, -1);
  vector<int> cycle; 
  distance[0] = 0;
  for(int i = 0; i < m; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    struct Edge e;
    e.from = from;
    e.to = to;
    e.cost = cost;
    edges.push_back(e);
  }

  int x;
  for(int i = 1; i <= n; ++i) {
    x = -1;
    for(Edge e : edges) {
      int from = e.from;
      int to = e.to;
      int cost = e.cost;
      if(distance[to] > distance[from] + cost) {
        distance[to] = distance[from] + cost;
        parent[to] = from;
        x = to;
      }
    }
  }
  if(x == -1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for(int i = 0; i < n; ++i) {
      x = parent[x];
    }
    for(int v = x; ; v = parent[v]) {
      if(v == x && cycle.size() > 0) break;
      cycle.push_back(v);
    }
    reverse(cycle.begin(), cycle.end());
    cycle.push_back(cycle[0]);
    for(int y : cycle) {
      cout << y << " ";
    }
    cout << endl;
  }
  return 0;
}
