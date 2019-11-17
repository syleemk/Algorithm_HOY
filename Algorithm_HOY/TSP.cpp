// TSP
// 그래프는 인접행렬로 구현

#include <cstdio>

#define infin 1000000000;

const int city = 4;
const int dist[4][4] = {
	{0,2,5,7},
	{2,0,8,3},
	{5,8,0,1},
	{7,3,1,0}
};

const int visited_all = (1 << city) - 1;

int min = infin;

void find_dist(int start, int last, int visited, int tmp_dist) {
	if (visited == visited_all) {// 모든 도시 다 방문한 경우
		if (dist[last][start] != 0) { // 마지막 방문 도시와 출발도시가 연결 되어있는지 확인
			tmp_dist += dist[last][start];
			min = min < tmp_dist ? min : tmp_dist;
			return;
		}
	}
	
	for (int i = 0; i < city; i++) {
		if ((visited & (1 << i)) == 0 && dist[last][i] != 0) {
			find_dist(start, i, visited | (1 << i), tmp_dist + dist[last][i]);
		}
	}

	return;
}

int main() {
	for (int i = 0; i < city; i++) {
		find_dist(i, i, 1 << i, 0);
	}

	printf("%d\n", min);
}

