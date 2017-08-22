/*
C++ Program to implement Merge Sort.
Best Case Time Complexity	= O(nlogn)
Worst Case Time Complexity	= O(nlogn)
Space Complexity		= O(n)
*/

#include <iostream>
using namespace std;

void merge_arr(int arr[], int p, int q, int r)
{
    int i, j, k;
    int n1 = q - p + 1;
    int n2 =  r - q;
    int L[n1], R[n2];

    // Copy to L[] and R[] from arr[]
    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1+ j];

    // Merge L[] and R[] to arr[p ... r]
    i = 0; j = 0; k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining of L/R to arr[p ... r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = p+(r-p)/2;

        // Sort first and second halves
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        // Merge the 2 halves
        merge_arr(arr, p, q, r);
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

	mergeSort(a, 0, n-1);

	cout << endl << "Sorted array: ";
	print_array(a, n);
	return 0;
}
