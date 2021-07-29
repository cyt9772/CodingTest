#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;
int a1149[1001][3]; //[집의 수][RGB]
long long  d1149[1001][3]; //최소 비용 관리

int P1149() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &a1149[i][0], &a1149[i][1], &a1149[i][2]);  //비용 입력
	}

	//비용 초기화
	d1149[1][0] = a1149[1][0]; //R
	d1149[1][1] = a1149[1][1]; //G
	d1149[1][2] = a1149[1][2]; //B

	for (int i = 2; i <= N; i++) {
		d1149[i][0] = min(d1149[i - 1][1] + a1149[i][0], d1149[i - 1][2] + a1149[i][0]); //R을 선택한 경우
		d1149[i][1] = min(d1149[i - 1][0] + a1149[i][1], d1149[i - 1][2] + a1149[i][1]); //G을 선택한 경우
		d1149[i][2] = min(d1149[i - 1][0] + a1149[i][2], d1149[i - 1][1] + a1149[i][2]); //B을 선택한 경우
	}

	long long  minVal = 1000*1000;
	for (int i = 0; i < 3; i++) {
		minVal = min(minVal, d1149[N][i]);
	}

	cout << minVal << endl;


	return 0;
}