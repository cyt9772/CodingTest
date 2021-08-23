#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//data 저장
int a2667[30][30]; //데이터 저장
int d2667[30][30];  // cnt value 저장

int dx2667[] = { 1, -1, 0, 0 };
int dy2667[] = { 0,0,-1,1 };

int ans2667[625];
void dfs2667(int row, int col, int N, int num) {
	d2667[row][col] = num;
	for (int k = 0; k < 4; k++) {
		int nx = row + dx2667[k];
		int ny = col + dy2667[k];
		if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
			if(a2667[nx][ny]==1 && d2667[nx][ny]==0)
				dfs2667(nx, ny, N, num);
		}
	}
}

int P2667() {

	int N; //정사각형 N
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &a2667[i][j]);
		}
	}
	int cnt = 0;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (a2667[i][j] == 1 && d2667[i][j] == 0) { //집이 있고, cnt 된 적이 없다면,
				dfs2667(i, j, N, ++cnt);
			}
		}
	}

	cout << cnt << endl;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans2667[d2667[i][j]] += 1;
			}
		}

	sort(ans2667 + 1, ans2667 + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		cout << ans2667[i] << endl;
	}
	return 0;
}