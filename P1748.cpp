#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>

using namespace std;


int P1748() {
	//������ ���ڸ� �Է� ����
	int end;
	cin >> end;
	
	//�ڸ����� ���Ѵ�
	int pos = to_string(end).length();

	int length = 0;
	//���ڸ����� pos���� ���ڱ��� ���ϱ�
	for (int i = 1; i <= pos; i++) {
		if (i == pos) {
			length += (end - pow(10, pos - 1) + 1) * pos;
		}
		else {
			int count = (pow(10, i )-pow(10,i-1)) * i;
			length += count;
		}
	}
	cout << length << endl;

	return 0;
}
