#include <iostream>
#include <string>
using namespace std;

bool is_palindrome(string str)
{
    if (str.length() <= 1)
    {
        return true;
    }

    if (str[0] == str[str.length()-1])
    {
        return is_palindrome(str.substr(1, str.length() - 2));
    }

    return false;
}

int main()
{
    // Test cases
    cout << "Testing is_palindrome function:" << endl;
    cout << "-----------------------------------" << endl;

    cout << "is_palindrome(\"racecar\"): " << (is_palindrome("racecar") ? "true" : "false") << endl;
    cout << "is_palindrome(\"hello\"): " << (is_palindrome("hello") ? "true" : "false") << endl;
    cout << "is_palindrome(\"madam\"): " << (is_palindrome("madam") ? "true" : "false") << endl;
    cout << "is_palindrome(\"a\"): " << (is_palindrome("a") ? "true" : "false") << endl;
    cout << "is_palindrome(\"ab\"): " << (is_palindrome("ab") ? "true" : "false") << endl;
    cout << "is_palindrome(\"robin\"): " << (is_palindrome("robin") ? "true" : "false") << endl;
    cout << "is_palindrome(\"aaradhya\"): " << (is_palindrome("aaradhya") ? "true" : "false") << endl;

    return 0;
}