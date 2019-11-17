#include <stdio.h>


int main() {
	char op;
	int res;
	int x=0, y=0;
	int range;

	printf("연산자를 입력하세요( +, -, x, %% ) : ");
	scanf("%c", &op);

	printf( "숫자를 입력하세요 : ");
	scanf("%d", &res);

	switch (op) {
	case '+':
		for (x = 1; x < res; x++) {
			y = res - x;
			printf("( %d, %d ) \n", x, y);
		}
		break;
	case '-':
	re_m:
		printf( "숫자의 범위를 설정해주세요 : ");
		scanf("%d", &range);
		if (range <= res) {
			printf("범위를 결과값보다 큰 수로 입력해주세요!");
			goto re_m;
		}
		for (x = range; x > res; x--) {
			y = x - res;
			printf("( %d, %d ) \n", x, y);
		}
		break;
	case 'x':
		for (x = 1; x <= res; x++) {
			y = res / x;
			if (res%x == 0) printf("( %d, %d ) \n", x, y);
		}
		break;
	case '%':
	re_d:
		printf("숫자의 범위를 설정해주세요 : ");
		scanf("%d", &range);
		if (range <= res) {
			printf("범위를 결과값보다 큰 수로 입력해주세요!");
			goto re_d;
		}
		for (y = 1; x < range; y++) {
			x = res * y;
			printf("( %d, %d ) \n", x, y);
		}

		break;
	}

}
