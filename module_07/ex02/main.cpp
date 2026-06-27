#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "--- test 1: empty constructor ---" << std::endl;
    Array<int> empty;
    std::cout << "size: " << empty.size() << std::endl;

    std::cout << "\n--- test 2: constructor with size ---" << std::endl;
    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i * 10;
    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;

    std::cout << "\n--- test 3: copy constructor ---" << std::endl;
    Array<int> copy(arr);
    copy[0] = 999;
    std::cout << "arr[0] after modifying copy: " << arr[0] << std::endl;
    std::cout << "copy[0]: " << copy[0] << std::endl;

    std::cout << "\n--- test 4: operator= ---" << std::endl;
    Array<int> assigned;
    assigned = arr;
    assigned[0] = 888;
    std::cout << "arr[0] after modifying assigned: " << arr[0] << std::endl;
    std::cout << "assigned[0]: " << assigned[0] << std::endl;

    std::cout << "\n--- test 5: out of bounds exception ---" << std::endl;
    try
    {
        std::cout << arr[99] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- test 6: array of strings ---" << std::endl;
    Array<std::string> strs(3);
    strs[0] = "hello";
    strs[1] = "world";
    strs[2] = "42";
    for (unsigned int i = 0; i < strs.size(); i++)
        std::cout << strs[i] << std::endl;

    return 0;
}