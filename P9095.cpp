#include<iostream>
#include<string>
#include<vector>
#include<cstdio>

#include<stdio.h>

using namespace std;

int go_9095(int sum, int n) {
	if (sum > n) return 0;
	if (sum == n) return 1;
	int cnt = 0;
	for (int i = 1; i <= 3; i++) {
		cnt += go_9095(sum + i, n);
	}
	return cnt;
}

int P9095() {
	int cases[11] = { 0, };
	
	cases[1] = 1;
	cases[2] = 2;
	cases[3] = 4;

	for (int i = 4; i < 11; i++) 
		cases[i] = cases[i - 3] + cases[i - 2] + cases[i - 1];
	
	int T,n;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << cases[n] << endl;
	}

	return 0;
	}

int P9095_1() {
	int t, n;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << go_9095(0, n)<<endl;
	}
	return 0;
}

	