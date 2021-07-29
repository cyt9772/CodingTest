#include<iostream>
#include<stdio.h>

using namespace std;
int a1932[501][501];  //입력
int d1932[501][501]; //최대 저장

int P1932() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a1932[i][j];
		}
	}

	//초기화
	d1932[1][1] = a1932[1][1];

	//DP
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d1932[i][j] = max(d1932[i - 1][j - 1], d1932[i - 1][j]) + a1932[i][j];
		}
	}

	int maxVal = 0;
	for (int i = 1; i <= n; i++) {
		if (d1932[n][i] > maxVal)
			maxVal = d1932[n][i];
	}
	cout << maxVal << endl;

	return 0;
}