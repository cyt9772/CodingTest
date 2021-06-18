#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


#include <stdio.h>

using namespace std;

#define ARRAY_NUM 1000001
int check_6588[ARRAY_NUM] = { 0, };


int P6588() {
	int i, j;
	vector<int> primes; //�Ҽ� ���� ����
	int pn=0; //�Ҽ� count

	//0,1�� ���� �Ҽ��� �ƴ� ������ ����
	check_6588[0] = 1;
	check_6588[1] = 1;

	//�Ҽ� ���� �̸� ���ؼ� �����ϱ�
	for (i = 2; i < ARRAY_NUM; i++) {
		if (check_6588[i] == 0) {
			//�Ҽ��� �����Ͽ� vector�� push
			primes.push_back(i);
			pn++;
			for (j = 2; i * j < ARRAY_NUM; j++) {
				check_6588[i * j] = 1; //�Ҽ��� �ƴ� ���� ����
			}
		}
	}
	int num;
	int first, second;

	//���
	while (scanf("%d", &num)) {
		if (num == 0)
			break;
		for (i = 1; i <= pn; i++) { //2�� �����ϰ� 3����
			first = primes[i];
			second = num - primes[i];
			if (check_6588[second] == 0) {
				printf("%d = %d + %d\n", num, first, second);
				break;
			}
		}
	}
	return 0;
}