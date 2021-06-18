#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

#include<stdio.h>

using namespace std;


bool c_15649[10]; int a_15649[10];

int go_15649(int index, int n, int m) {
	if (index == m) {
		//출력
		for (int i = 0; i < m; i++)
			printf("%d ", a_15649[i]);
		printf("\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (c_15649[i]) continue;
		c_15649[i] = true; a_15649[index] = i;
		go_15649(index + 1, n, m);
		c_15649[i] = false;
	}
	return 0;
};

/* 전체 N개 중에서 M개를 선택하는 방법*/
int P15649() {
	int n, m;
	cin >> n >> m;
	go_15649(0, n, m);
	return 0;
}