#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> a11724[1001];
bool visited11724[1001];


void dfs11724(int start) {
	visited11724[start] = true;
	for (int i = 0; i < a11724[start].size(); i++) {
		int next = a11724[start][i];
		if (visited11724[next] == false) {
			dfs11724(next);
		}
	}
};

int P11724() {
	int N, M;
	cin >> N >> M;

	//data �Է�
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		a11724[u].push_back(v);
		a11724[v].push_back(u);
	}

	//node�� ������ ����
	for (int i = 1; i <= N; i++) {
		sort(a11724[i].begin(), a11724[i].end());
	}

	//������ ����
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited11724[i]) continue;
		dfs11724(i);
		cnt++;
	}

	cout << cnt << endl;
	return 0;
}