#include<iostream>
#include<stdio.h>

using namespace std;



unsigned int d2156[10001][3]; //n번째까지 최대값, 0: n번째 마시지 않은 경우, 1: 1번째 연속, 2: 2번째 연속
int a2156[10001]; //포도주의 양


int P2156() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> a2156[i];
	}

	//초기화
	d2156[1][1] = a2156[1];
	d2156[2][0] = a2156[1];
	d2156[2][1]= a2156[2];
	d2156[2][2] = d2156[1][1]+a2156[2];

	//dynamic programming
	for (int i = 3; i <= N; i++) {
		d2156[i][0] = max(max(d2156[i - 1][0], d2156[i - 1][1]), d2156[i - 1][2]);
		d2156[i][1] = d2156[i-1][0]+a2156[i];
		d2156[i][2] = d2156[i - 1][1] + a2156[i];
	}
	cout << max(max(d2156[N][0], d2156[N][1]), d2156[N][2]) << endl;

	return 0;
}