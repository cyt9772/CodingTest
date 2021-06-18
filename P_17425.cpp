
#include <stdio.h>

#define MAX 1000001

//��ü f(x), g(x) ���� �Ҵ�
long long  sumDiv[MAX];  //f(x)
long long  partialSum[MAX]; //g(x)


void P_17425() {
    int N, i,j;
    
    //��ü �޸� �̸� �Ҵ�
    for (i = 2; i < MAX; i++) {
        for (j = 1; i * j < MAX; j++) {
            sumDiv[i * j] += i;
        }
    }

    //�κ��� �̸� ���ϱ�
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