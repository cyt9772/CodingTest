#include<iostream>
#include<stdio.h>

using namespace std;

/*d[n][m] 을 n번째 m으로 끝나는 경우 가정
* d[n][m]=d[n-1][m]+d[n-1][m-1]  + ...+ d[n-1][0]
*/

#define MOD11057 10007

long long d11057[1001][10];


int P11057() {

	int N;
	cin >> N;

	//초기화
	for (int i = 0; i < 10; i++) {
		d11057[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				d11057[i][j] += (d11057[i - 1][k])%MOD11057;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans += d11057[N][i];

	cout << ans % MOD11057 << endl;

	return 0;
}
