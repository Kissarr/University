#pragma warning(disable: 4996)
#define MaxStrLength 2048
#include <stdio.h>
#include <windows.h>
void sort(int arr[], int length) {
	int i, swap = 0;
	int step = length / 2;
	while (step > 0) {
		for (i = 0; step + i < length; i++) {
			if (arr[step + i] < arr[i]) {
				swap = 1;
				int temp = arr[i];
				arr[i] = arr[step + i];
				arr[step + i] = temp;
			}
		}

		for (i = 0; i < length; i++) {
			printf("%d ", arr[i]);
		}
		printf("шаг = %d\n", step);

		if (swap == 0) {
			step /= 2;
		}
		swap = 0;
	}
}
int main(int argc, char* argv[]) {
	SetConsoleOutputCP(1251);
	int arr[MaxStrLength] = { 0 };
	printf("Введите размер массива, а затем заполните его ");
	int n;
	scanf("%d", &n);
	int i, temp;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, n); // 5 4 3 2 1 10 9 8 7 6 // 11 5 4 3 2 1 10 9 8 7 6 // 10 4 5 11 3 9 8 7 6 2 1
	/*for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}*/
	return 0;
}