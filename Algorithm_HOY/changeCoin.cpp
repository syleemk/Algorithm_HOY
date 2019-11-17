#include <stdio.h>

// 50000 10000 5000 1000 500 100 10원 단위

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
		printf("%d원 : %d개\n", arr_changeType[i], arr_changeCount[i]);
	}
}

void input(int& price, int& money, int& changes) {
	printf("물건 가격을 입력해주세요 : ");
	scanf("%d", &price);
	while (1) {
		printf("받은 돈의 액수를 입력해주세요 : ");
		scanf("%d", &money);

		if (price == money) printf("거스름돈이 없습니다.\n");
		else if (price > money) printf("돈을 더 내야합니다.\n");
		else {
			changes = money - price;
			printf("거스름 돈 액수 : %d\n", changes);
			break;
		}
	}
}