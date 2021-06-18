#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

#include<stdio.h>

using namespace std;

vector<char> data_1759;
char outData_1759[15];
bool data_flag_1759[15];
int L, C; //input ����, L: ��й�ȣ ����, C: �ش� ���� ����

//����� ��ȣ�� ��ȿ�� ����
bool check_1759() {
	int mo = 0, ja = 0;

	for (int i = 0; i < L; i++) {
		if (outData_1759[i] == 'a' or outData_1759[i] == 'e' or outData_1759[i] == 'i' or outData_1759[i] == 'o' or outData_1759[i] == 'u')
			mo += 1;
		else
			ja += 1;
	}

	if (mo >= 1 && ja >= 2)
		return true;
	return false;
};

//����Լ�
void go_1759(int index, int start, int m, int n) {
	if (index == m) {
		if (!check_1759())
			return;
		for (int i = 0; i < m; i++)
			cout << outData_1759[i];
		cout << endl;
		return;
	}

	for (int i = start; i < n; i++) {
		if (data_flag_1759[i]) continue;
		data_flag_1759[i] = true;
		outData_1759[index] = data_1759[i];
		go_1759(index + 1, i+1, m,  n);
		data_flag_1759[i] = false;
	}
	return;

};


int P1759() {

	//L,C �Է�
	cin >> L >> C;

	//data ����
	for (int i=0; i < C; i++) {
		char input;
		cin >> input;
		data_1759.push_back(input);
	}

	//data ����
	sort(data_1759.begin(), data_1759.end());

	//���ȣ��
	go_1759(0, 0, L, C);
	return 0;
}