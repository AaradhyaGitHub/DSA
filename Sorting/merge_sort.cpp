#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int>(L), (R);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
};

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    vector<int> arr = {8, 3, 5, 2, 9, 1, 7, 4};

    cout << "Before sorting:\n";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    mergeSort(arr, 0, arr.size() - 1);

    cout << "After sorting:\n";
    for (int x : arr)
        cout << x << " ";
    cout << "\n";

    return 0;
}

/*
    merge helper:

    - void, takes in left, mid, right
        i)    left is usually always 0
        ii)   right is the size of the array - 1
        iii)  mid = left + (right-left) / 2
              [decided in the main]
              [like army march: left right left]

    - n1:
        i)  mid-left + 1 -> store how many in left
    - n2:
        ii) right-mid;

    - intiaite empty vector of size n1 to hold L
    - initiate empty vector of size n2 to hold R

    - To populat LL use n1 and n2:
        - L[i] = arr[left + i];
        - R[j] = arr[mid + 1 + j];

    - Re-Initiate i, j, k for comparision and placement
    - While loop to loop over n1 and n2 using i and j
    - Main manipulation in if else chain.
        i)  i and j + k and i + k and j OR
        ii) Injured Joan Kicked Idiotic Kylian's Junk

    - 2 separate while loops in case one side is over before another

    - Merge function:
        i)   if left > = right -> return
        ii)  declare mid
        iii) recurse on left -> arr, left, mid
        iv)  recurse on right -> arr, mid+1, right
        iv)  finally merge

*/