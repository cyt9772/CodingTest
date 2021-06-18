#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


#include <stdio.h>

using namespace std;

//�� ����
char map3085[50][50];

//check function
void map3085_check(int n);

//���ӵ� value ����, �ִ밪�� ��� update
int conti_count=0;

int P3085() {
	//���� ũ�� �Է� �ޱ�
	int N;
	int i, j;

	scanf("%d\n", &N);

	//���� �� ä���
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("\n%c", map3085[i] + j);
//	scanf("%c");  //���๮�� ����
	
	//Ư�� ����Ʈ����  value swap
	for(i=0;i<N;i++)
		for (j = 0; j < N; j++) {
			if (j != N - 1) {
				//row swap
				swap(map3085[i][j], map3085[i][j + 1]);
				//swap�� ���忡�� ���� value üũ
				map3085_check(N);
				//���������� ����
				swap(map3085[i][j], map3085[i][j + 1]);
			}
			else
				continue;
			if (j != N - 1) {
				//column swap
				swap(map3085[i][j], map3085[i + 1][j]);
				//swap�� ���忡�� ���� value üũ
				map3085_check(N);
				//���������� ����
				swap(map3085[i][j], map3085[i + 1][j]);
			}
		}

	//���� value �ִ밪 ���
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