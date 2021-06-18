#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#include<stdio.h>

using namespace std;

bool c_15652[10];
int a_15652[10];

int go_15652(int index,int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", a_15652[i]);
		}
		printf("\n");
		return 0;
	}

	for (int i = start; i <= n; i++) {
		a_15652[index] = i;
		go_15652(index + 1, i, n, m);
	}
	return 0;
};

int P15652() {
	int n, m;
	cin >> n >> m;

	go_15652(0, 1, n, m);
	return 0;
}