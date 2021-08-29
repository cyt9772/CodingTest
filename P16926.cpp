#include <iostream>
#include <vector>

using namespace std;

int map16926[301][301];


int P16926() {
	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map16926[i][j];
		}
	}

	vector<vector<int>> groups;
	//group의 개수 구하기
	int groupn = min(m, n) / 2;

	//일차원 배열로 바꾸기
	for (int k = 0; k < groupn; k++) {
		vector<int> group;
		for (int i = k+1; i <= m - k-1; i++) { //상단 가로
			group.push_back(map16926[k+1][i]);
		}

		for (int i = k + 1; i <= n - k - 1; i++) {  //오른쪽 세로
			group.push_back(map16926[i][m-k]);
		}

		for (int i = m-k; i > k + 1; i--) {  //하단 가로
			group.push_back(map16926[n-k][i]);
		}

		for (int i = n - k; i > k + 1; i--) {  //왼쪽 가로
			group.push_back(map16926[i][k+1]);
		}
		groups.push_back(group);

	}

	//rotate
	for (int k = 0; k < groupn; k++) {
		vector<int>& group = groups[k];
		int len = group.size();
		int index = r % len;

		for (int i = k + 1; i <= m - k - 1; i++, index=(index+1)%len) { //상단 가로
			map16926[k + 1][i] = group[index];
		}

		for (int i = k + 1; i <= n - k - 1; i++,  index = (index + 1) % len) {  //오른쪽 세로
			map16926[i][m - k]=group[index];
		}

		for (int i = m - k; i > k + 1; i--, index = (index + 1) % len) {  //하단 가로
			map16926[n - k][i]=group[index];
		}

		for (int i = n - k; i > k + 1; i--, index = (index + 1) % len) {  //왼쪽 가로
			map16926[i][k + 1]=group[index];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << map16926[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}