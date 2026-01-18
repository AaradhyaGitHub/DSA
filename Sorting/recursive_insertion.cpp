#include <iostream>
#include <vector>
using namespace std;

void insertionSortRecursive(vector<int> &arr, int n)
{
    // Base case: array of size 0 or 1 is already sorted
    if (n <= 1)
        return;

    // Recursively sort first n-1 elements
    insertionSortRecursive(arr, n - 1);

    // Insert the nth element (arr[n-1]) into the sorted portion
    int key = arr[n - 1];
    int j = n - 2;

    // Same shifting logic as iterative version
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

int main()
{
    vector<int> arr = {5, 2, 4, 6, 1, 3};

    cout << "Before sorting:\n";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    insertionSortRecursive(arr, arr.size());

    cout << "After sorting:\n";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    return 0;
}