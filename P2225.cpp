#include<iostream>

#include<stdio.h>

using namespace std;

#define MOD2225 1000000000
long long d2225[201][201];


int P2225() {
	int N, k; //N: 0~N������ ���� �� ���� N, k: 0~N���� �� ������ ����
	cin >> N >> k;

	int cnt = 0;
	//�ʱ�ȭ

	for (int i = 0; i <= N; i++)
		d2225[1][i] = 1; //�ϳ��� �����ؼ� ���� N�� ���� N �Ѱ��� ����.

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