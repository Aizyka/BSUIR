#include "Sort.h"
#include "Array.h"
#include <string>

void MergeSortFunc(int*& arr, char**& sort, int start, int mid, int end) {
	int left = start;
	int right = mid + 1;
	int length = end - start + 1;
	int* tempArr = allocate(length);
	char** tempArrSort = (char**)calloc(length, sizeof(char*));
	int index = 0;
	while ((left <= mid) && (right <= end)) {
		if (arr[left] > arr[right]) {
			tempArr[index] = arr[left];
			tempArrSort[index] = sort[left];
			left++;
		}
		else {
			tempArr[index] = arr[right];
			tempArrSort[index] = sort[right];
			right++;
		}
		index++;
	}
	for (int i = left; i <= mid; i++) {
		tempArr[index] = arr[i];
		tempArrSort[index] = sort[i];
		index++;
	}
	for (int i = right; i <= end; i++) {
		tempArr[index] = arr[i];
		tempArrSort[index] = sort[i];
		index++;
	}

	for (int i = 0; i < length; i++) {
		arr[start + i] = tempArr[i];
		sort[start + i] = tempArrSort[i];
	}
	free(tempArr);
	free(tempArrSort);
}

void MergeSort(int*& arr, char**& sort, int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		MergeSort(arr, sort, start, middle);
		MergeSort(arr, sort, middle + 1, end);
		MergeSortFunc(arr, sort, start, middle, end);
	}
}