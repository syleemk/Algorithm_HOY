#include <stdio.h>


int main() {
	char op;
	int res;
	int x=0, y=0;
	int range;

	printf("�����ڸ� �Է��ϼ���( +, -, x, %% ) : ");
	scanf("%c", &op);

	printf( "���ڸ� �Է��ϼ��� : ");
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
		printf( "������ ������ �������ּ��� : ");
		scanf("%d", &range);
		if (range <= res) {
			printf("������ ��������� ū ���� �Է����ּ���!");
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
		printf("������ ������ �������ּ��� : ");
		scanf("%d", &range);
		if (range <= res) {
			printf("������ ��������� ū ���� �Է����ּ���!");
			goto re_d;
		}
		for (y = 1; x < range; y++) {
			x = res * y;
			printf("( %d, %d ) \n", x, y);
		}

		break;
	}

}
