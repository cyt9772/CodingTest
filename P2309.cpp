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
	bool setFlag = false; //100���� ã���� ��� true

	//Ű�� �Է¹޾� ����
	for (i = 0; i < 9; i++) {
		scanf("%d", dwarf+i);
	}

	//��ü Ű�� ��
	for (i = 0; i < 9; i++)
		total += dwarf[i];

	//�� ���� ����
	for (i = 0; i < 9; i++) {
		if (setFlag)
			break;
		for (j = (i + 1); j < 9; j++) {
			//�θ��� Ű ��
			pSum = dwarf[i] + dwarf[j];

			//������ 7���� Ű���� 100�̸�,
			if ((total - pSum) == 100) {
				for (k = 0; k < 9; k++) {
					//i,j��° �����ϰ� vector�� ����
					if ((k != i) && (k != j)) {
						height.push_back(dwarf[k]);
					}
				}
				setFlag = true;
				break;
			}
		}
	}

	//7���� sort() & ���
	sort(height.begin(), height.end());
	for (i = 0; i < height.size(); i++)
		printf("%d\n", height[i]);

	return 0;
}