#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;

int P10974() {
	vector<int> data;

	int n;
	cin >> n;

	for (int i = 1; i <=n; i++) {
		data.push_back(i);
	}

	do {
		for (int i = 0; i < n; i++) {
			cout << data[i] << ' ';
		}
		cout << '\n';

	} while (next_permutation(data.begin(), data.end()));
		
	return 0;
}