#include<iostream>

#include<stdio.h>

using namespace std;

int d11052[1001];
int p11052[1001];

int P11052(){
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p11052[i];
	}

	d11052[1] = p11052[1];
	d11052[2] = max(p11052[2], 2 * p11052[1]);

	for (int i = 3; i <= n; i++) {
		int subsum = 0;
		for (int j = 1; j <= i ; j++) {
			int tempsum = p11052[j] + d11052[i - j];
			subsum = max(subsum, tempsum);
		}
		d11052[i] = subsum;
	}

	cout << d11052[n] << endl;

	return 0;
}
