#include<iostream>
#include<vector>

#include<stdio.h>

using namespace std;

int a14002[1001];
int d14002[1001];
int v14002[1001];

void go14002(int idx, int maxVal, int cnt, vector<int> buf) {
	if (cnt == maxVal) {
		for (int i = buf.size()-1; i >=0; i--) {
			cout << buf[i] << ' ';
		}
		return;
	}
	buf.push_back(a14002[idx]);
	go14002(v14002[idx], maxVal, cnt+1, buf);

};
int P14002() {
	int n;
	cin >> n; //�Է� ������ ����

	for (int i = 1; i <= n; i++)
		cin >> a14002[i];

	for (int i = 1; i <= n; i++) {
		d14002[i] = 1;
		for (int j = i; j >= 1; j--) {
			int cnt = 1;
			if (a14002[i] > a14002[j]) {  //ū ��� d���� update
				cnt += d14002[j];
				if (cnt > d14002[i]) {
					d14002[i] = cnt; //���� ����� ������ ū ��츸 ���� update
					v14002[i] = j;  //���߿� ����� index�� ã�� ����� ���� tracking
				}
			}
		}
	}

	int maxVal = 0;
	int index = 0;
	for (int i = 1; i <= n; i++) {
		if (d14002[i] > maxVal) {
			maxVal = d14002[i];
			index = i;
		}
	}
	cout << maxVal << endl;
	vector<int> buf;
	go14002(index, maxVal, 0, buf);

	return 0;
}