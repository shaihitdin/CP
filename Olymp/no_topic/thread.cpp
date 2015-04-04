#include <string>
#include <iostream>
#include <thread>

using namespace std;

//The function we want to make the thread run.
void task1(string msg)
{
    cout << "task1 says: " << msg;
}

int main()
{
    // Constructs the new thread and runs it. Does not block execution.
    thread t1(task1, "Hello");

    //Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    t1.join();
}