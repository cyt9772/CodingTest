#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

#include<stdio.h>

using namespace std;


bool c_16560[10]; int a_16560[10];

int go_16560(int index,int start,  int n, int m) {
	if (index == m) {
		//출력
		for (int i = 0; i < m; i++)
			printf("%d ", a_16560[i]);
		printf("\n");
		return 0;
	}
	for (int i = start; i <= n; i++) {
		if (c_16560[i]) continue;
		c_16560[i] = true; a_16560[index] = i;
		go_16560(index+1, i + 1, n, m);
		c_16560[i] = false;
	}
	return 0;
};

/* 전체 N개 중에서 M개를 선택하는 방법*/
int P15650() {
	int n, m;
	cin >> n >> m;
	go_16560(0, 1, n, m);
	return 0;
}