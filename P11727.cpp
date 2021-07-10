#include<iostream>

#include<stdio.h>

using namespace std;

int d11727[1001];

int P11727() {
	int n;
	cin >> n;

	//Á¡È­½Ä d[n]=d[n-1] + 2d[n-2]
	d11727[1] = 1;
	d11727[2] = 3;

	for (int i = 3; i <= n; i++) {
		d11727[i] = (d11727[i - 1] + 2 * d11727[i - 2])%10007;
	}
	cout << d11727[n] << endl;

	return 0;
}