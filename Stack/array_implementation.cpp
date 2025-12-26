#include <iostream>
#include <vector>
using namespace std;

class CityStack
{
private:
    vector<string> cities;

public:
    void add_to_top(string city)
    {
        cities.push_back(city);
    };

    string remove_top()
    {
        if (cities.empty())
        {
            return "";
        }
        string top = cities.back();
        cities.pop_back();
        return top;
    }

    string peek_top()
    {
        return cities.empty() ? "" : cities.back();
    };

    bool isEmpty()
    {
        return cities.empty();
    };

    void display()
    {
        for (int i = 0; i < cities.size(); i++)
        {
            cout << i << ": " << cities[i] << endl;
        }
    };
};

int main()
{
    CityStack myStack;
    CityStack emptyStack;

    myStack.add_to_top("El Cerrito");
    myStack.add_to_top("Albany");
    myStack.add_to_top("Berkeley");
    myStack.add_to_top("Emeryville");

    cout << "--------- CURRENT CITIES ---------" << endl;
    cout << endl;
    myStack.display();
    cout << endl;

    string westMostCity = myStack.peek_top();
    cout << "---> " << westMostCity << " is the west most city" << " <---" << endl;

    myStack.isEmpty() ? cout << "No Cities in the cities list" : cout << "City list is not empty!" << endl;
    emptyStack.isEmpty() ? cout << "No Cities in the Test Empty List..." : cout << "Test Empty List is not empty!" << endl;
    cout << endl;
    cout << endl;

    cout << "Replacing WEST MOST CITY..." << endl;
    cout << endl;
    cout << "City to remove: " << westMostCity << endl;
    cout << "Now removing " << westMostCity << endl;
    myStack.remove_top();
    cout << westMostCity << " was succesfully removed!" << endl;
    string newWestMostCity = myStack.peek_top();
    cout << newWestMostCity << " is now the west most city." << endl;

    return 0;
};