#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>




void PrintMergeArray(int arr1[], int size1, int arr2[], int size2);


void PrintMergeArray(int arr1[], int size1, int arr2[], int size2) {
	
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j< size2; j++) {
			if (arr1[i] == arr2[j]) {
				printf("%d ", arr1[i]);
				break;
			}
		}

	}

}

int main() {
	
	int arr1[] = { 1, 3, 4, 5, 10, 12 };
	int arr2[] = { 1, 2, 4, 8, 10 };


	PrintMergeArray(arr1, sizeof(arr1)/sizeof(int), arr2, sizeof(arr2) / sizeof(int));

	return 0;
}