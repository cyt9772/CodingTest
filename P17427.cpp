#include <stdio.h>


void P_17427() {
    int N;
    int i = 1;
    long long ans = 0;

    scanf("%d", &N);

    for (; i < (N + 1); i++) {
        ans += (N / i) * i;
    }
    printf("%lld", ans);
}
