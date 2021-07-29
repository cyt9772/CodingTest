#include<iostream>

#include<stdio.h>
#include<math.h>

using namespace std;
int d1699[100001];

int P1699() {
	int n;
	int cnt=0;

	cin >> n;
	//d[n]의 최소값은 d[n-i2]의 최소값 +1

	//초기화
	d1699[0] = 0;
	d1699[1] = 1;
	d1699[2] = 2;
	d1699[3] = 3;

	

	for (int i = 4; i <= n; i++) {
		int j = (int)sqrt(i);
		int temp = 316;

		while (j > 0) {
			temp=min(d1699[i - j * j] + 1, temp);
			j--;
		}
		d1699[i] = temp;
	}


	
	cout << d1699[n] << endl;

	return 0;
}