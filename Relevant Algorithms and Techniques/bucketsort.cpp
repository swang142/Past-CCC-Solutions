// C++ program to sort an
// array using bucket sort
#include <bits/stdc++.h>
using namespace std;
 
// Function to sort arr[] of
// size n using bucket sort
void bucketSort(float arr[], int n)
{
     
    // 1) Create n empty buckets
    vector<float> b[n]; //this is an array of vectors
 
    // 2) Put array elements
    // in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in bucket
        b[bucketIndex].push_back(arr[i]);
    }


 
    // 3) Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
 
/* Driver program to test above function */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << 1+'a' << endl;
    float arr[]
        = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}