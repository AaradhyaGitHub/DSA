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

void display(Planet **head)
{
    Planet *current = *head;

    while (current != nullptr)
    {
        cout << current->name << endl;
        current = current->next;
    }
}

int main()
{

    Planet *mercury = new Planet("Mercury");
    Planet *venus = new Planet("Venus");
    Planet *earth = new Planet("Earth");
    Planet *mars = new Planet("Mars");
    Planet *jupiter = new Planet("Jupiter");
    Planet *saturn = new Planet("Saturn");

    mercury->next = venus;
    venus->next = earth;
    earth->next = mars;
    mars->next = jupiter;
    jupiter->next = saturn;
    saturn->next = nullptr;

    Planet *head = mercury;
    Planet *current = head;

    display(&head);

    return 0;
}