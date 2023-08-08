#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int c = 0; 

// Function to partition the array
int partition(int arr[], int p, int r) {
	int key = arr[r]; // Choosing the last element as the pivot
	int i = p - 1;


	// Iterating through the array
	for (int j = p; j <= r; j++) {
		if (arr[j] < key) { 
			c++; 
			i++;
			swap(arr[i], arr[j]); 
		}
	}


	swap(arr[i + 1], arr[r]); // Placing the pivot in its correct position
	return i + 1; // Returning the index of the pivot
}

// Function to choose a random pivot and partition the array
int random_partition(int arr[], int p, int r) {
	int i = p + rand() % (r - p + 1); 
	swap(arr[i], arr[r]); 
	return (partition(arr, p, r)); 
}


// Function to perform random quicksort
void random_quicksort(int arr[], int p, int r) {
	if (p < r) {
		int q = random_partition(arr, p, r); 
		random_quicksort(arr, p, q - 1); 
		random_quicksort(arr, q + 1, r); 
	}
}

int main() {

	srand(time(0)); // Seeding the random number generator

	int n;

	cin >> n; // Taking input for the number of elements
	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; // Taking input for the array elements
	}


	random_quicksort(arr, 0, n - 1); // Calling the random quicksort function

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " "; // Printing the sorted array
	}

	cout << "comparisons: " << c << endl; // Printing the number of comparisons

	return 0;
}
