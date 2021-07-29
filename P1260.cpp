#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

vector<int> a1260[1001];
bool visited[1001];

void dfs1260(int start) {
	visited[start] = true;
	cout << start << " ";
	for (int i = 0; i < a1260[start].size(); i++) {
		int next = a1260[start][i];
		if (visited[next] == false) {
			dfs1260(next);
		}
	}
};

void bfs1260(int start) {
	queue<int> q;
	memset(visited, false, sizeof(visited));
	visited[start] = true;
	q.push(start);
	cout << start << " ";
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < a1260[node].size(); i++) {
			int next = a1260[node][i];
			if (visited[next] == false) {
				visited[next] = true;
				q.push(next);
				cout << next << " ";
			}
		}
	}
};

int P1260() {
	int N, M, start;
	cin >> N >> M >> start;
	//data 입력
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		a1260[u].push_back(v);
		a1260[v].push_back(u);
	}
	//data 정렬
	for (int i = 1; i <= N; i++) {
		sort(a1260[i].begin(), a1260[i].end());
	}
	dfs1260(start);
	cout << endl;
	bfs1260(start);
	cout << endl;

	return 0;
}