#include <iostream>
#include <memory>

using namespace std;

int map16935[101][101];
int output16935[101][101];
int row16935, col16935;

void oper1(int row, int col) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			output16935[i][j] = map16935[row - i + 1][j];
		}
	}
	row16935 = row;
	col16935 = col;
}

void oper2(int row, int col) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			output16935[i][j] = map16935[i][col-j+1];
		}
	}
	row16935 = row;
	col16935 = col;
}

void oper3(int row, int col) {
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			output16935[i][j] = map16935[row-j+1][i];
		}
	}
	row16935 = col;
	col16935 = row;
}

void oper4(int row, int col) {
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			output16935[i][j] = map16935[j][col-i+1];
		}
	}
	row16935 = col;
	col16935 = row;
}

void oper5(int row, int col) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (i <= (row / 2) && j <= (col / 2)) {
				output16935[i][j] = map16935[i+row/2][j];
			}
			if (i <= (row / 2) && j > (col / 2)) {
				output16935[i][j] = map16935[i][j-col/2];
			}
			if (i > (row / 2) && j > (col / 2)) {
				output16935[i][j] = map16935[i - row / 2][j];
			}
			if (i > (row / 2) && j <= (col / 2)) {
				output16935[i][j] = map16935[i ][j+col/2];
			}
		}
	}
}

void oper6(int row, int col) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (i <= (row / 2) && j <= (col / 2)) {
				output16935[i][j] = map16935[i ][j+col/2];
			}
			if (i <= (row / 2) && j > (col / 2)) {
				output16935[i][j] = map16935[i+row/2][j];
			}
			if (i > (row / 2) && j > (col / 2)) {
				output16935[i][j] = map16935[i][j-col/2];
			}
			if (i > (row / 2) && j <= (col / 2)) {
				output16935[i][j] = map16935[i-row/2][j];
			}
		}
	}
}

int main() {
	int n, m, opcnt; //�迭 ũ��, operation ����

	cin >> n >> m >> opcnt;

	row16935 = n;
	col16935 = m;

	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >>output16935[i][j];
		}
	}
	
	for (int i = 0; i < opcnt; i++) {
		int op;
		cin >> op;

		memcpy(map16935, output16935, sizeof(output16935));

		switch (op) {
		case 1:
			oper1(row16935, col16935);
			break;
		case 2:
			oper2(row16935, col16935);
			break;
		case 3:
			oper3(row16935, col16935);
			break;
		case 4:
			oper4(row16935, col16935);
			break;
		case 5:
			oper5(row16935, col16935);
			break;
		case 6:
			oper6(row16935, col16935);
			break;
		}

	}
	
	for (int i = 1; i <= row16935; i++) {
		for(int j = 1; j <= col16935; j++) {
			cout << output16935[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

