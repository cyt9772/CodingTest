#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;

void combination(vector<char> arr, vector<char> comb, int r, int index, int depth) {
	if (r == 0) {
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << ' ';
		}
		cout << endl;
	}
	else if (depth == arr.size()) {
		return;
	}
	else
	{
		comb[index] = arr[depth];
		combination(arr, comb, r - 1, index + 1, depth + 1);
		combination(arr, comb, r, index, depth + 1);
	}

};

int Combination() {
	vector<char> vec = { 'a', 'b','c','d','e' };

	int r = 2;
	vector<char> comb(r);

	combination(vec, comb, r, 0, 0);
	return 0;
 }
