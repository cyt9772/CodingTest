#include<iostream>
#include<stdio.h>

using namespace std;

int a11053[1001];
int d11053[1001];

int P11053() {
	int n;
	cin >> n; //�Է� ������ ����

	for (int i = 1; i <= n; i++)
		cin >> a11053[i];

	for (int i = 1; i <= n; i++) {
		d11053[i] = 1;
		for (int j = i; j >= 1; j--) {
			int cnt = 1;
			if (a11053[i] > a11053[j]) {  //ū ��� d���� update
				cnt += d11053[j];
				if (cnt > d11053[i])
					d11053[i] = cnt; //���� ����� ������ ū ��츸 ���� update
			}
		}
	}

	int maxVal = 0;
	for (int i = 1; i <= n; i++) {
		if (d11053[i] > maxVal)
			maxVal = d11053[i];
	}
	cout << maxVal << endl;

	return 0;
}