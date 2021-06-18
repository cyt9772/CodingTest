#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

#include<stdio.h>

using namespace std;


int data_T_14501[15];
int data_P_14501[15];
int ans_14501;

//재귀함수
void go_14501(int day, int sum, int retireDay) {
	if (day == retireDay) {
		if (ans_14501 < sum)
			ans_14501 = sum;
		return;		
	}
	if (day > retireDay)
		return;

	go_14501(day + 1, sum, retireDay);
	go_14501(day + data_T_14501[day], sum+data_P_14501[day], retireDay);

	return;
};


int P14501() {
	int N;
	ans_14501 = 0;
	//N입력
	cin >> N;

	//data 저장
	for (int i = 0; i < N; i++) {
		cin >> data_T_14501[i]>>data_P_14501[i];
	}


	//재귀호출
	go_14501(0, 0, N);

	cout << ans_14501 << endl;

	return 0;
}