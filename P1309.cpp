#include<iostream>
#include<stdio.h>

using namespace std;
#define MOD1309 9901
/*
* n��° state�� d[n][state]��� �����ϸ� state�� 0(����), 1(����ä��), 2(������ä��)���� ����
* dynamic programming���� �����ϸ�
* d[n][0]=d[n-1][0]+d[n-1][1]+d[n-1][2]
* d[n][1]=d[n-1][0]+d[n-1][2]
* d[n][2]=d[n-1][0]+d[n-1][1]
*/
long long d1309[100001][3];


int P1309() {

	int N;
	cin >> N;

	//�ʱ�ȭ
	d1309[1][0] = 1;
	d1309[1][1] = 1;
	d1309[1][2] = 1;

	for (int i = 2; i <= N; i++) {
		d1309[i][0] = (d1309[i - 1][0] + d1309[i - 1][1] + d1309[i - 1][2])%MOD1309;
		d1309[i][1] = (d1309[i - 1][0] + d1309[i - 1][2]) % MOD1309;
		d1309[i][2] = (d1309[i - 1][0] + d1309[i - 1][1])% MOD1309;
	}
	int result = d1309[N][0] + d1309[N][1] + d1309[N][2];

	cout << result% MOD1309 << endl;

	return 0;
}