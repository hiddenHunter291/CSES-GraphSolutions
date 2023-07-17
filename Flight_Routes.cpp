#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<long long,int>>> graph(n);
  vector<int> costs;
  for(int i = 0; i < m; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    from -= 1, to -= 1;
    graph[from].push_back({cost, to});
  }
  priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
  pq.push({0, 0});
  while(!pq.empty()) {
    auto x = pq.top();
    pq.pop();
    int currNode = x.second;
    int currCost = x.first;
    if(currNode == n-1) {
      costs.push_back(currCost);
      if(costs.size() == k) break;
    }
    for(pair<long long,int> adj : graph[currNode]) {
      int adjNode = adj.second;
      int adjCost = adj.first;
      pq.push({adjCost+currCost, adjNode});
    }
  }
  for(int cost : costs) {
    cout << cost << " ";
  }
  cout << endl;
  return 0;
}
