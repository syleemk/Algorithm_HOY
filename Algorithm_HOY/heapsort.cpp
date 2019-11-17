#include <cstdio>
#include <cstdlib>

#define MAX_SIZE 100

struct Heap {
	int size = 0;
	int heap[MAX_SIZE];

};

void insertHeap(Heap * h, int element);
int deleteHeap(Heap * h);
void HeapSort(int * arr, int arrSize);

int main() {
	int num;

	printf("입력받을 숫자의 개수를 입력하세요 : ");
	scanf("%d", &num);

	int * arr = new int[num];

	printf("%d개의 숫자를 입력하세요 : ", num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	HeapSort(arr, num);

	printf("정렬결과 : ");
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
}

void insertHeap(Heap * h, int element) {
	int i = ++(h->size);

	while ((i != 1) && (element < h->heap[i / 2])) { // 최소 힙 구성
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}

	h->heap[i] = element;
}

int deleteHeap(Heap * h) {
	int parent = 1;
	int child = 2;

	int out = h->heap[parent];
	int last = h->heap[(h->size)--];

	while (child <= h->size) {
		if ((child <= h->size) && (h->heap[child] > h->heap[child + 1])) { // 더 작은 자식 고른다
			child++;
		}

		if (last <= h->heap[child]) break;  // 자식이 더 크면 탈출
		
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;			
	}
	h->heap[parent] = last;

	return out;
}

void HeapSort(int * arr, int arrSize) {
	Heap h;

	for (int i = 0; i < arrSize; i++) {
		insertHeap(&h, arr[i]);
	}


	for (int i = 0; i < arrSize; i++) {
		arr[i] = deleteHeap(&h);
	}
}
