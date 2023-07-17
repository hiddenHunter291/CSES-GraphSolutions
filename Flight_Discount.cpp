// modified Dijkstra's algorithm
#include<iostream>
#include<queue>
#define ll long long
using namespace std;

struct Edge {
  int from, to, cost;
};

const ll INF = 1e18;

void Dijkstra(vector<vector<pair<int,int>>>& graph, vector<ll>& distance, int start) {
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  distance[start] = 0;
  pq.push({0, start});
  while(!pq.empty()) {
    auto curr = pq.top();
    pq.pop();
    ll currNode = curr.second;
    ll currCost = curr.first;
    if(currCost > distance[currNode]) {
      continue;
    }
    for(pair<int,int> node : graph[currNode]) {
      int adjNode = node.second;
      int adjNodeCost = node.first;
      if(distance[adjNode] > distance[currNode] + adjNodeCost) {
        distance[adjNode] = distance[currNode] + adjNodeCost;
        pq.push({distance[adjNode], adjNode});
      }
    }
  }
  return;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int,int>>> a(n), b(n);
  vector<Edge> edges;
  vector<ll> distanceA(n, INF);
  vector<ll> distanceN(n, INF);
  for(int i = 0; i < m; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    --from;
    --to;
    a[from].push_back({cost, to});
    b[to].push_back({cost, from});
    struct Edge e;
    e.from = from, e.to = to, e.cost = cost;
    edges.push_back(e);
  }
  Dijkstra(a, distanceA, 0);
  Dijkstra(b, distanceN, n-1);
  ll ans = INF;
  for(Edge e : edges) {
    int from = e.from;
    int to = e.to;
    int cost = e.cost;
    if(distanceA[from] == INF || distanceN[to] == INF) continue;
    ans = min(ans, distanceA[from] + (cost/2) + distanceN[to]);
  }
  cout << ans << endl;
  return 0;
}
