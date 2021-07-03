#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>

using namespace std;

extern void Combination(int* arr, bool* visited, int depth, int n, int r);

int data1182[20] = { 0, };
bool flag1182[20] = { false, };
int ans1182;
int buf1182[20];
vector<vector<int>> temp1182;

void go1182(int index, int start, int n, int s) {
	if (index > 0) {
		int subhap = 0;
		vector<int> temp;
		for (int i = 0; i <= index - 1; i++) { //index-1까지 합을 계산
			subhap += buf1182[i];
		}
		if (subhap == s) {//hap이 match가 되면 cnt 1 증가
/*			for (int i = 0; i <= index - 1; i++) {
				temp.push_back(buf1182[i]);
			}
			sort(temp.begin(), temp.end());

			bool ok = true;
			for (int i = 0; i < temp1182.size(); i++) {
				if (temp == temp1182[i]) {
					ok = false;
					break;
				}
			}
			if (ok) { */
				ans1182++;
//				temp1182.push_back(temp);
//			}
		}
	}

	if (index == n) {
		return;
	}

	for (int i = start; i < n; i++) {
		if (flag1182[i]) continue;
		flag1182[i] = true;
		buf1182[index] = data1182[i];
		go1182(index + 1, start+1, n, s);
		flag1182[i] = false;
	}
};

int P1182(){
	int N, S;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> data1182[i];
	}

//	go1182(0, 0, N, S);
//	Combination(data1182, flag1182, 0, 5, 2);
//	cout << ans1182 << endl;
	return 0;
}