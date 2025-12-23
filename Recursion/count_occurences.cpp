#include <iostream>
#include <vector>
using namespace std;
// Recursive function to count occurrences of a value in a vector
int count_occurrences(const vector<int> &arr, int index, int target)
{
     // Base case: if we've reached the end of the vector
     if (index >= arr.size())
     {
          return 0;
     }

     int match = (arr[index] == target) ? 1 : 0;
     
     return match + count_occurrences(arr, index + 1, target);
}

int main()
{
     // Test Case 1: Basic example from problem
     vector<int> test1;
     test1.push_back(1);
     test1.push_back(2);
     test1.push_back(3);
     test1.push_back(2);
     test1.push_back(4);
     test1.push_back(2);
     cout << "Test 1: count_occurrences([1, 2, 3, 2, 4, 2], 2) = "
          << count_occurrences(test1, 0, 2) << " (expected: 3)" << endl;

     // Test Case 2: No occurrences
     vector<int> test2;
     test2.push_back(1);
     test2.push_back(3);
     test2.push_back(5);
     test2.push_back(7);
     test2.push_back(9);
     cout << "Test 2: count_occurrences([1, 3, 5, 7, 9], 2) = "
          << count_occurrences(test2, 0, 2) << " (expected: 0)" << endl;

     // Test Case 3: All elements are the target
     vector<int> test3;
     test3.push_back(5);
     test3.push_back(5);
     test3.push_back(5);
     test3.push_back(5);
     cout << "Test 3: count_occurrences([5, 5, 5, 5], 5) = "
          << count_occurrences(test3, 0, 5) << " (expected: 4)" << endl;

     // Test Case 4: Empty array
     vector<int> test4;
     cout << "Test 4: count_occurrences([], 1) = "
          << count_occurrences(test4, 0, 1) << " (expected: 0)" << endl;

     // Test Case 5: Single element matching
     vector<int> test5;
     test5.push_back(7);
     cout << "Test 5: count_occurrences([7], 7) = "
          << count_occurrences(test5, 0, 7) << " (expected: 1)" << endl;

     // Test Case 6: Single element not matching
     vector<int> test6;
     test6.push_back(7);
     cout << "Test 6: count_occurrences([7], 3) = "
          << count_occurrences(test6, 0, 3) << " (expected: 0)" << endl;

     return 0;
}