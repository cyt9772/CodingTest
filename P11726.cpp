#include<iostream>

#include<stdio.h>

using namespace std;
int d11726[1001];

int P11726() {
	int n; //2xn ют╥б
	cin >> n;
	
	d11726[1] = 1;
	d11726[2] = 2;
	if (n < 3) {
		cout << d11726[n] << endl;
		return 0;
	}

	for (int i = 3; i <= n; i++) {

		d11726[i] = (d11726[i - 1] + d11726[i - 2])%10007;
	}

	cout << d11726[n] << endl;

	return 0;
}
