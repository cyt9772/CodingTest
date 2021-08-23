#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;

int a2187[101][101];
int dx2187[] = { 1,-1,0,0 };
int dy2187[] = { 0,0, 1,-1 };
bool visited2187[101][101];
int dist2187[101][101];


int P2187() {
	int N, M; //가로, 세로
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &a2187[i][j]);
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	visited2187[1][1] = true;
	dist2187[1][1] = 1;

	while (!q.empty()) { //초기에 (1,1) push
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx2187[k];
			int ny = y + dy2187[k];
			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
				if (visited2187[nx][ny] == false && a2187[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					dist2187[nx][ny] = dist2187[x][y] + 1;
					visited2187[nx][ny] = true;
				}
			}
		}
	} //end while
	cout << dist2187[N][M] << endl;

	return 0;
}