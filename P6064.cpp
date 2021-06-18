#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

#include<stdio.h>

using namespace std;

int P6064() {
	//전체 test case 입력
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		//Test Case동안  M,N,x,y 입력
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		
		//modulo 연산을 위해 x,y 하나씩 감소
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