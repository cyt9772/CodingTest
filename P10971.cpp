#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;
int cost10971[10][10];
int ans10971;

int chkCost(vector<int> cities, int n, bool* flag) {
	int cost = 0;
	*flag = true;
	for (int i = 0; i < (n-1); i++) {
		if (!cost10971[cities[i]][cities[i + 1]]) { //각 노드별 이동 가능여부 점검
			*flag = false;
			cost = 0;
			return cost;
		}
		cost += cost10971[cities[i]][cities[i + 1]];
	}

	if (!cost10971[cities[n - 1]][cities[0]]) { //최종점에서 시작점 점검
		*flag = false;
		cost = 0;
		return cost;
	}
	cost += cost10971[cities[n - 1]][cities[0]];
	return cost;
};

int P10971() {
	vector<int> cities;
	ans10971 = 1e9;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> cost10971[i][j];
		cities.push_back(i);
	}

	do {
		bool flag;
		int cost = chkCost(cities, n, &flag);
		if (flag)
			ans10971 = min(ans10971, cost);
		else continue;
	} while (next_permutation(cities.begin(), cities.end()));
	
	cout << ans10971;

	return 0;
}