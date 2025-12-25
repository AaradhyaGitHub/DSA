#include <iostream>
#include <vector>
using namespace std;

// Recursive function to reverse a vector
vector<int> reverse_list(const vector<int> &arr, int index)
{
    if (index >= arr.size())
    {
        return vector<int>();
    }

    vector<int> reversed = reverse_list(arr, index + 1);
    reversed.push_back(arr[index]);
    return reversed;

    // if array size is 1 or greater, return what we received?
}

int main()
{
    // Test Case 1: Basic example from problem
    vector<int> test1;
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(3);
    test1.push_back(4);
    vector<int> result1 = reverse_list(test1, 0);
    cout << "Test 1: reverse_list([1, 2, 3, 4]) = [";
    for (int i = 0; i < result1.size(); i++)
    {
        cout << result1[i];
        if (i < result1.size() - 1)
            cout << ", ";
    }
    cout << "] (expected: [4, 3, 2, 1])" << endl;

    // Test Case 2: Single element
    vector<int> test2;
    test2.push_back(5);
    vector<int> result2 = reverse_list(test2, 0);
    cout << "Test 2: reverse_list([5]) = [";
    for (int i = 0; i < result2.size(); i++)
    {
        cout << result2[i];
        if (i < result2.size() - 1)
            cout << ", ";
    }
    cout << "] (expected: [5])" << endl;

    // Test Case 3: Empty vector
    vector<int> test3;
    vector<int> result3 = reverse_list(test3, 0);
    cout << "Test 3: reverse_list([]) = [";
    for (int i = 0; i < result3.size(); i++)
    {
        cout << result3[i];
        if (i < result3.size() - 1)
            cout << ", ";
    }
    cout << "] (expected: [])" << endl;

    // Test Case 4: Two elements
    vector<int> test4;
    test4.push_back(10);
    test4.push_back(20);
    vector<int> result4 = reverse_list(test4, 0);
    cout << "Test 4: reverse_list([10, 20]) = [";
    for (int i = 0; i < result4.size(); i++)
    {
        cout << result4[i];
        if (i < result4.size() - 1)
            cout << ", ";
    }
    cout << "] (expected: [20, 10])" << endl;

    // Test Case 5: Longer list
    vector<int> test5;
    test5.push_back(1);
    test5.push_back(2);
    test5.push_back(3);
    test5.push_back(4);
    test5.push_back(5);
    test5.push_back(6);
    vector<int> result5 = reverse_list(test5, 0);
    cout << "Test 5: reverse_list([1, 2, 3, 4, 5, 6]) = [";
    for (int i = 0; i < result5.size(); i++)
    {
        cout << result5[i];
        if (i < result5.size() - 1)
            cout << ", ";
    }
    cout << "] (expected: [6, 5, 4, 3, 2, 1])" << endl;

    // Test Case 6: List with duplicate values
    vector<int> test6;
    test6.push_back(3);
    test6.push_back(3);
    test6.push_back(7);
    test6.push_back(3);
    vector<int> result6 = reverse_list(test6, 0);
    cout << "Test 6: reverse_list([3, 3, 7, 3]) = [";
    for (int i = 0; i < result6.size(); i++)
    {
        cout << result6[i];
        if (i < result6.size() - 1)
            cout << ", ";
    }
    cout << "] (expected: [3, 7, 3, 3])" << endl;

    return 0;
}