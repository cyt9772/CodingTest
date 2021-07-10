#include<iostream>

#include<stdio.h>

using namespace std;

int d[1000001];

int P1463() {
	int cnt = 0;
	int n;
	cin >> n;

	d[0] = 0;
	d[1] = 0;
	d[2] = 1;
	d[3] = 1;
	
	if (n == 2 or n == 3) {
		cnt = 1;
		cout << cnt << endl;
		return 0;
	}
	
	for (int i = 4; i <= n ; i++) {
		int cnt2 = 0;
		int m1, m2;

		//2의 배수 체크
		if (i % 2 == 0) {
			cnt2 = d[i / 2] + 1;
		}
		else {
			m1 = i - 1;
			cnt2 = d[m1 / 2] + 2;
		}

		//3의 배수 기준 
		int cnt3 = 0;
		if (i % 3 == 0) {
			cnt3 = d[i / 3] + 1;
		}
		else {
			m2= (int)(i / 3) * 3;
			cnt3 = d[m2 / 3] + i-m2+1;
		}
		cnt = min(cnt2, cnt3);
		d[i] = cnt;
	}

	cout << d[n] << endl;

	return 0;
}