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
    vector<PrintJob> queue;  // This is what you were missing!

public:
    CircularArrayQueue(int size)
    {
        head = 0;
        tail = 0;
        capacity = size;
        queue.resize(size);  // Initialize vector with 'size' empty PrintJobs
    }
    
    // TODO: Add your methods here
    // void enqueue(string print_data, string employee_name)
    // string dequeue()
    // bool isEmpty()
    // bool isFull()
};