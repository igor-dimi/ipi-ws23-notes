#include <iostream>
#include "arr.cc"

std::ostream& operator<< (std::ostream& stream, 
    Array& arr)
{
    for (int i = arr.min_index(); i <= arr.max_index(); i++) {
        std::cout << arr[i] << " ";
    }
    return stream;
}

int main()
{
    Array arr(10, 1.0);
    Array arr2(5, 3.5);
    std::cout << arr << std::endl << arr2 << std::endl;
}