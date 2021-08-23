#include<iostream>
#include<vector>

using namespace std;

vector<int> a1707[20001];//연결노드 정보
int color1707[20001]; //방문 및 color 정보

bool dfs1707(int node, int c) {
	color1707[node] = c;
	for (int i = 0; i < a1707[node].size(); i++) {
		int next = a1707[node][i];
		if (color1707[next] == 0) {
			if (dfs1707(next, 3 - c) == false) {
				return false;
			}
		}
		else if (color1707[next] == color1707[node]) {
			return false;
		}
	}
	return true;
};

int P1707() {
	int T, N, M; //T: test case, N: node, M: 간선

//	cin >> T;
	scanf("%d\n", &T);

	while(T--)  //test case
	{
//		cin >> N >> M;
		scanf("%d %d", &N, &M);
		//초기화
		for (int i = 1; i <= N; i++) {
			a1707[i].clear();
			color1707[i] = 0;
		}

		for (int i = 0; i < M; i++) { //연결정보 입력
			int u, v;
//			cin >> u >> v;
			scanf("%d %d", &u, &v);
			a1707[u].push_back(v);
			a1707[v].push_back(u);
		}

		//모든 노드에 대해 검사를 해야 함으로 loop  필요
		bool ok = true;
		for (int i = 1; i <= N; i++) {
			if (color1707[i] == 0) {// not visited
				if (dfs1707(i, 1)==false) {
					ok = false;
				}
			}
		}

		cout << (ok ? "YES" : "NO");
	}

	return 0;
}