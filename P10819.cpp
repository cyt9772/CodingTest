#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;

int data10819[10];
bool flag10819[10];
int buf10819[10];
int ans10819;

void chkAns(int n) {
	int tmp=0;
	for (int i = 1; i < n; i++) {
		int buf = 0;
		buf = buf10819[i-1] - buf10819[i];
		if (buf < 0)
			buf = -buf;
		tmp += buf;
	}

	if (tmp > ans10819)
		ans10819 = tmp;
};

void go10819(int index, int n){
	if (index == n) {
		chkAns(n);
	}

	for (int i = 0; i < n; i++) {
		if (flag10819[i]) continue;
		flag10819[i] = true;
		buf10819[index] = data10819[i];
		go10819(index + 1, n);
		flag10819[i] = false;
	}
};

int P10819() {
	int n;
	cin >> n;

	ans10819 = 0;

	for (int i = 0; i < n; i++) {
		cin >> data10819[i];
	}

	go10819(0, n);

	cout << ans10819;
	return 0;
}