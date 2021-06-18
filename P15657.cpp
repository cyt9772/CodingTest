#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#include<stdio.h>

using namespace std;

bool c_15657[10];
int a_15657[10];
vector<int>  data_15657;

int go_15657(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", a_15657[i]);
		}
		printf("\n");
		return 0;
	}

	for (int i = start; i < n; i++) {
		//		if (c_15657[i]) continue;
		c_15657[i] = true;  a_15657[index] = data_15657[i];
		go_15657(index + 1, i, n, m);
		//		c_15657[i] = false;
	}
	return 0;
};

int P15657() {
	int n, m;
	int input;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		data_15657.push_back(input);
	}
	sort(data_15657.begin(), data_15657.end());
	go_15657(0, 0, n, m);
	return 0;
}