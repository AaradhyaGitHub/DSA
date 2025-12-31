#include <iostream>
#include <vector>
using namespace std;

class PrintJob
{
public:
    string data;
    string employee;

    // Default constructor for empty slots
    PrintJob()
    {
        data = "";
        employee = "";
    }

    PrintJob(string print_data, string employee_name)
    {
        data = print_data;
        employee = employee_name;
    }
};

class CircularArrayQueue
{
private:
    int head;
    int tail;
    int capacity;
    vector<PrintJob> queue; // This is what you were missing!

public:
    CircularArrayQueue(int size)
    {
        head = 0;
        tail = 0;
        capacity = size;
        queue.resize(size); // Initialize vector with 'size' empty PrintJobs
    }

    // bool isEmpty()
    // bool isFull()
    bool isEmpty()
    {
        return head == tail;
    };

    bool isFull()
    {
        return (tail + 1) % capacity == head ? true : false;
    }

    void display()
    {
        int current = head;
        int index = 1;
        cout << endl;
        cout << "---- ALL JOBS ----" << endl;
        cout << endl;

        while (current != tail)
        {

            cout << index << ") 🗎 " << queue[current].data << endl;
            cout << "  - 👤" << queue[current].employee << endl
                 << endl;
            current = (current + 1) % capacity;
            index++;
        }
    }

    void dequeue()
    {
        if (head == tail)
        {

            cout << "Queue is empty. Nothing to print." << endl;
            return;
        }

        cout << "-------------------------------------------" << endl;
        cout << "Document to Print: " << queue[head].data << endl;
        cout << "Owner: " << queue[head].employee << endl;
        cout << "-------------------------------------------" << endl;

        head = (head + 1) % capacity;
        return;
    }

    void enqueue(string print_data, string employee_name)
    {
        if ((tail + 1) % capacity == head)
        {
            cout << "---------------------------------------------------" << endl;
            cout << "Queue is full! " << print_data << " NOT added" << endl;
            cout << "Please try adding after the first item is printed" << endl;
            cout << "---------------------------------------------------" << endl;

            return;
        }

        queue[tail] = PrintJob(print_data, employee_name);
        cout << employee_name << "'s print added!" << endl;
        tail = (tail + 1) % capacity;
    }
};

int main()
{
    CircularArrayQueue printer(5);

    printer.enqueue("English 2 Adv Syllabus", "Ms. Ngo");
    printer.enqueue("ITA Syllabus", "Mr. Lindsay");
    printer.enqueue("Geometry Final v1", "Mr. Tarpeh");
    printer.enqueue("Spanish Final Answersheet", "Ms. Caballero");
    printer.display();

    printer.dequeue();
    printer.display();
}

/*
 Pitfalls:
- for enqueue, tail is what we are gonna manipulate.
- Even for the first element, you'd set queue[tail], not head
- But the if statement is there to compare the head and tail to detect when we are over the bound
- next_position = (current_position + 1) % capacity;

Array size = 5 (spots 0, 1, 2, 3, 4)
At spot 3: (3 + 1) % 5 = 4 % 5 = 4  ✅ Normal
At spot 4: (4 + 1) % 5 = 5 % 5 = 0  ✅ WRAPS!
At spot 0: (0 + 1) % 5 = 1 % 5 = 1  ✅ Normal
At spot 1: (1 + 1) % 5 = 2 % 5 = 2  ✅ Normal

*/
