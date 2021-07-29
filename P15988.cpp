#include<iostream>
#include<stdio.h>

using namespace std;
long long d15988[1000001];
#define MOD15988 1000000009

int P15988() {
	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		d15988[0] = 1;
		d15988[1] = 1;
		d15988[2] = 2;
		d15988[3] = 4;
		for (int j = 4; j <= n; j++) {
			if (d15988[j]) continue;
			d15988[j]= (d15988[j-1]+ d15988[j - 2] + d15988[j - 3])%MOD15988 ;
		}
		cout << d15988[n]%MOD15988 << endl;

	}
	return 0;
}