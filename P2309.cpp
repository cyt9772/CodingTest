#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>


#include <stdio.h>

using namespace std;


int P2309() {
	int dwarf[9] = { 0, };
	vector<int> height;

	int i,j,k;
	int total=0;
	int pSum = 0;
	bool setFlag = false; //100합을 찾았을 경우 true

	//키를 입력받아 저장
	for (i = 0; i < 9; i++) {
		scanf("%d", dwarf+i);
	}

	//전체 키의 합
	for (i = 0; i < 9; i++)
		total += dwarf[i];

	//두 명을 고르기
	for (i = 0; i < 9; i++) {
		if (setFlag)
			break;
		for (j = (i + 1); j < 9; j++) {
			//두명의 키 합
			pSum = dwarf[i] + dwarf[j];

			//나머지 7명의 키합이 100이면,
			if ((total - pSum) == 100) {
				for (k = 0; k < 9; k++) {
					//i,j번째 제외하고 vector에 저장
					if ((k != i) && (k != j)) {
						height.push_back(dwarf[k]);
					}
				}
				setFlag = true;
				break;
			}
		}
	}

	//7명을 sort() & 출력
	sort(height.begin(), height.end());
	for (i = 0; i < height.size(); i++)
		printf("%d\n", height[i]);

	return 0;
}