#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;

int a7576[1001][1001];
int dx7576[] = { 1,-1,0,0 };
int dy7576[] = { 0,0, 1,-1 };
bool visited7576[1001][1001];
int days7576[1001][1001];
int ans7576;

void bfs7576(int row, int col, queue<pair<int, int>> q) {

	while (!q.empty()) { //초기에 (1,1) push
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx7576[k];
			int ny = y + dy7576[k];
			if (nx >= 1 && nx <= row && ny >= 1 && ny <= col) {
				if (visited7576[nx][ny] == false && a7576[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					days7576[nx][ny] = days7576[x][y] + 1;
					ans7576 = max(ans7576, days7576[nx][ny]);
					visited7576[nx][ny] = true;
				}
			}
		}
	} //end while

};

int P7576() {
	int N, M; //가로, 세로
	cin >> M >> N;

	ans7576 = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &a7576[i][j]);
		}
	}

	queue<pair<int, int>> q;

	for (int i = 1; i <= N; i++) {
		for (int j=1; j <= M; j++) {
			if (a7576[i][j] == 1) {
				q.push(make_pair(i, j));
				visited7576[i][j] = true;
//				days7576[i][j] = 1;
			}
		}
	}
	bfs7576(N, M, q);

	bool ok=true;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (visited7576[i][j]==false && a7576[i][j]==0) {
				ok = false;
				break;
			}
		}
		if (!ok) break;
	}
	if (ok) {
		cout << ans7576 << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}