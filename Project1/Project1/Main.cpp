// Description: This is the starting point for the image processing tool
//
// Author: Jesse Kavelaars

#include <chrono>
#include <iostream>

#include "ScopedThread.h"

// TEMPORARY FUNCTIONS
void hello()
{
    std::cout << "Hello, concurrent world" << std::endl;
}


struct func
{
    func() {}

    void operator()()
    {
        hello();
    }
};


// MAIN PROCESS
int main()
{
    THRD::ScopedThread t_scoped{ std::thread(func()) };

    std::cout << "The main thread" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));

    return 0;
}