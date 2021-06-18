#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

#include<stdio.h>

using namespace std;


int data_14889[20][20];
bool flag_14889[20];
vector<int> team1, team2;
int sum1_14889, sum2_14889;
int diff_14889;


//재귀함수
void go_14889(int index, int start, int n) {
	if (index==n/2) {
		//team1 & team2로 구분
		for (int i = 0; i < n; i++) {
			bool ok = true;
			for (int j = 0; j < (n / 2); j++) {
				if (i == team1[j]) {
					ok = false;
					break;
				}
			}
			if(ok)
				team2.push_back(i);
		}

		//team의 합 구하기
		sum1_14889 = 0;
		sum2_14889 = 0;
		//team1
		for (int i = 0; i < team1.size(); i++)
			for (int j = 0; j < team1.size(); j++) {
				if (i == j) continue;
				sum1_14889 += data_14889[team1[i]][team1[j]];
				sum2_14889 += data_14889[team2[i]][team2[j]];
			}
		//team2 clear
		team2.clear();

		int diff = sum1_14889 - sum2_14889;
		if (diff < 0)
			diff = -diff;

		if (diff < diff_14889)
			diff_14889 = diff;
		return;
	}  //end index==n/2

	for (int i = start; i < n; i++) {
		if (flag_14889[i] == true) continue;
		flag_14889[i] = true; team1.push_back(i);
		go_14889(index + 1, i+1, n);
		flag_14889[i] = false; team1.pop_back();
	}
	return;
};


int P14889() {
	int N;

	diff_14889 = 500000;
	//N입력
	cin >> N;

	//data 저장
	for (int i = 0; i < N; i++) 
		for(int j=0;j<N;j++){
		cin >> data_14889[i][j];
	}

	//재귀호출
	go_14889(0, 0, N);

	cout << diff_14889<<endl;
	return 0;
}