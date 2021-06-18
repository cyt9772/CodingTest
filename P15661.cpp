#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

#include<stdio.h>

using namespace std;


int data_15661[20][20];
bool flag_15661[20];
vector<int> team1_15661, team2_15661;
int sum1_15661, sum2_15661;
int diff_15661;


//재귀함수
void go_15661(int index, int start, int n) {
	if (index >1) { //2명 이상이면 매번 팀별 능력치를 계산
		//team1_15661 & team2_15661로 구분
		for (int i = 0; i < n; i++) {
			bool ok = true;
			for (int j = 0; j < team1_15661.size(); j++) {
				if (i == team1_15661[j]) {
					ok = false;
					break;
				}
			}
			if (ok)
				team2_15661.push_back(i);
		}

		//team의 합 구하기
		sum1_15661 = 0;
		sum2_15661 = 0;
		//team1_15661 의 능력치
		for (int i = 0; i < team1_15661.size(); i++)
			for (int j = 0; j < team1_15661.size(); j++) {
				if (i == j) continue;
				sum1_15661 += data_15661[team1_15661[i]][team1_15661[j]];
			}
		//team2_15661 의 능력치
		for (int i = 0; i < team2_15661.size(); i++)
			for (int j = 0; j < team2_15661.size(); j++) {
				if (i == j) continue;
				sum2_15661 += data_15661[team2_15661[i]][team2_15661[j]];
			}
		int diff = sum1_15661 - sum2_15661;
		if (diff < 0)
			diff = -diff;

//		cout << diff << ' ' << diff_15661 << endl;

		if (diff < diff_15661)
			diff_15661 = diff;
		if (team2_15661.size() == 2) {
			team2_15661.clear();
			return;
		}
		//team2_15661 clear
		team2_15661.clear();
	}  //end index==n/2

	for (int i = start; i < n; i++) {
		if (flag_15661[i] == true) continue;
		flag_15661[i] = true; 
		team1_15661.push_back(i);
		go_15661(index + 1, i + 1, n);
		flag_15661[i] = false; 
		team1_15661.pop_back();
	}
	return;
};


int P15661() {
	int N;

	diff_15661 = 500000;
	//N입력
	cin >> N;

	//data 저장
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> data_15661[i][j];
		}

	//재귀호출
	go_15661(0, 0, N);

	cout << diff_15661 << endl;
	return 0;
}