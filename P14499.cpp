#include <iostream>

using namespace std;

int map14499[21][21];
int dx_14499[] = { 0,0,-1,1 };
int dy_14499[] = { 1,-1, 0, 0 };
int dice14499[6];

int P14499() {
	int n, m, x, y, opcnt;
	cin >> n >> m >> x >> y >> opcnt;

	//map data 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map14499[i][j];
		}
	}

	//operation 입력
	for (int i = 0; i < opcnt; i++) {
		int k;
		cin >> k;

		k--;
		int nx, ny;  //이동하려는 좌표
		nx = x + dx_14499[k];
		ny = y + dy_14499[k];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)  //지도의 범위를 벗어난 좌표
			continue;
		if (k == 0) { //동쪽(오른쪽)
			int temp = dice14499[1];
			dice14499[1] = dice14499[4];
			dice14499[4] = dice14499[6];
			dice14499[6] = dice14499[5];
			dice14499[5] = temp;
		}
		if (k == 1) { //서쪽(왼쪽)
			int temp = dice14499[1];
			dice14499[1] = dice14499[5];
			dice14499[5] = dice14499[6];
			dice14499[6] = dice14499[4];
			dice14499[4] = temp;
		}
		if (k == 2) { //북쪽(위쪽)
			int temp = dice14499[1];
			dice14499[1] = dice14499[3];
			dice14499[3] = dice14499[6];
			dice14499[6] = dice14499[2];
			dice14499[2] = temp;
		}
		if (k == 3) { //남쪽(아래쪽)
			int temp = dice14499[1];
			dice14499[1] = dice14499[2];
			dice14499[2] = dice14499[6];
			dice14499[6] = dice14499[3];
			dice14499[3] = temp;
		}
		x = nx;
		y = ny;

		if (map14499[x][y] == 0) { //바닥이 0이라면 주사위의 값을 바닥으로 복사
			map14499[x][y] = dice14499[6];
		}
		else { //바닥이 0이 아니라면 주사위의 바닥값을 지도의 바닥 값으로 설정하고 지도는 0
			dice14499[6] = map14499[x][y];
			map14499[x][y] = 0;
		}
		//operation마다 맨위의 값을 표시
		cout << dice14499[1] << endl;
	}

	return 0;
}