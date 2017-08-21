/*
C++ Program to implement Insertion Sort.
Best Case Time Complexity	= O(n)		==> When the array is sorted
Worst Case Time Complexity	= O(n^2)	==> When the array is reverse sorted
Space Complexity			= O(1)		==> Only '3' extra variables needed

Time complexity of searching in sorted part of array can be improved by using
Binary Search to O(logn), but every element after the desired place has to be
shifted right which in worst case will take O(n) and this will be done 'n' times.
So Worst Case Time Complexity remains O(n^2).

We can improve movement time to O(1) by using Doubly Linked List. But then,
instead of Binary search we'll have to use Linear Search, since Binary Search
can't be applied to DLL. This makes Search Complexity O(n) and this will be done
'n' times.
So again, Worst Case Time Complexity remains O(n^2).

Using Linear Search and Array
insertion_sort(int a[], int n)			==> Iterative Insertion Sort
rec_insertion_sort(int a[], int n)		==> Recursive Insertion Sort
*/

#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n) {
	int i, j, key;
	for (j = 1; j < n; j++) {
		key = arr[j];
		// Insert arr[j] into sorted sequence arr[1 ... (j-1)]
		i = j - 1;
		while (i>=0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
	}
}

void rec_insertion_sort(int arr[], int n) {
	if (n <= 1) { return; }		// Array is empty

	rec_insertion_sort(arr, n - 1);		// Sort first (n-1) elements

	// Insert last element at it's correct position
	int key = arr[n - 1];
	int i = n - 2;
	while (i >= 0 && arr[i] > key) {
		arr[i + 1] = arr[i];
		i--;
	}
	arr[i + 1] = key;
}

void print_array(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << " " << arr[i] << ",";
	}
	cout << "\b \b" << endl;
}

void main() {
	int a[] = { 10, 12, 8, 4, 15 };
	int b[] = { 17, 28, 1, 38, 3 };

	int n = sizeof(a) / sizeof(a[0]);
	insertion_sort(a, n);
	print_array(a, n);

	n = sizeof(b) / sizeof(b[0]);
	rec_insertion_sort(b, n);
	print_array(b, n);

	getchar();		// Console Wait
}