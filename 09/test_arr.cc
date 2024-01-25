#include "arr.cc"
#include <iostream>

std::ostream& operator<< (std::ostream& stream, 
    Array& arr)
{
    for (int i = arr.min_index(); i <= arr.max_index(); i++){
        stream << arr[i] << " ";
    }
    return stream;
}

int main()
{
    Array arr(3, -3.0);
    Array arr2(4, 4.0);
    std::cout << arr << std::endl << arr2 <<std::endl;
    return 0;
}