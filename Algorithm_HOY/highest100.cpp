// 상위 100개 수 출력	

#include <iostream>

using namespace std;

void sort(int * arr, int size) {
	int index;

	for (int i = 0; i < size - 1; i++) {
		int max = arr[i];
		index = i;
		for (int j = i + 1; j < size ; j++) {
			if (max < arr[j]) {
				max = arr[j];
				index = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
}

int main() {
	int size;
	cin >> size;

	int * arr = new int[size];

	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	sort(arr, size);

	for (int i = 0; i < 100; i++) {
		cout << arr[i] << ' ';
	}

	delete[] arr;
}