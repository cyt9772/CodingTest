#include<iostream>
#include <stdio.h>

using namespace std;

long long  d15990[100001][4]; //long long으로 선언해야 범위 벗어나지 않음

int P15990() {
	//~3까지 value 초기화
	//d[n][m] =n을 만들때 m으로 끝나는 경우
	//d[n][1]=d[n-1][2]+d[n-1][3]
	//d[n][2]=d[n-2][1]+d[n-2][3]
	//d[n][3]=d[n-3][1]+d[n-3][2]

	d15990[1][1] = 1;
	d15990[2][2] = 1;
	d15990[3][1] = d15990[3][2] = d15990[3][3] = 1;

	int t; //test case
	cin >> t;
	int cnt;
	int n; //입력 n
	for (int i = 0; i < t; i++) {
		cnt = 0;
		cin >> n;
		if (n <= 3) { //기존에 정의되어 있는 value에서 return
			cnt = d15990[n][1] + d15990[n][2] + d15990[n][3];
		}

		for (int j = 4; j <= n; j++) {
			if (d15990[j][1] != 0) continue;
			d15990[j][1] = (d15990[j - 1][2] + d15990[j - 1][3])%1000000009;
			d15990[j][2] = (d15990[j - 2][1] + d15990[j - 2][3])% 1000000009;
			d15990[j][3] = (d15990[j - 3][1] + d15990[j - 3][2])% 1000000009;
		}
		cnt = (d15990[n][1] + d15990[n][2] + d15990[n][3])%1000000009;
		cout << cnt << endl;
	}

	return 0;
}