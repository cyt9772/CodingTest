#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#include<stdio.h>

using namespace std;

bool c_15656[10];
int a_15656[10];
vector<int>  data_15656;

int go_15656(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", a_15656[i]);
		}
		printf("\n");
		return 0;
	}

	for (int i = 0; i < n; i++) {
//		if (c_15656[i]) continue;
		c_15656[i] = true;  a_15656[index] = data_15656[i];
		go_15656(index + 1, i , n, m);
//		c_15656[i] = false;
	}
	return 0;
};

int P15656() {
	int n, m;
	int input;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		data_15656.push_back(input);
	}
	sort(data_15656.begin(), data_15656.end());
	go_15656(0, 0, n, m);
	return 0;
}