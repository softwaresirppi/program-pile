#include <stdio.h>

int linear_search(int n, int* items, int suspect) {
	for(unsigned int i = 0; i < n; i++) {
		if(items[i] == suspect) {
			return i;
		}
	}
	return -1;
}

int binary_search(int n, int*  items, int suspect) {
	int left = 0, right = n; // left inclusive. right exclusive.
	while(left < right) {
		int mid = left + (right - left) / 2;
		if(suspect < items[mid]) {
			right = mid;
		} else if (items[mid] < suspect) {
			left = mid + 1;
		} else {
			return mid;
		}
	}
	return left;
}
