#include <stdio.h>

int main() {
	int x, y, z;
	int m;

	scanf("%d", &m);
	
	for (int n = m; n <= 300; n += m) {
		for (x = 1; x <= 100; x++) {
			for (y = 1; y <= 100; y++) {
				z = n - x - y;
				if(z <= 100 && z >=1) printf("( %d, %d, %d )\n", x, y, z);
			}
		}
	}
}