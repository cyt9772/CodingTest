#include<iostream>
#include<stdio.h>

using namespace std;

int A11054[1001];
int L11054[1001];

int lenBitonic=0;

int P11054(){
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> A11054[i];

	for (int k = 1; k <= n; k++) {
		//K값을 기준으로 w 증가수열과 감소수열의 길이 구함
		int lenInc = 0;
		int lenDec = 0;

		//1.증가수열
		for (int i = 1; i <= k; i++) {
			L11054[i] = 1;
			for (int j = 1; j <= i; j++) {
				if (A11054[j] < A11054[i] && L11054[i] < L11054[j] + 1) {
					L11054[i] = L11054[j] + 1;
				}
			}
		}
		
		//max길이 저장
		for (int i = 1; i <= k; i++) {
			if (L11054[i] > lenInc)
				lenInc = L11054[i];
		}

		//2.감소수열
		for (int i = k; i <= n; i++) {
			L11054[i] = 1;
			for (int j = k; j <= i; j++) {
				if (A11054[j] > A11054[i] && L11054[i] < L11054[j] + 1) {
					L11054[i] = L11054[j] + 1;
				}
			}
		}

		//max길이 저장
		for (int i = k; i <= n; i++) {
			if (L11054[i] > lenDec)
				lenDec = L11054[i];
		}

		if ((lenInc + lenDec-1) > lenBitonic)
			lenBitonic = lenInc + lenDec-1;  //k가 중복이므로 1감소
	}
	cout << lenBitonic << endl;

	return 0;
}