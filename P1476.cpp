#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


#include <stdio.h>

using namespace std;

//��ü ������� ����
int year[15][28][19];

int P1476() {
	
	//��ü ������� ����
	int count = 1;
	int i, j, k;
	i = j = k = 1;
	while (1) {
		year[i - 1][j - 1][k - 1] = count;

		if (count == 15 * 28 * 19) //��ü ���� �� ä������ Ȯ��
			break;
		else {
			i++; j++; k++;
			if (i > 15)
				i = (i % 15);
			if (j > 28)
				j = (j % 28);
			if (k > 19)
				k = (k % 19);
		}
		count++;
	}

	//input���� 3���� ESM �޾Ƶ��̱�
	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);

	//table���� ���
	printf("%d\n", year[e - 1][s - 1][m - 1]);

	return 0;
}
int P1476_1() {

	//input���� 3���� ESM �޾Ƶ��̱�
	int e, s, m;
	scanf("%d %d %d", &e, &s, &m);

	//����� 0���� �̸� ����
	e = e % 15;
	s = s % 28;
	m = m % 19;

	for (int i = 1;; i++) {
		if (i % 15 == e && i % 28 == s && i % 19 == m) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}