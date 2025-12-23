#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive function to find the largest number in a vector
int find_max(const vector<int> &arr, int index)
{
    if (index == arr.size() - 1)
    {
        return arr[index];
    }

    return max(arr[index], find_max(arr, index + 1));
}

int main()
{
    // Test Case 1: Basic example from problem
    vector<int> test1;
    test1.push_back(3);
    test1.push_back(1);
    test1.push_back(4);
    test1.push_back(1);
    test1.push_back(5);
    test1.push_back(9);
    cout << "Test 1: find_max([3, 1, 4, 1, 5, 9]) = "
         << find_max(test1, 0) << " (expected: 9)" << endl;

    // Test Case 2: All same numbers
    vector<int> test2;
    test2.push_back(7);
    test2.push_back(7);
    test2.push_back(7);
    cout << "Test 2: find_max([7, 7, 7]) = "
         << find_max(test2, 0) << " (expected: 7)" << endl;

    // Test Case 3: Negative numbers
    vector<int> test3;
    test3.push_back(-5);
    test3.push_back(-1);
    test3.push_back(-10);
    test3.push_back(-3);
    cout << "Test 3: find_max([-5, -1, -10, -3]) = "
         << find_max(test3, 0) << " (expected: -1)" << endl;

    // Test Case 4: Single element
    vector<int> test4;
    test4.push_back(42);
    cout << "Test 4: find_max([42]) = "
         << find_max(test4, 0) << " (expected: 42)" << endl;

    // Test Case 5: Max at beginning
    vector<int> test5;
    test5.push_back(100);
    test5.push_back(1);
    test5.push_back(2);
    test5.push_back(3);
    cout << "Test 5: find_max([100, 1, 2, 3]) = "
         << find_max(test5, 0) << " (expected: 100)" << endl;

    // Test Case 6: Max at end
    vector<int> test6;
    test6.push_back(1);
    test6.push_back(2);
    test6.push_back(3);
    test6.push_back(100);
    cout << "Test 6: find_max([1, 2, 3, 100]) = "
         << find_max(test6, 0) << " (expected: 100)" << endl;

    return 0;
}