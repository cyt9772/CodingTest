#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;



int P6603() {
	vector<int> flag;


	while (1) {
		int cnt;
		int a;

		cin >> cnt;

		if (cnt == 0) break;

		vector<int> data(cnt);

		for (int i = 0; i < cnt; i++)
			cin >> data[i];

		sort(data.begin(), data.end());

		for (int i = 0; i < cnt - 6; i++)
			flag.push_back(0);

		for (int i = 0; i < 6; i++)
			flag.push_back(1);

		vector<vector<int>> ans;

		do {
			vector<int> current;
			for (int i = 0; i < cnt; i++) {
				if (flag[i]) {
					current.push_back(data[i]);
				}
			}
			ans.push_back(current);
		} while (next_permutation(flag.begin(), flag.end()));

		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[i].size(); j++) {
				cout << ans[i][j] << ' ';
			}
			cout << '\n';
		}

		cout << '\n';
		flag.clear();
		data.clear();
	}
	return 0;

}