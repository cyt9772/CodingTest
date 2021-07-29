#include<iostream>

#include<stdio.h>

using namespace std;

int a1912[100001];
int d1912[100001];

int P1912() {
	int n;
	cin >> n;

	for (int i=1; i <= n; i++) {
		scanf("%d", &a1912[i]);
	}

	int ans = -1001; //최소 숫자가 1000
	for (int i = 1; i <= n; i++) {
		d1912[i] = a1912[i];
		if (i == 0) continue; //초기화인 경우
		d1912[i] = (a1912[i] < (d1912[i - 1] + a1912[i]) ? (d1912[i - 1] + a1912[i]) : a1912[i]);
		ans = (d1912[i] > ans ? d1912[i] : ans);
	}

	cout << ans << endl;
	return 0;
}