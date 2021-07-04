#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;

vector<int> data1182;

int ans1182, n1182, s1182;

void go1182(vector<int> buf, int r, int index, int depth) {
	if (r == 0) {
		int tempSum = 0;
/*		if (buf.size() == 3) {
			for (int i = 0; i < buf.size(); i++) {
				cout << buf[i] << ' ';
			}
			cout << endl;
		} */
		for (int i = 0; i < buf.size(); i++) {
			tempSum += buf[i];
		}
		if (tempSum == s1182)
			ans1182++;

		return;
	}
	else if (depth == data1182.size()) {
		return;
	}
	else
	{
		buf[index] = data1182[depth];
		go1182(buf, r - 1, index + 1, depth + 1);
		go1182(buf, r, index, depth + 1);
	}
};

int P1182(){
	int N, S;
	cin >> N >> S;

	n1182 = N;
	s1182 = S;

	int input = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;
		data1182.push_back(input);
	}

	for (int r = 1; r <= N; r++) {
		vector<int> buf(r);

		go1182(buf, r, 0, 0);
	}
	cout << ans1182<<endl;
	data1182.clear();

	return 0;
}