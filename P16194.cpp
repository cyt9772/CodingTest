#include<iostream>

#include<stdio.h>

using namespace std;

int d16194[1001];
int p16194[1001];

int P16194() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p16194[i];
	}

	d16194[1] = p16194[1];
	d16194[2] = min(p16194[2], 2 * p16194[1]);

	for (int i = 3; i <= n; i++) {
		int subsum = 1000*10000;
		for (int j = 1; j <= i; j++) {
			int tempsum = p16194[j] + d16194[i - j];
			subsum = min(subsum, tempsum);
		}
		d16194[i] = subsum;
	}

	cout << d16194[n] << endl;

	return 0;
}
