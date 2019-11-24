#include <cstdio>

#define itemNum 5

int max = -1;
const int maxW = 55;

class Item {
public:
	Item(int weight, int value) : weight(weight), value(value) {}

	int weight;
	int value;
};

Item arr[itemNum] = { Item(20,25), Item(15,30), Item(30,45), Item(20,30), Item(15,35) };

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