#include<iostream>
#include<vector>

#include<stdio.h>

using namespace std;

int a11055[1001];
int s11055[1001];

int P11055() {
	int n;
	cin >> n; //입력 데이터 개수

	for (int i = 1; i <= n; i++)
		cin >> a11055[i];

	for (int i = 1; i <= n; i++) {
		s11055[i] = a11055[i];
		for (int j = 1; j <= i; j++) {
			if (a11055[j] < a11055[i] && s11055[i]<s11055[j]+a11055[i]) {
				s11055[i] = s11055[j] + a11055[i];
			}
		}
	}
	int maxVal = 0;
	for (int i = 1; i <= n; i++) {
		if (s11055[i] > maxVal)
			maxVal = s11055[i];
	}
	cout << maxVal << endl;

	return 0;
}