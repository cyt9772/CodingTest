#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

#include<stdio.h>

using namespace std;

int P6064() {
	//��ü test case �Է�
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		//Test Case����  M,N,x,y �Է�
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		
		//modulo ������ ���� x,y �ϳ��� ����
		x -= 1;
		y -= 1;
		bool ok = false;

		for (int k = x; k < N * M; k += M) {
			if (k % N == y) {
				printf("%d\n", k + 1);
				ok = true;
				break;
			}
		}

		if (!ok) {
			printf("-1\n");
		}

	}
	return 0;
}