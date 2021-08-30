#include <iostream>

using namespace std;

int map14499[21][21];
int dx_14499[] = { 0,0,-1,1 };
int dy_14499[] = { 1,-1, 0, 0 };
int dice14499[6];

int P14499() {
	int n, m, x, y, opcnt;
	cin >> n >> m >> x >> y >> opcnt;

	//map data �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map14499[i][j];
		}
	}

	//operation �Է�
	for (int i = 0; i < opcnt; i++) {
		int k;
		cin >> k;

		k--;
		int nx, ny;  //�̵��Ϸ��� ��ǥ
		nx = x + dx_14499[k];
		ny = y + dy_14499[k];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m)  //������ ������ ��� ��ǥ
			continue;
		if (k == 0) { //����(������)
			int temp = dice14499[1];
			dice14499[1] = dice14499[4];
			dice14499[4] = dice14499[6];
			dice14499[6] = dice14499[5];
			dice14499[5] = temp;
		}
		if (k == 1) { //����(����)
			int temp = dice14499[1];
			dice14499[1] = dice14499[5];
			dice14499[5] = dice14499[6];
			dice14499[6] = dice14499[4];
			dice14499[4] = temp;
		}
		if (k == 2) { //����(����)
			int temp = dice14499[1];
			dice14499[1] = dice14499[3];
			dice14499[3] = dice14499[6];
			dice14499[6] = dice14499[2];
			dice14499[2] = temp;
		}
		if (k == 3) { //����(�Ʒ���)
			int temp = dice14499[1];
			dice14499[1] = dice14499[2];
			dice14499[2] = dice14499[6];
			dice14499[6] = dice14499[3];
			dice14499[3] = temp;
		}
		x = nx;
		y = ny;

		if (map14499[x][y] == 0) { //�ٴ��� 0�̶�� �ֻ����� ���� �ٴ����� ����
			map14499[x][y] = dice14499[6];
		}
		else { //�ٴ��� 0�� �ƴ϶�� �ֻ����� �ٴڰ��� ������ �ٴ� ������ �����ϰ� ������ 0
			dice14499[6] = map14499[x][y];
			map14499[x][y] = 0;
		}
		//operation���� ������ ���� ǥ��
		cout << dice14499[1] << endl;
	}

	return 0;
}