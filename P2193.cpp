#include<iostream>
#include<stdio.h>

using namespace std;


long long d2193[91];


int P2193() {
	int n; //�Է� �ڸ���
	cin >> n;

	//data �ʱ�ȭ
	d2193[1] = 1;
	d2193[2] = 1;

	for (int i = 3; i <= n; i++) {
		d2193[i] = d2193[i - 1] + d2193[i - 2];
	}

	cout << d2193[n] << endl;

	return 0;
}