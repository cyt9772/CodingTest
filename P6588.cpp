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
	vector<int> primes; //소수 저장 공간
	int pn=0; //소수 count

	//0,1에 대해 소수가 아닌 것으로 설정
	check_6588[0] = 1;
	check_6588[1] = 1;

	//소수 값을 미리 구해서 정리하기
	for (i = 2; i < ARRAY_NUM; i++) {
		if (check_6588[i] == 0) {
			//소수만 추출하여 vector에 push
			primes.push_back(i);
			pn++;
			for (j = 2; i * j < ARRAY_NUM; j++) {
				check_6588[i * j] = 1; //소수가 아닌 것은 제거
			}
		}
	}
	int num;
	int first, second;

	//출력
	while (scanf("%d", &num)) {
		if (num == 0)
			break;
		for (i = 1; i <= pn; i++) { //2는 제외하고 3부터
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