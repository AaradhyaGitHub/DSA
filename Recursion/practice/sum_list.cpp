#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Recursive function to sum a vector
int sum_list(const vector<int> &arr, int index)
{
    if (index >= arr.size()){
        return 0;
    }

    return sum_list(arr, index+1)+arr[index];
}

int main()
{
    // Test Case 1: Basic example
    vector<int> test1;
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(3);
    test1.push_back(4);
    int result1 = sum_list(test1, 0);
    cout << "Test 1: sum_list([1, 2, 3, 4]) = "
         << result1 << " (expected: 10)" << endl;

    // Test Case 2: Single element
    vector<int> test2;
    test2.push_back(5);
    int result2 = sum_list(test2, 0);
    cout << "Test 2: sum_list([5]) = "
         << result2 << " (expected: 5)" << endl;

    // Test Case 3: Empty vector
    vector<int> test3;
    int result3 = sum_list(test3, 0);
    cout << "Test 3: sum_list([]) = "
         << result3 << " (expected: 0)" << endl;

    // Test Case 4: Two elements
    vector<int> test4;
    test4.push_back(10);
    test4.push_back(20);
    int result4 = sum_list(test4, 0);
    cout << "Test 4: sum_list([10, 20]) = "
         << result4 << " (expected: 30)" << endl;

    // Test Case 5: Longer list
    vector<int> test5;
    test5.push_back(1);
    test5.push_back(2);
    test5.push_back(3);
    test5.push_back(4);
    test5.push_back(5);
    test5.push_back(6);
    int result5 = sum_list(test5, 0);
    cout << "Test 5: sum_list([1, 2, 3, 4, 5, 6]) = "
         << result5 << " (expected: 21)" << endl;

    // Test Case 6: List with negative numbers
    vector<int> test6;
    test6.push_back(3);
    test6.push_back(-2);
    test6.push_back(7);
    test6.push_back(-3);
    int result6 = sum_list(test6, 0);
    cout << "Test 6: sum_list([3, -2, 7, -3]) = "
         << result6 << " (expected: 5)" << endl;

    return 0;
}
