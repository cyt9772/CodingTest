
#include <stdio.h>

#define MAX 1000001

//전체 f(x), g(x) 공간 할당
long long  sumDiv[MAX];  //f(x)
long long  partialSum[MAX]; //g(x)


void P_17425() {
    int N, i,j;
    
    //전체 메모리 미리 할당
    for (i = 2; i < MAX; i++) {
        for (j = 1; i * j < MAX; j++) {
            sumDiv[i * j] += i;
        }
    }

    //부분합 미리 구하기
    for (i = 1; i < MAX; i++) {
        partialSum[i] = partialSum[i - 1] + sumDiv[i]+1;
    }

    scanf("%d", &N);

    while (N--) {
        int m = 0;
        scanf("%d", &m);
        printf("%lld\n", partialSum[m]);

    }
}