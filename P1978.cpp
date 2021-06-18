#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


#include <stdio.h>

using namespace std;

#define ARRAY_NUM 1001


int P1978() {
	int i, j;
	int check[ARRAY_NUM];

	check[0] = 1;
	check[1] = 1;

	for (i = 2; i < ARRAY_NUM; i++) {
		if (check[i] == 0) {
			for (j = 2; i * j < ARRAY_NUM; j++) {
				check[i * j] = 1;
			}
		}
	}
	int T, value, count=0;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &value);
		if (check[value] == 0)
			count++;
	}
	printf("%d\n", count);
	return 0;
}