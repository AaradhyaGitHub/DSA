#include <iostream>
using namespace std;
// FIFO
// First In-First Out
// Printer Job Queue

class PrintJob
{
public:
    string data;
    string employee;
    PrintJob *next;

    PrintJob(string print_data, string employee_name)
    {
        data = print_data;
        employee = employee_name;
        next = nullptr;
    }
};

class LinkedListQueue
{
private:
    PrintJob *head;
    PrintJob *tail;

public:
    LinkedListQueue()
    {
        head = nullptr;
        tail = nullptr;
    };

    ~LinkedListQueue()
    {
        while (head != nullptr)
        {
            PrintJob *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void enqueue(string print_data, string employee_name)
    {
        if (head == nullptr && tail == nullptr)
        {
            PrintJob *first_print_job = new PrintJob(print_data, employee_name);
            head = first_print_job;
            tail = first_print_job;
            cout << "📄 " << employee_name << "'s print job received: \"" << print_data << "\"" << endl;
            cout << "   ✅ Your print will be executed first!" << endl;
            cout << "----------------------------------" << endl;
        }
        else
        {
            PrintJob *new_print_job = new PrintJob(print_data, employee_name);
            string last_employee = tail->employee;
            tail->next = new_print_job;
            tail = new_print_job;

            cout << "📄 " << employee_name << "'s print job received: \"" << print_data << "\"" << endl;
            cout << "   ⏳ Your print will be executed after: " << last_employee << endl;
            cout << "________________________________________" << endl;
        }
    };

    string dequeue()
    {
        if (head == nullptr)
        {
            cout << "❌ Queue is empty! Nothing to print!" << endl;
            return "";
        }

        PrintJob *temp = head;
        string currently_printing = temp->employee;
        string document = temp->data;

        cout << "🖨️  Printing " << currently_printing << "'s document: \"" << document << "\"..." << endl;

        head = temp->next;
        delete temp;

        if (head == nullptr)
        {
            tail = nullptr;
            cout << "   ✅ Print successful! Queue is now empty." << endl;
        }
        else
        {
            cout << "   ✅ Print successful! Next to print: " << head->employee << " (\"" << head->data << "\")" << endl;
        }

        return currently_printing;
    }

    string front()
    {
        if (head == nullptr)
        {
            return "Queue is empty";
        }
        return head->employee + " - " + head->data;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }
};

int main()
{
    LinkedListQueue printer;

    printer.enqueue("Q4 Fiscal Year Report", "Eric");
    printer.enqueue("New Hire Onboarding Packet", "Sarah");
    printer.enqueue("Cyber Attack Incident Report", "Mike");
    printer.enqueue("Employee Benefits Summary", "Jessica");

    cout << "\n--- Starting to process print jobs ---\n"
         << endl;

    printer.dequeue(); // Eric
    printer.dequeue(); // Sarah
    printer.dequeue(); // Mike
    printer.dequeue(); // Jessica
    printer.dequeue(); // Should say "Queue is empty"

    cout << "\n--- Testing after empty ---\n"
         << endl;
    printer.enqueue("Marketing Proposal 2025", "Tom");
    printer.dequeue(); // Tom
}