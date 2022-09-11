#include <stdio.h>

#define xor_swap(a, b) (a ^= b, b ^= a, a ^= b)

void partition(size_t n, int* arr, int* pivot) {
	xor_swap(*pivot, arr[n - 1]);
	int* unfitLeft = NULL, * unfitRight = NULL;
	do {
		for (size_t i = 0; i < n; i++)
			if (arr[i] > arr[n - 1]) {
				unfitLeft = arr + i;
				break;
			}
		for (int i = n - 1; i >= 0; i--)
			if (arr[i] < arr[n - 1]) {
				unfitRight = arr + i;
				break;
			}
    if(unfitLeft && unfitRight)
		xor_swap(*unfitLeft, *unfitRight);
	} while (unfitRight - unfitLeft > 0);
	xor_swap(*pivot, arr[n - 1]);
}

void pivotSort(size_t n, int* arr) {
	if (n == 0) return;
	partition(n, arr, arr + n - 1);
	pivotSort(n / 2, arr);
	pivotSort(n / 2, arr + n / 2);
}

int main() {
	int x[] = { 5,4,3,2,1 };
	pivotSort(5, x);
	for (size_t i = 0; i < 5; i++) printf("%d, ", x[i]);
}
