#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int mod = 1000000007;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<int> indegree(n, 0);
	vector<long long> ways(n, 0);

	for(int i = 0; i < m; ++i) {
		int from, to;
		cin >> from >> to;
		graph[--from].push_back(--to);
		indegree[to]++;
	}

	queue<int> q;
	for(int i = 1; i < n; ++i) {
		if(indegree[i] == 0) {
			q.push(i);
		}
	}

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int v : graph[u]) {
			indegree[v]--;
			if(indegree[v] == 0 && v != 0) {
				q.push(v);
			}
		}
	}

	queue<int> q1;
	q1.push(0);
	ways[0] = 1;
	while(!q1.empty()) {
		int curr = q1.front();
		q1.pop();
		for(int to : graph[curr]) {
			ways[to] += ways[curr];
			ways[to] %= mod;
			indegree[to]--;
			if(indegree[to] == 0) {
				q1.push(to);
			}
		}
	}

	cout << ways[n-1] << endl;
	return 0;
}