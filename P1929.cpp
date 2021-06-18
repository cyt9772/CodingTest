#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


#include <stdio.h>

using namespace std;

#define ARRAY_NUM 1000001
int check_1929[ARRAY_NUM] = { 0, };


int P1929() {
	int i, j;

	//0,1에 대해 소수가 아닌 것으로 설정
	check_1929[0] = 1;
	check_1929[1] = 1;

	for (i = 2; i < ARRAY_NUM; i++) {
		if (check_1929[i] == 0) {
			for (j = 2; i * j < ARRAY_NUM; j++) {
				check_1929[i * j] = 1;
			}
		}
	}

	int start, end;
	scanf("%d %d", &start, &end);

	for (i = start; i <= end; i++) {
		if (check_1929[i] == 0)
			printf("%d\n", i);
	}
	return 0;
}