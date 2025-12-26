#include <iostream>
using namespace std;

class Planet
{
public:
    string name;
    Planet *next;

    Planet(string planet_name)
    {
        name = planet_name;
        next = nullptr;
    };
};

class LinkedListStack
{
private:
    Planet *head;

public:
    LinkedListStack()
    {
        head = nullptr;
    };
    ~LinkedListStack()
    { // Destructor (right after constructor)
        while (head != nullptr)
        {
            Planet *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(string planet_name)
    {
        Planet *newPlanet = new Planet(planet_name);
        newPlanet->next = head;

        head = newPlanet;
        cout << planet_name << " added to the STACK! " << endl;
        cout << "___________________________" << endl;
    };

    void display()
    {
        Planet *current = head;
        int index = 1;
        while (current != nullptr)
        {
            cout << index << ") " << current->name << endl;
            index++;
            current = current->next;
        }
    };

    string pop()
    {
        if (head == nullptr)
        {
            return "";
        }
        Planet *temp = head;
        string name_to_return = temp->name;

        head = temp->next;
        delete temp;
        return name_to_return;
    }

    string peek()
    {
        if (head == nullptr)
            return "";
        cout << "Head of the Stack: " << head->name << endl;
        return head->name; // Returns "Earth" ✅
    };

    bool isEmpty()
    {
        return head == nullptr ? true : false;
    }
};

int main()
{
    LinkedListStack solarSystem;
    LinkedListStack unexploredGalaxy;
    solarSystem.push("Uranus *snickers");
    solarSystem.push("Saturn");
    solarSystem.push("Jupiter");
    solarSystem.push("Mars");
    solarSystem.push("Earth");
    solarSystem.push("Venus");
    solarSystem.push("Mercury");

    cout << endl;
    solarSystem.display();

    cout << endl;
    solarSystem.peek();

    if (solarSystem.isEmpty())
    {
        cout << "Solar System Stack is not explored";
    }
    else
    {
        cout << "Solar System is explored! Here are the planets:" << endl;
        solarSystem.display();
    }

    cout << endl;

    if (unexploredGalaxy.isEmpty())
    {
        cout << "This Galaxy is unexplored!";
    }
    else
    {
        cout << "This Galaxy is explored!" << endl;
        unexploredGalaxy.display();
    }

    cout << "\n--- Testing pop() ---" << endl;
    string removed = solarSystem.pop();
    cout << "Removed: " << removed << endl;

    cout << "\nStack after pop:" << endl;
    solarSystem.display();
}
