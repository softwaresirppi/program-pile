#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& numbers, int begin, int end, int pivot){
    int ridge = begin;
    for(int i = begin; i < end; i++)
        if(numbers[i] <= pivot)
	    swap(numbers[ridge++], numbers[i]);
    ridge = end - 1;
    for(int i = end - 1; i >= begin; i--)
        if(numbers[i] >= pivot)
	    swap(numbers[ridge--],  numbers[i]);
    return ridge + 1;
}

// selects the kth smallest element (dont be a pussy, start at zero)
// REQUIREMENTS: 0 <= k < numbers.size()
int quickselect(vector<int>& numbers, int begin, int end, int k){
    if(end <= begin) return numbers[begin];

    // So that we can blame it on god when things get worse.
    int pivot = numbers[begin + rand() % (end - begin)];
    int ridge = partition(numbers, begin, end, pivot);
    if(k < ridge)
	return quickselect(numbers, begin, ridge, k);
    else if(ridge < k)
	return quickselect(numbers, ridge + 1, end, k);
    else
	return numbers[ridge];
}

void quicksort(vector<int>& numbers, int begin, int end){
    if(end <= begin) return;

    int pivot = numbers[begin + rand() % (end - begin)];
    int ridge = partition(numbers, begin, end, pivot);
    quicksort(numbers, begin, ridge);
    quicksort(numbers, ridge + 1, end);
}

int main(){
    vector<int> numbers{16, 0, 32, 128, 16, 1};
    quicksort(numbers, 0, numbers.size());
    cout << "2th smallest element" << endl;
    cout << quickselect(numbers, 0, numbers.size(), 2) << endl;
    cout << "SORTED: " << endl;
    for(int x: numbers) cout << x << " "; cout << endl;
}
