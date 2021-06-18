#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>

#include<stdio.h>

using namespace std;
/* 숫자버튼 + 채널 증감의 형태*/
int getPressCount(int channel, int* broken, int br_cnt);

int P1107() {
	const int max_1107=500000;
	//current 채널 100
	int current_Ch = 100;

	//target 채널 입력 받음
	int targetCh;
	cin >> targetCh;

	//고장난 버튼 입력 받음
	int broken[10];
	int broken_num;

	cin >> broken_num;

	for (int i = 0; i < broken_num; i++) {
		cin >> broken[i];
	}

	//이동하려는 채널을 확인 후 고장난 버튼 있는지 확인
	//max가 500000이므로 max channel까지만 확인
	int current_check_high = targetCh;
	int current_check_low = targetCh;
	int length_high, btnPress_high;
	int length_low, btnPress_low;
	bool find_lowest_count = false;

	//target과 current 동일시에는 바로 출력
//	if (current_Ch == targetCh) {
//		printf("0\n");
//		return 0;
//	}

	for (int i = 0; i < max_1107; i++) {
		//target보다 큰 부분 check
		current_check_high = targetCh + i;
		if (length_high=getPressCount(current_check_high, broken, broken_num)) {
			btnPress_high = targetCh - current_check_high;
			if (btnPress_high< 0)
				btnPress_high = -btnPress_high;
			if (!find_lowest_count) {
				int pressCnt = targetCh - 100;
				if (pressCnt < 0)
					pressCnt = -pressCnt;
				find_lowest_count = true;
				if((btnPress_high+length_high) > pressCnt)
					printf("%d\n", pressCnt);
				else
					printf("%d\n", btnPress_high + length_high);
				break;
			}
		}
		//target보다 작은 부분 check
		current_check_low = targetCh - i;
		if (length_low = getPressCount(current_check_low, broken, broken_num)) {
			btnPress_low = targetCh - current_check_low;
			if (btnPress_low < 0)
				btnPress_low = -btnPress_low;
			if (!find_lowest_count) {
				int pressCnt = targetCh - 100;
				if (pressCnt < 0)
					pressCnt = -pressCnt;
				find_lowest_count = true;
				if ((btnPress_low + length_low) > pressCnt)
					printf("%d\n", pressCnt);
				else
					printf("%d\n", btnPress_low + length_low);
				break;
			}
		}
	}
	return 0;
}

/* channel 정보의 유효성 검사 및 눌러야 하는 버튼 횟수 return*/
int getPressCount(int channel, int* broken, int br_cnt) {
	if (channel > 1000000 || channel < 0)
		return 0;

	int count; //누르는 버튼 count
	string str_ch = to_string(channel);
	count = str_ch.length();

	int check_value = channel;
	int check_remainer;
	//유효성 검사
	while (1) {
		check_remainer = check_value % 10;
		for (int i = 0; i < br_cnt; i++) {
			if (broken[i] == check_remainer) {
				return 0; //error(invalid) return
			}
		}
		if (check_value < 10)  //몫이 10보다 작으면 break
			break;
		check_value = check_value / 10;
	}
	return count;
}

bool broken[10];

int possible(int c) {
	if (c == 0) {
		if (broken[0])
			return 0;
		else
			return 1;
	}

	int len = 0;
	while (c > 0) {
		if (broken[c % 10]) {
			return 0;
		}
		len += 1;
		c /= 10;
	}
	return len;
}

int P1107_1(){

	int n;
	cin >> n; //target channel

	int m;
	cin >> m; //고장난 채널 수

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}

	//초기화
	int ans = n - 100; 
	if (ans < 0)
		ans = -ans;

	for (int i = 0; i <= 1000000; i++) {
		int c = i;
		int len = possible(c);
		if (len > 0) {
			int press = c - n;
			if (press < 0)
				press = -press;
			if (ans > len + press)
				ans = len + press;
		}
	}
	printf("%d\n", ans);

	return 0;
}

