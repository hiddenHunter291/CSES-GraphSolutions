// Dijkstra's algorithm (Greedy approach)
// uses priority_queue, used when all edge weights are positive
#include<vector>
#include<iostream>
#include<queue>
#include<climits>
#define ll long long

using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<ll,ll>>> graph(n);
  vector<ll> distance(n, LLONG_MAX);
  for(int i = 0; i < m; ++i) {
    ll from, to, cost;
    cin >> from >> to >> cost;
    graph[--from].push_back({cost, --to});
  }
  distance[0] = 0;
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> nodeHolder;
  nodeHolder.push({0, 0});
  while(!nodeHolder.empty()) {
    pair<ll,ll> curr = nodeHolder.top();
    nodeHolder.pop();
    ll currNode = curr.second;
    for(pair<ll,ll> pr : graph[currNode]) {
      ll costToAdjNode = pr.first;
      ll adjNode = pr.second;
      if(distance[currNode] + costToAdjNode < distance[adjNode]) {
        distance[adjNode] = distance[currNode] + costToAdjNode;
        nodeHolder.push({distance[adjNode], adjNode});
      }
    }
  }
  for(ll dist : distance) {
    cout << dist << " ";
  }
  return 0;
}