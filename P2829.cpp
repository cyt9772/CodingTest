#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;

#define PNUM 2829
int N_PNUM; //부등호 개수
char inEqual_NPUM[9];
bool chkFlag[10];
long long  maxNum_PNUM, minNum_PNUM;
string numMax_PNUM, numMin_PNUM;

int data_PNUM[10];


bool chkValidNum(int n) {
	bool ok = true;
	for (int i = 0; i < n; i++) { //부등호 개수만큼 비교
		if (inEqual_NPUM[i] == '<') {
			if (data_PNUM[i] >= data_PNUM[i + 1]) {
				ok = false;
				break;
			}
		}
		else {  // '>' 일경우
			if (data_PNUM[i] <= data_PNUM[i + 1]) {
				ok = false;
				break;
			}
		}
	}
	return ok;
};

long long my_atoi(char* str) {
	long long ret=0;
	for (int i = 0; str[i] != '\0'; i++) {
		ret=ret*10+ (str[i] - '0');
	}
	return ret;


};

void go_PNUM(int index, int n) {
	if (index == n) {  //n+1개의 숫자를 모두 찾은 경우
		char temp[16];
		if (chkValidNum(N_PNUM)) {
			for (int i = 0; i < n; i++) {
				sprintf(temp + i, "%d", data_PNUM[i]);
			}

			
			long long temp_num = my_atoi(temp);

			if (maxNum_PNUM < temp_num) {
				maxNum_PNUM = temp_num;
				numMax_PNUM = string(temp);
			}
			if (minNum_PNUM > temp_num) {
				minNum_PNUM = temp_num;
				numMin_PNUM = string(temp);
			}
		}
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (chkFlag[i]) continue;
		chkFlag[i] = true; data_PNUM[index] = i;
		go_PNUM(index + 1, n);
		chkFlag[i] = false;
	}


};


int P2829() {
	//초기화
	for (int i = 0; i < 9; i++)
		inEqual_NPUM[i] = NULL;

	cin >> N_PNUM; //개수 저장
	for (int i = 0; i < N_PNUM; i++)
		cin >> inEqual_NPUM[i];
	maxNum_PNUM = 0;
	minNum_PNUM = 9999999999;
	go_PNUM(0, N_PNUM + 1);
	cout << numMax_PNUM << endl;
	cout << numMin_PNUM<< endl;

	return 0;
}