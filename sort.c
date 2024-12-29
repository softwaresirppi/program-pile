// Bubble, Insertion, Selection
// QuickSort, MergeSort
#include <stdio.h>

typedef unsigned int index;
#define SWAP(x, y) if(x != y) { x ^= y; y ^= x; x ^= y; }

void bubble_sort(int n, int* items) {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n - 1 - i; j++){
			if(items[j + 1] < items[j])
				SWAP(items[j], items[j + 1]);
		}
}

void selection_sort(int n, int* items) {
	for(int i = 0; i < n; i++) {
		int min_idx = i;
		int min = items[i];
		for(int j = i; j < n; j++){
			if(items[j] < min) {
				min = items[j];
				min_idx = j;
			}
		}
		SWAP(items[i], items[min_idx]);
	}
}

void insertion_sort(int n, int* items) {
	for(int i = 1; i < n; i++) {
		int j = i;
		while(j - 1 >= 0 && items[j] < items[j - 1]) {
			SWAP(items[j], items[j - 1]);
			j--;
		}
	}
}

// Lomuto partitioning scheme
// `pivot_idx` is expected to be within [0 to n)
int partition(int n, int* items, int pivot_idx) {
	int writer = 0;
	for(int i = 0; i < n; i++)
		if(items[i] < items[pivot_idx]) {
			SWAP(items[writer], items[i]);
			writer++;
		}
	SWAP(items[writer], items[pivot_idx]);
	return writer;
}

void quick_sort(int n, int* items) {
	if(n <= 1) return;
	int ridge = partition(n, items, n - 1);
	quick_sort(ridge, items);
	quick_sort(n - ridge - 1, items + ridge + 1);
}

// `output` is expected to have an + bn elements allocated.
void merge(int an, int* a, int bn, int* b, int* output) {
	int i = 0, j = 0, writer = 0;
	while(i < an || j < bn) {
		while(i < an && (j >= bn || a[i] < b[j]))
			output[writer++] = a[i++];
		while(j < bn && (i >= an || b[j] <= a[i]))
			output[writer++] = b[j++];
	}
}

// `buffer` is expected to have n elements allocated.
void merge_sort(int n, int* items, int* buffer) {
	if(n == 1) return;
	merge_sort(n/2, items, buffer);
	merge_sort( n - n/2, items + n/2, buffer);
	merge(n/2, items, n - n/2, items + n/2, buffer);
	for(int i = 0; i < n; i++) items[i] = buffer[i];
}

// Returns the kth element of the array as if it was sorted.
int kth_smallest(int n, int* items, int k) {
	if(!(0 <= k && k < n)) return -1;
	int ridge = partition(n, items, n - 1);
	if(k < ridge){
		return kth_smallest(ridge, items, k);
	} else if(ridge < k) {
		return kth_smallest(n - ridge - 1, items + ridge + 1, k - ridge - 1);
	} else {
		return items[ridge];
	}
}

int main() {
	int x[] = {4,64,16,2,32,8};
	printf("%d\n", kth_smallest(6, x, 1));
}
