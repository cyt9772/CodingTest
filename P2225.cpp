#include<iostream>

#include<stdio.h>

using namespace std;

#define MOD2225 1000000000
long long d2225[201][201];


int P2225() {
	int N, k; //N: 0~N까지의 정수 및 합이 N, k: 0~N까지 중 정수의 개수
	cin >> N >> k;

	int cnt = 0;
	//초기화

	for (int i = 0; i <= N; i++)
		d2225[1][i] = 1; //하나를 선택해서 합이 N인 경우는 N 한가지 뿐임.

	for (int i = 2; i <= k; i++) {
		for (int j = 0; j <= N; j++) {
			for (int m = 0; m <= j; m++) {
				d2225[i][j] = (d2225[i][j]+d2225[i - 1][j - m])%MOD2225;
			}
		}
	}
	cout << d2225[k][N] % MOD2225 << endl;

	return 0;
}