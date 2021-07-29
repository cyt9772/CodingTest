#include<iostream>
#include<stdio.h>

using namespace std;


#define mod10844 1000000000
long long d10844[101][10];


int P10844() {
	int n; //입력 자리수
	cin >> n;

	//data 초기화
	d10844[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		d10844[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) { //d[n][j]=d[n-1][j+1]
				d10844[i][0] = (d10844[i - 1][1])%mod10844;
			}
			else if (j == 9) {//d[n][j]=d[n-1][j-1]
				d10844[i][9] = (d10844[i - 1][8])%mod10844;
			}
			else { //d[n][j]=d[n-1][j-1]
				d10844[i][j] = (d10844[i - 1][j+1]+d10844[i-1][j-1])%mod10844;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += d10844[n][i];
	}
	cout << ans % mod10844 << endl;

	return 0;
}