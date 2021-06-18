#include<iostream>
#include<string>
#include<stdio.h>
#include<math.h>

using namespace std;


int P1748() {
	//마지막 숫자를 입력 받음
	int end;
	cin >> end;
	
	//자리수를 구한다
	int pos = to_string(end).length();

	int length = 0;
	//한자리부터 pos까지 숫자길이 더하기
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
