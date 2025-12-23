#include <iostream>
using namespace std;

void printValue(int *p)
{
    // Inside this function, you don't have 'x'
    // You only have the pointer 'p'
    cout << *p << endl; // Must use *p
}

void tryChange(int x)
{
    x = 100;
    cout << "  Inside tryChange: x = " << x << endl;
}

void actuallyChange(int *ptr)
{
    *ptr = 100;
    cout << "  Inside actuallyChange: *ptr = " << *ptr << endl;
}

void changePointer(int *ptr) {
    int y = 99;
    ptr = &y;  // Changes the copy of the pointer
}

void actuallyChangePointer(int **ptrPtr) {
    int y = 99;
    *ptrPtr = &y;  // Changes the actual pointer
}

int main()
{
    int x = 5;
    int *ptr = &x; // ptr stores the address of x

    /*--------------- variable and adrdress--------------*/
    cout << "x is just a variable = " << x << endl;
    cout << "&x is the memory address where x lives = " << &x << endl;

    /*--------------- pointers --------------*/
    cout << "ptr holds the address of x = " << ptr << endl;
    cout << "*ptr is again the value itself = " << *ptr << endl;

    /* pass be reference vs pass by value */
    cout << "Accessing x directly = " << x << endl; // Direct access
    cout << "Accessing x via address: ";
    printValue(&x); // This will print inside the function

    /* Why pointers matter: changing values */
    cout << "\n--- Pass by value vs Pass by pointer ---" << endl;
    x = 5; // Reset x

    cout << "Before tryChange: x = " << x << endl;
    tryChange(x);
    cout << "After tryChange: x = " << x << endl;

    cout << "\nBefore actuallyChange: x = " << x << endl;
    actuallyChange(&x);
    cout << "After actuallyChange: x = " << x << endl;


    /* Pointer to pointer */
    cout << "\n--- Pointer to Pointer ---" << endl;
    int a = 10;
    int *p = &a;

    cout << "P before anything= " << p << endl;

    cout << "Before changePointer: *p = " << *p << endl;
    changePointer(p);
    cout << "After changePointer: *p = " << *p << endl;
    cout << "Ineffective pointer change= " << p << endl;
    
    cout << "\nBefore actuallyChangePointer: *p = " << *p << endl;
    actuallyChangePointer(&p);
    cout << "After actuallyChangePointer: *p = " << *p << endl;
    cout << "Effective pointer change= " << p << endl;


    return 0;
}

/*

NOTES:
 i)   x is a regular int variable ✓
 ii)  &x is the address ✓
 iii) Address varies each run ✓


Getting the address with & is called the "address-of" operator.

*/