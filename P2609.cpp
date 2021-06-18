#include <stdio.h>
int gcd(int m, int n);


int P2609() {
	int a, b,g,l;
	scanf("%d %d", &a, &b);

	g = gcd(a, b);
	l = g * (a / g) * (b / g);
	printf("%d\n", g);
	printf("%d\n", l);

	return 0;
}

int gcd(int m, int n) {
	if (n == 0)
		return m;
	else
		return gcd(n, m % n);
}