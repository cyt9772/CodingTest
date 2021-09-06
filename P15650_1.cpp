#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

int inputData[8];
int printData[8];
bool checked[8];

void go(int index, int start, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", printData[i]);
		printf("\n");
		return;
	}

	for (int i = start; i <=n; i++) {
		if (checked[i]) continue;
		checked[i] = true; printData[index]=inputData[i-1];
		go(index + 1, i+1, n, m);
		checked[i] = false;
	}
};
010
int main() {
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		inputData[i]=i+1;
	}



	go(0, 1, n, m);
	return 0;
}