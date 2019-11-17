#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int f = 1;

	for (int m = 1; m <= n; m++) {
		f *= m;
	}

	printf("%d\n", f);
}