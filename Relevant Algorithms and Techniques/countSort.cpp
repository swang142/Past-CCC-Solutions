// Counting sort in C++ programming

#include <iostream>
using namespace std;

int count[max];

void countSort(int array[]) {

  int count[max];

  // Find the largest element of the array
  for (int i = 1; i < max; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < max; i++) {
    count[array[i]]++;
  }
}
// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int array[] = {4, 2, 2, 8, 3, 3, 1};
  int n = sizeof(array) / sizeof(array[0]);
  countSort(array, n);
  printArray(array, n);
}
