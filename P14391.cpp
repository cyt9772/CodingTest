#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int data14391[4][4];
bool check14391[4][4] = { false, };
int row14391, col14391, result14391 = 0;

void brute(int num, int sum) {
	int x = num % col14391;
	int y = num / col14391;
	if (num >= row14391 * col14391) {
		result14391= max(result14391, sum);
		return;
	}
	if (check14391[y][x]) brute(num + 1, sum);
	else {
		int val, ny, nx;
		val = data14391[y][x];
		check14391[y][x] = true;
		brute(num + 1, sum + val);
		check14391[y][x] = false;
		//밑으로
		for (int k = 1; k < row14391 - y; k++) {
			nx = x;
			ny = y + k;
			val *= 10;
			val += data14391[ny][nx];
			for (int j = 1; j <= k; j++)
				check14391[y + j][nx] = true;
			brute(num + 1, sum + val);
			for (int j = 1; j <= k; j++)
				check14391[y + j][nx] = false;
		}
		val = data14391[y][x];
		//오른쪽으로
		for (int k = 1; k < col14391 - x; k++) {
			ny = y;
			nx = x + k;
			if (check14391[ny][nx]) return;
			val *= 10;
			val += data14391[ny][nx];
			for (int j = 1; j <= k; j++)
				check14391[ny][x + j] = true;
			brute(num + 1, sum + val);
			for (int j = 1; j <= k; j++)
				check14391[ny][x + j] = false;
		}
	}
}

int P14391() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> row14391 >> col14391;
	string str;
	for (int i = 0; i < row14391; i++) {
		cin >> str;
		for (int j = 0; j < col14391; j++)
			data14391[i][j] = str[j] - '0';
	}
	brute(0, 0);
	cout << result14391;
	return 0;
}