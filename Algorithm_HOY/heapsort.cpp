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

	printf("�Է¹��� ������ ������ �Է��ϼ��� : ");
	scanf("%d", &num);

	int * arr = new int[num];

	printf("%d���� ���ڸ� �Է��ϼ��� : ", num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	HeapSort(arr, num);

	printf("���İ�� : ");
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}
}

void insertHeap(Heap * h, int element) {
	int i = ++(h->size);

	while ((i != 1) && (element < h->heap[i / 2])) { // �ּ� �� ����
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
		if ((child <= h->size) && (h->heap[child] > h->heap[child + 1])) { // �� ���� �ڽ� ����
			child++;
		}

		if (last <= h->heap[child]) break;  // �ڽ��� �� ũ�� Ż��
		
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
