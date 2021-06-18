#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

#include<stdio.h>

using namespace std;

bool c_15651[10];
int a_15651[10];

int go_15651(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", a_15651[i]);
		}
		printf("\n");
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		a_15651[index] = i;
		go_15651(index+1, n, m);
	}

	return 0;
};
int P15651() {
	int n, m;
	cin >> n >> m;

	go_15651(0, n, m);
	return 0;
}