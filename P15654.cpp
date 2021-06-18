#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

#include<stdio.h>

using namespace std;

bool c_15654[10];
int a_15654[10];
vector<int>  data_15654;

int go_15654(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", a_15654[i]);
		}
		printf("\n");
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (c_15654[i]) continue;
		c_15654[i] = true;  a_15654[index] = data_15654[i];
		go_15654(index + 1,  n, m);
		c_15654[i] = false;
	}
	return 0;
};

int P15654() {
	int n, m;
	int input;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input;
		data_15654.push_back(input);
	}
	sort(data_15654.begin(), data_15654.end());
	go_15654(0,  n, m);
	return 0;
}