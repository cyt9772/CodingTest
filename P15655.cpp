#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#include<stdio.h>

using namespace std;

bool c_15655[10];
int a_15655[10];
vector<int>  data_15655;

int go_15655(int index,int start,  int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", a_15655[i]);
		}
		printf("\n");
		return 0;
	}

	for (int i = start; i < n; i++) {
		if (c_15655[i]) continue;
		c_15655[i] = true;  a_15655[index] = data_15655[i];
		go_15655(index + 1, i+1, n, m);
		c_15655[i] = false;
	}
	return 0;
};

int P15655() {
	int n, m;
	int input;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		data_15655.push_back(input);
	}
	sort(data_15655.begin(), data_15655.end());
	go_15655(0, 0, n, m);
	return 0;
}