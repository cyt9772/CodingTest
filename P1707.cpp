#include<iostream>
#include<vector>

using namespace std;

vector<int> a1707[20001];//������ ����
int color1707[20001]; //�湮 �� color ����

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
	int T, N, M; //T: test case, N: node, M: ����

//	cin >> T;
	scanf("%d\n", &T);

	while(T--)  //test case
	{
//		cin >> N >> M;
		scanf("%d %d", &N, &M);
		//�ʱ�ȭ
		for (int i = 1; i <= N; i++) {
			a1707[i].clear();
			color1707[i] = 0;
		}

		for (int i = 0; i < M; i++) { //�������� �Է�
			int u, v;
//			cin >> u >> v;
			scanf("%d %d", &u, &v);
			a1707[u].push_back(v);
			a1707[v].push_back(u);
		}

		//��� ��忡 ���� �˻縦 �ؾ� ������ loop  �ʿ�
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