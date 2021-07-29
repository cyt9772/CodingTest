#include<iostream>
#include<vector>

#include<stdio.h>

/*
4
6 5 7 3
*/
using namespace std;

int a11722[1001];
int L11722[1001];

int P11722() {
	int n;
	cin >> n; //입력 데이터 개수

	for (int i = 1; i <= n; i++)
		cin >> a11722[i];

	for (int i = 1; i <= n; i++) {
		L11722[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (a11722[j] > a11722[i] && L11722[i] < L11722[j]+1) {
				L11722[i] = L11722[j] + 1;
			}
		}
	}
	int maxVal = 0;
	for (int i = 1; i <= n; i++) {
		if (L11722[i] > maxVal)
			maxVal = L11722[i];
	}
	cout << maxVal << endl;

	return 0;
}