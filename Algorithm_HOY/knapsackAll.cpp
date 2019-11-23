#include <cstdio>
#include <cstdlib>

#define MAXLEN 100

struct Item {
	int idx;
	int weight;
	int value;
};

int itemNum = 0;
Item* itemList[MAXLEN]; 

void inputItem(int weight, int value);
void sortbyValue(int start, int end);
void sortbyValuePerWeight(int start, int end);

int main() {

}

void sortbyValue(int start, int end) { // item들을 가치순으로 내림차순 정렬한다. 퀵소트 이용
	if (start >= end) return;

	int key = start;
	int i = start + 1;
	int j = end;

	while (i <= j) {
		while (itemList[i]->value <= itemList[key]->value && i <= end)  i++;
		while (itemList[j]->value >= itemList[key]->value && j > start) j--;

		if (i > j) { 
			Item* temp = itemList[key];
			itemList[key] = itemList[j];
			itemList[j] = temp;
		}
		else { 
			Item* temp = itemList[i];
			itemList[i] = itemList[j];
			itemList[j] = itemList[i];
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
		while (((float)(itemList[i]->value) / (itemList[i]->weight)) <= ((float(itemList[key]->value) / (itemList[key]->weight)) && i <= end)) i++;
		while (((float)(itemList[j]->value) / (itemList[j]->weight)) >= ((float(itemList[key]->value) / (itemList[key]->weight)) && j > start)) j--;

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