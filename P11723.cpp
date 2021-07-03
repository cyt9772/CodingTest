#include<iostream>
#include<vector>
#include<algorithm>

#include<stdio.h>
#include<string.h>

using namespace std;

int P11723() {
	int n = 0; //cmd ¼ö
	int S = 0;
	int allS = (1 << 21) - 1;
	
	cin >> n;

	for(int k=0;k<n;k++){
		char cmdStr[15];

		int param = 0;
		scanf("%s", cmdStr);
//		cin >> cmdStr;

		if (cmdStr[2] == 'd') {
			scanf("%d", &param);
			S = (S | (1 << param));

		}
		else if (cmdStr[0]== 'r') {
			scanf("%d", &param);
			S = S & ~(1 << param);

 		}
		else if (cmdStr[0]== 'c') {
			int a;
			scanf("%d", &param);
			a = S & (1 << param);
			a = a >> param;
			printf("%d\n", a);
		}
		else if (cmdStr[0]== 't') {
			scanf("%d", &param);
			S = S ^ (1 << param);

		}
		else if (cmdStr[0]== 'a') {
			S = allS;
		}
		else if (cmdStr[0] == 'e') {
			S = 0;
		}

	
	}
	return 0;
}