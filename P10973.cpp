#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;

int P10973() {
	int n; //���� ����
	vector<int> a; //data ����

	cin >> n;
	int input;

	for (int i = 0; i < n; i++) {
		cin >> input;
		a.push_back(input);
	}

	if (prev_permutation(a.begin(), a.end())) {
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
	}
	else {
		cout << "-1";
	}
	cout << endl;
	return 0;
}