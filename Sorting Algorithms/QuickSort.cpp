/*
C++ Program to implement Quick Sort.
Best Case Time Complexity	= O(nlogn)
Worst Case Time Complexity	= O(n^2)

Space is required for Recursion Stack:
Best Case Space Complexity	= O(logn)   -> Equal Partitions (n/2 : n/2)
Worst Case Space Complexity = O(n)      -> 0:n-1 Partitions
*/

#include <iostream>
using namespace std;

// The heart of Quick Sort,
// Partition procedure
int partition(int arr[], int p, int r) {
    int pivot = r;
    int i = p-1, j, temp;

    for (j = p; j < pivot; j++) {
        if (arr[j] <= arr[pivot]) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap the pivot to it's location
    i++;
    temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;
    // Return partition location
    return i;
}

void quickSort(int arr[], int p, int r) {
    if (p < r) {
        int q;
        q = partition(arr, p, r);
        // Quick Sort on the partitions
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " " << arr[i] << ",";
	}
	cout << "\b \b" << endl;
}

int main() {
	int a[] = { 10, 12, 8, 4, 15 };
	int n = sizeof(a)/sizeof(a[0]);
	cout << "Given array: ";
	print_array(a, n);

	quickSort(a, 0, n-1);

	cout << endl << "Sorted array: ";
	print_array(a, n);
	return 0;
}
