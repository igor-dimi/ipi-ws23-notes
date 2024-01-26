#include <iostream>
#include "CheckedArray.cc"

float g(Array a, int index) 
{
    return a[index];
}

int main()
{
    CheckedArray arr(10, 3.1415);
    std::cout << arr[9] << std::endl;
    // std::cout << arr[10] << std::endl;
    std::cout << g(arr, 9) << std::endl;
    std::cout << g(arr, 10) << std::endl;
    return 0;
}