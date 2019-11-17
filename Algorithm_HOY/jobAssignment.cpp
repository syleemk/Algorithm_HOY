#include <cstdio>

#define pNum 4
#define jNum 4
#define infin 1000000000

int min = infin;
const int assigned_all = (1 << jNum) - 1;

int cost[pNum][jNum] = {
	{9,2,7,8},
	{6,4,3,7},
	{5,8,1,8},
	{7,6,9,4}
};

void find_cost(int person, int assigned, int t_cost) {
	if (assigned == assigned_all) { // 모든 작업이 다 할당 된 경우
		min = min < t_cost ? min : t_cost;
		return;
	}

	for (int i = 0; i < jNum; i++) {
		if ((assigned & (1 << i)) == 0 && person < pNum) { // i번째 작업이 아직 할당되지 않았고, 
			find_cost(person + 1, assigned | (1 << i), t_cost + cost[person + 1][i]);
		}
	}

	return;
}

int main() {
	for (int i = 0; i < jNum; i++) {
		find_cost(0, 1 << i, cost[0][i]);
	}
	printf("%d\n", min);
}