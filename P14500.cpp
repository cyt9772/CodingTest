#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#include<stdio.h>

using namespace std;
int board[500][500];
int block[19][3][2] = {
	{{0,1},{0,2},{0,3}},  //직선(옆으로)
	{{1,0},{2,0},{3,0}}, //직선(아래로)
	{{0,1},{1,0},{1,1}},  //정사각형
	{{1,0},{2,0},{2,1}}, // ㄴ-1
	{{1,0},{2,0},{2,-1}}, //2
	{{1,0},{0,1},{0,2}}, //3
	{{0,1},{0,2},{1,2}},  //4
	{{0,1},{1,1},{2,1}}, //5
	{{1,0},{2,0},{0,1}}, //6
	{{0,1},{0,2},{-1,2}},  //7
	{{1,0},{1,1},{1,2}},  //8
	{{1,0},{1,1},{2,1}},  //
	{{1,0},{1,-1},{2,-1}}, //
	{{0,1},{-1,1},{-1,2}}, //
	{{0,1},{1,1},{1,2}}, //
	{{0,1},{0,2},{1,1}}, //
	{{0,1},{0,2},{-1,1}}, //
	{{1,0},{2,0},{1,1}},
	{{1,0},{2,0},{1,-1}},
};

int P14500() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int ans = 0;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 19; k++) {
				bool ok = true;
				int sum = board[i][j];
				for (int l=0; l < 3; l++) {
					int dx = i + block[k][l][0];
					int dy = j + block[k][l][1];
					if (dx >= 0 && dx < n && dy >= 0 && dy < m)
						sum += board[dx][dy];
					else {
						ok = false;
						break;
					}
				}
				if (ok && ans < sum) {
					ans = sum;
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}