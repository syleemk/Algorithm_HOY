#include <stdio.h>

int main() {
	int cnt = 0;
	float n = 0.03;

	int value;
	scanf("%d", &value);
	printf("%d", value);

	int charge;
	scanf("%d", &charge);
	printf("%d", charge);

	int discount;
	scanf("%d", &discount);
	printf("%d", discount);

	if (charge >= value) {
		if (charge * n > discount) {
			charge = charge - charge * n;
			cnt++;
		}
		else {
			charge = charge - discount;
			cnt++;
		}

		if (cnt == 3) n *= 2;

	}
}