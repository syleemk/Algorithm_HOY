#include <stdio.h>

// 50000 10000 5000 1000 500 100 10�� ����

int arr_changeType[8] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };
int arr_changeCount[8] = { 0, };

void input(int& price, int& money, int& changes);
void CountChanges(int changes);
void printChanges();

int main() {
	int price, money, changes;

	input(price, money, changes);
	CountChanges(changes);
	printChanges();
}

void CountChanges(int changes) {
	for (int i = 0; i < 8; ) {
		if (changes >= arr_changeType[i]) {
			changes -= arr_changeType[i];
			arr_changeCount[i]++;

			if (changes == 0) break;
		}
		else i++;
	}
}

void printChanges() {
	for (int i = 0; i < 8; i++) {
		printf("%d�� : %d��\n", arr_changeType[i], arr_changeCount[i]);
	}
}

void input(int& price, int& money, int& changes) {
	printf("���� ������ �Է����ּ��� : ");
	scanf("%d", &price);
	while (1) {
		printf("���� ���� �׼��� �Է����ּ��� : ");
		scanf("%d", &money);

		if (price == money) printf("�Ž������� �����ϴ�.\n");
		else if (price > money) printf("���� �� �����մϴ�.\n");
		else {
			changes = money - price;
			printf("�Ž��� �� �׼� : %d\n", changes);
			break;
		}
	}
}