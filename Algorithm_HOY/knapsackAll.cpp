#include <cstdio>
#include <cstdlib>

/*

	for (int i = 0; i < itemNum; i++) {
		printf("%d %d %d\n", itemList[i]->idx, itemList[i]->weight, itemList[i]->value);
	}

*/

#define MAXLEN 100

struct Item {
	int idx;
	int weight;
	int value;
};

int itemNum = 0;
Item* itemList[MAXLEN]; 

int maxW;

void inputItem(int weight, int value);
void sortbyValue(int start, int end);
void sortbyValuePerWeight(int start, int end);
void sortbyWeight(int start, int end);
void bruteForce(int currentN, int currentV, int currentW, int& maxV);
void greedy01();
void greedy01_perV();
void greedyFractional();
void ifVpWisSame();

int main() {
	printf("How many items? : ");
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++) { // item들을 입력받는다
		int weight, value;
		printf("item %d: ", i + 1);
		scanf("%d %d", &weight, &value);
		inputItem(weight, value);
	}

	printf("max weight? : ");
	scanf("%d", &maxW);

	puts("=====================================");
	puts("** Brute Force **");
	int maxV = -1;
	for (int i = 0; i < itemNum; i++) {
		bruteForce(i, itemList[i]->value, itemList[i]->weight, maxV);
	}
	printf("max value : %d\n", maxV);
	puts("-------------------------------------");
	greedy01();
	puts("-------------------------------------");
	greedy01_perV();
	puts("-------------------------------------");
	greedyFractional();
}

void greedyFractional() {
	sortbyValuePerWeight(0, itemNum - 1); // 무게당 가치 높은 순으로 정렬
	ifVpWisSame(); // 무게당 가치 같으면 무게 작은 것이 먼저오도록 다시 정렬

	for (int i = 0; i < itemNum; i++) {
		printf("%d %d %d\n", itemList[i]->idx, itemList[i]->weight, itemList[i]->value);
	}

	float currentV = 0;
	int currentW = 0;

	puts("** Greedy - fractional **");

	printf("item set : ( ");
	for (int i = 0; i < itemNum; i++) {
		if (currentW + itemList[i]->weight <= maxW) {
			printf("%d ", itemList[i]->idx);
			currentW += itemList[i]->weight;
			currentV += itemList[i]->value;
		}
		else {
			int leftW = maxW - currentW;
			if (leftW > 0) {
				printf("( fractional : %d)", itemList[i]->idx);
				currentV += leftW * ((float)itemList[i]->value / itemList[i]->weight);
			}
			break;
		}
	}
	printf(")\n");

	printf("max value : %.1f\n", currentV);
}

void greedy01_perV() {
	sortbyValuePerWeight(0, itemNum - 1); // 무게당 가치 높은 순으로 정렬
	ifVpWisSame();

	for (int i = 0; i < itemNum; i++) {
		printf("%d %d %d\n", itemList[i]->idx, itemList[i]->weight, itemList[i]->value);
	}


	int currentV = 0;
	int currentW = 0;

	puts("** Greedy - 0/1 무게당 가치**");

	printf("item set : ( ");
	for (int i = 0; i < itemNum; i++) {
		if (currentW + itemList[i]->weight <= maxW) {
			printf("%d ", itemList[i]->idx);
			currentW += itemList[i]->weight;
			currentV += itemList[i]->value;
		}
		else break;
	}
	printf(")\n");

	printf("max value : %d\n", currentV);
}

void greedy01() {
	sortbyValue(0, itemNum - 1); // Value큰 순으로 정렬

	int currentV = 0;
	int currentW = 0;

	puts("** Greedy - 0/1 **");	

	printf("item set : ( ");
	for (int i = 0; i < itemNum; i++) {
		if (currentW + itemList[i]->weight <= maxW) {
			printf("%d ", itemList[i]->idx);
			currentW += itemList[i]->weight;
			currentV += itemList[i]->value;
		}
		else break;
	}
	printf(")\n");

	printf("max value : %d\n", currentV);
}

void bruteForce(int currentN, int currentV, int currentW, int& maxV) {
	maxV = currentV > maxV ? currentV : maxV;

	for (int i = currentN + 1; i < itemNum; i++) {
		if ((currentW + itemList[i]->weight) <= maxW) {
			bruteForce(i, currentV + itemList[i]->value, currentW + itemList[i]->weight, maxV);
		}
	}

	return;
}

void sortbyWeight(int start, int end) {// 무게가 작은 순으로 정렬
	if (start >= end) return;

	int key = start;
	int i = start + 1;
	int j = end;
	
	while (i <=  j) {
		while (i <= end && itemList[i]->weight <= itemList[key]->weight) i++;
		while (j > start && itemList[j]->weight >= itemList[key]->weight) j--;

		if (i > j) {
			Item* temp = itemList[key];
			itemList[key] = itemList[j];
			itemList[j] = temp;
		}
		else {
			Item* temp = itemList[i];
			itemList[i] = itemList[j];
			itemList[j] = temp;
		}
	}
	sortbyWeight(start, j - 1);
	sortbyWeight(j + 1, end);
}

void sortbyValue(int start, int end) { // item들을 가치순으로 내림차순 정렬한다. 퀵소트 이용
	if (start >= end) return;

	int key = start;
	int i = start + 1;
	int j = end;

	while (i <= j) {
		while (i <= end && itemList[i]->value >= itemList[key]->value ) i++;
		while (j > start && itemList[j]->value <= itemList[key]->value) j--;

		if (i > j) { 
			Item* temp = itemList[key];
			itemList[key] = itemList[j];
			itemList[j] = temp;
		}
		else { 
			Item* temp = itemList[i];
			itemList[i] = itemList[j];
			itemList[j] = temp;
		}
	}
	sortbyValue(start, j-1);
	sortbyValue(j+1, end);
}

void sortbyValuePerWeight(int start, int end) {
	if (start >= end) return;

	int key = start;
	int i = start + 1;
	int j = end;

	while (i <= j) {
		while (i <= end && ((float)(itemList[i]->value) / (itemList[i]->weight)) >= ((float)(itemList[key]->value) / (itemList[key]->weight))) {
			i++;
		}
		while (j > start && ((float)(itemList[j]->value) / (itemList[j]->weight)) <= ((float)(itemList[key]->value) / (itemList[key]->weight))) j--;

		if (j < i) {
			Item* temp = itemList[j];
			itemList[j] = itemList[key];
			itemList[key] = temp;
		}
		else {
			Item* temp = itemList[j];
			itemList[j] = itemList[i];
			itemList[i] = temp;
		}
	}
	sortbyValuePerWeight(start, j - 1);
	sortbyValuePerWeight(j + 1, end);
}

void inputItem(int weight, int value) {
	Item* newItem = (Item*)malloc(sizeof(Item));
	if (newItem == NULL) {
		printf("메모리 공간 부족\n");
		exit(1);
	}
	newItem->weight = weight;
	newItem->value = value;
	newItem->idx = itemNum + 1;

	itemList[itemNum++] = newItem;
}

void ifVpWisSame() {
	for (int i = 0; i < itemNum-1; i++) {
		if (((float)(itemList[i]->value) / (itemList[i]->weight)) == ((float)(itemList[i + 1]->value) / (itemList[i + 1]->weight))) {// value per weight가 같은 경우, 무게가 더 작은 것을 앞으로 보냄
			if (itemList[i]->weight > itemList[i + 1]->weight) {
				Item* temp = itemList[i];
				itemList[i] = itemList[i + 1];
				itemList[i + 1] = temp;
			}
		}
	}
}