#include <iostream>
using namespace std;

class City
{
public:
    string name;
    City *prev;
    City *next;

    City(string city_name)
    {
        name = city_name;
        prev = nullptr;
        next = nullptr;
    }
};

void going_west(City **head)
{
    City *current = *head;

    while (current != nullptr)
    {
        cout << current->name << endl;
        current = current->next;
    }
}

void going_east(City **head)
{
    City *current = *head;
    City *previous_reversed = nullptr;

    while (current != nullptr)
    {
        if (current->next == nullptr)
        {
            *head = current;
        }

        City *temp = current->prev;  // save old prev before we lose it
        
        current->next = current->prev;  // reverse next pointer
        current->prev = previous_reversed;  // reverse prev pointer
        
        previous_reversed = current;  // remember this node for next iteration
        current = temp;  // move backwards through original list
    }
}

int main()
{

    City *el_cerrito = new City("El Cerrito");
    City *albany = new City("Albany");
    City *berkeley = new City("Berkeley");
    City *oakland = new City("Oakland");

    el_cerrito->prev = nullptr;
    el_cerrito->next = albany;

    albany->prev = el_cerrito;
    albany->next = berkeley;

    berkeley->prev = albany;
    berkeley->next = oakland;

    oakland->prev = berkeley;
    oakland->next = nullptr;

    /*
        City *temp = current->prev;
        current->prev = temp;
        current->next = current->prev;
        current = current->next;

    */

    // oakland->next = berkeley;
    // oakland->prev = nullptr;

    City *head = el_cerrito;

    return 0;
}