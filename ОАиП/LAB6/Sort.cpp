#include "Sort.h"
#include "Array.h"
#include <string>

void MergeSortFunc(int*& arr, int start, int mid, int end) {
	int left = start;
	int right = mid + 1;
	int length = end - start + 1;
	int* tempArr = allocate(length);
	int index = 0;
	while ((left <= mid) && (right <= end)) {
		if (arr[left] < arr[right]) {
			tempArr[index] = arr[left];
			left++;
		}
		else {
			tempArr[index] = arr[right];
			right++;
		}
		index++;
	}
	for (int i = left; i <= mid; i++) {
		tempArr[index] = arr[i];
		index++;
	}
	for (int i = right; i <= end; i++) {
		tempArr[index] = arr[i];
		index++;
	}

	for (int i = 0; i < length; i++) {
		arr[start + i] = tempArr[i];
	}
	free(tempArr);
}

void MergeSort(int*& arr, int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		MergeSort(arr, start, middle);
		MergeSort(arr, middle + 1, end);
		MergeSortFunc(arr, start, middle, end);
	}
}

void BubbleSort(int*& arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = (size - 1); j > i; j--) {
			if (arr[j - 1] > arr[j]) {
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void SortMatrixByHoaraMethod(int**& arr, int width, int height) {
	int* sort = allocate(height);
	int* sumArr = allocate(height);
	for (int i = 0; i < height; i++) {
		int sum = 0;
		for (int j = 0; j < width; j++)
		{
			if (j % 2 == 0) continue;
			sum += arr[j][i];
		}
		sumArr[i] = sum;
	}
	for (int i = 0; i < height; i++) {
		sort[i] = i;
	}
	HoaraSort(sumArr, sort, 0, height - 1);
	MergeSortAndArrayHoara(arr, sort, width, height);
	free(sort);
}

void HoaraSort(int*& arr, int*& sort, int start, int end) {
	int i = start;
	int j = end;
	int tmp;
	int sort_tmp;
	int x = arr[(start + end) / 2];

	do {
		while (arr[i] > x)
			i++;
		while (arr[j] < x)
			j--;
		if (i <= j) {
			if (i < j) {
				
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;

				sort_tmp = sort[i];
				sort[i] = sort[j];
				sort[j] = sort_tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < end)
		HoaraSort(arr, sort, i, end);
	if (start < j)
		HoaraSort(arr, sort, start, j);
}

void MergeSortAndArrayHoara(int**& arr, int* sort, int w, int h) {
	int** new_matrix = allocate_sec(w, h);
	for (int sort_pos = 0; sort_pos < h; sort_pos++) {
		for (int j = 0; j < w; j++)
		{
			new_matrix[j][sort_pos] = arr[j][sort[sort_pos]];
		}
	}
	free(arr);
	arr = new_matrix;
}

void Reverse(int*& arr, int w) {
	for (int i = 0; i < w / 2; i++) {
		int temp = arr[i];
		arr[i] = arr[w - i - 1];
		arr[w - i - 1] = temp;
	}
}