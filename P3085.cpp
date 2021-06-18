#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


#include <stdio.h>

using namespace std;

//맵 정의
char map3085[50][50];

//check function
void map3085_check(int n);

//연속된 value 저장, 최대값일 경우 update
int conti_count=0;

int P3085() {
	//보드 크기 입력 받기
	int N;
	int i, j;

	scanf("%d\n", &N);

	//보드 값 채우기
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("\n%c", map3085[i] + j);
//	scanf("%c");  //개행문자 제거
	
	//특정 포인트에서  value swap
	for(i=0;i<N;i++)
		for (j = 0; j < N; j++) {
			if (j != N - 1) {
				//row swap
				swap(map3085[i][j], map3085[i][j + 1]);
				//swap된 보드에서 연속 value 체크
				map3085_check(N);
				//원래값으로 복구
				swap(map3085[i][j], map3085[i][j + 1]);
			}
			else
				continue;
			if (j != N - 1) {
				//column swap
				swap(map3085[i][j], map3085[i + 1][j]);
				//swap된 보드에서 연속 value 체크
				map3085_check(N);
				//원래값으로 복구
				swap(map3085[i][j], map3085[i + 1][j]);
			}
		}

	//연속 value 최대값 출력
	printf("%d", conti_count);

	return 0;
}

void map3085_check(int n) {
	int temp_count;
	char prev_value;

	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			prev_value = map3085[i][j];
			temp_count = 0;

			//row check
			for (int k = 0; k + j < n; k++) {
				if (map3085[i][j + k] == prev_value) {
					temp_count++;
					if (temp_count > conti_count) {
						conti_count = temp_count;
					}
				}
				else {
					temp_count = 0;
					break;
				}
			}
			//column check
			temp_count = 0;
			for (int k = 0; k + i < n; k++) {
				if (map3085[i+k][j] == prev_value) {
					temp_count++;
					if (temp_count > conti_count) {
						conti_count = temp_count;
					}
				}
				else {
					temp_count = 0;
					break;
				}
			}

		}
}