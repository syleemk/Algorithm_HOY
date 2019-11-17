#include <cstdio>

#define itemNum 4

int max = -1;
const int maxW = 10;

class Item {
public:
	Item(int weight, int value) : weight(weight), value(value) {}

	int weight;
	int value;
};

Item arr[itemNum] = { Item(7,42), Item(3,12), Item(4,40), Item(5,25) };

void knapsack(int currentN, int currentW, int currentV) {
	if(currentW <= maxW)
		max = max > currentV ? max : currentV;

	for (int i = currentN+1; i < itemNum; i++) {
		if (currentW + arr[i].weight <= maxW) {
			knapsack(i, currentW + arr[i].weight, currentV + arr[i].value);
		}
	}

	return;
}

int main() {

	for (int i = 0; i < itemNum; i++) {
		knapsack(i, arr[i].weight, arr[i].value);
	}

	printf("%d\n", max);

}