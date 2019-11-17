#include <cstdio>
#include <cstdlib>
#include <ctime>

int arr[500];

int main()
{
	clock_t start = clock(); // 시작 시간 

	for (int i = 0; i < 500; i++) {
		arr[i] = rand() % 1000001;
	}	
	
	int index;

	for (int i = 0; i < 500 - 1; i++) {
		int max = arr[i];
		index = i;
		for (int j = i + 1; j < 500; j++) {
			if (max < arr[j]) {
				max = arr[j];
				index = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}

	printf("%d\n", arr[4]);


	clock_t end = clock(); // 코드가 끝난 시간 

						   // 걸린 시간 출력
						   // 단위 : 초(second)
						   // CLOCKS_PER_SEC로 나눠줘야 초단위로 출력
	printf("\nTime : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
