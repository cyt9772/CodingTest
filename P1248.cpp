#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;


int data1248[10]; //�迭�� �ִ� ũ��
char sign1248[10][10]; //�� ��ġ�� ��ȣ ����


//���� index ���� ��ȣ�� ���� ��ȣ�� check
bool chk1248(int index, int val) { 

	//1. index ��ȣ Ȯ��
	if (sign1248[index][index] == '-') {
		if (val >= 0) return false;
	}
	else if (sign1248[index][index] == '0') {
		if (val) return false;
	}
	else { //���
		if (val <= 0) return false;
	}

	//2. s[i][j]�� value ��
//	for (int i = index; i >=0; i--) {
		int partialSum = 0;
		for (int j = 0; j < index; j++) {
			partialSum += data1248[j];
		}
		partialSum += val; //���� ���ϰ��� �ϴ� ���� ��

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
	if (index == n) { //N��ŭ �ʿ��� ���� Ȯ��
		for (int i = 0; i < n; i++) {
			cout << data1248[i]<<' ';
		}
		cout << endl;
		exit(0);  //�ϳ��� ����ϸ� �ǹǷ� ����
	}

	for (int i = -10; i <= 10; i++) {
		if (!chk1248(index, i)) continue; //��ȿ���� ���� ��� ���
		data1248[index] = i;
		go1248(index + 1, n);
	}
};


int P1248() {
	int n; //�迭�� ����
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