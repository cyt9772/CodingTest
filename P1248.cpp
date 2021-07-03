#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;


int data1248[10]; //배열의 최대 크기
char sign1248[10][10]; //각 위치의 부호 저장


//현재 index 숫자 부호와 합의 부호를 check
bool chk1248(int index, int val) { 

	//1. index 부호 확인
	if (sign1248[index][index] == '-') {
		if (val >= 0) return false;
	}
	else if (sign1248[index][index] == '0') {
		if (val) return false;
	}
	else { //양수
		if (val <= 0) return false;
	}

	//2. s[i][j]의 value 비교
//	for (int i = index; i >=0; i--) {
		int partialSum = 0;
		for (int j = 0; j < index; j++) {
			partialSum += data1248[j];
		}
		partialSum += val; //현재 더하고자 하는 값을 비교

		if (partialSum == 0) {
			if (sign1248[0][index] != '0') return false;
		}
		else if (partialSum > 0) {
			if (sign1248[0][index] != '+') return false;
		}
		else if (partialSum < 0) {
			if (sign1248[0][index] != '-') return false;
		}
//	}
	return true;
};


void go1248(int index, int n) {
	if (index == n) { //N만큼 필요한 수를 확보
		for (int i = 0; i < n; i++) {
			cout << data1248[i]<<' ';
		}
		cout << endl;
		exit(0);  //하나만 출력하면 되므로 종료
	}

	for (int i = -10; i <= 10; i++) {
		if (!chk1248(index, i)) continue; //유효하지 않을 경우 계속
		data1248[index] = i;
		go1248(index + 1, n);
	}
};


int P1248() {
	int n; //배열의 개수
	cin >> n;

	char instr[64];
	cin >> instr;

	int k = 0;
	for(int i=0;i<n;i++)
		for (int j = i; j < n; j++) {
			sign1248[i][j] = instr[k];
			k++;
		}
	go1248(0,n);

	return 0;
}