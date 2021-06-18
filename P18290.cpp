#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

#include<stdio.h>
using namespace std;

int data_18290[10][10]; //data 저장공간
bool data_flag_18290[10][10]; //flag 공간

int dx[] = { 0,0,1,-1 };
int dy[] = { 1, -1, 0,0 };

int ans = -50000;
int n, m, k;

void go_18290(int px, int cnt, int sum) {
	if (cnt == k) {
		if (ans < sum)
			ans = sum;
		return;
	}
	int nx, ny; //x,y임시좌표

	for (int i = px; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (data_flag_18290[i][j] == true) continue;
			bool ok = true;
			for (int l = 0; l < 4; l++) {
				nx = i + dx[l];
				ny = j + dy[l];

				if (nx >= 0 && nx < n && ny >= 0 && ny < m) { //유효한 범위내에 있으면
					if (data_flag_18290[nx][ny]) { //인접한 칸이 있으면
						ok = false;
						break; //다음칸으로
					}
				}
			}
			if (ok) { //유효한 범위내에 인접한 칸이 없다면,
				data_flag_18290[i][j] = true;
				go_18290(i, cnt + 1, sum + data_18290[i][j]);
				data_flag_18290[i][j] = false;
			}
		}
	}
}

int P18290() {
	cin >> n >> m >> k;  //입력
	//data 초기화
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> data_18290[i][j];

	go_18290(0, 0, 0);
	cout << ans << endl;
	return 0;

}