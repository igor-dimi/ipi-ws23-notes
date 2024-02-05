#include <iostream>
#include "../code/Zufall.cc"
#include <vector>

void show(int* arr, int size)
{
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
}
//returns index k such that arr[k] == min(arr[i..j-1])
int min(int* arr, int i, int j)
{

    int min = i; // a[min] == min(a[i..k-1])
    for (int k = i + 1; k < j; k++) 
        if (arr[k] < arr[min]) min = k;
    //k == j => a[min] == min(a[i..j-1])
    return min;
}

//swaps arr[i] with arr[j]
void swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}



void selection_sort(int* arr, int size)
{
    swap(arr, 0, min(arr, 0, size));
    //invariant: sorted(arr[0...i])
    for (int i = 0; i < size - 1; i++) {
        swap(arr, i + 1, min(arr, i + 1, size));
    } // i == size - 1 => sorted(arr[0...size - 1]) <=> sorted(arr)
}

template <class C>
void selectionsort (C& a)
{

    for (int i = 0; i < a.size() - 1; i++) {
        int min = i; // min(a[i..size-1] == a[min])
        for (int j = i + 1; j < a.size(); j++) {
            if (a[j] < a[min]) min = j;
        }
        std::swap(a[i], a[min]);
    }
}

template <class T>
std::ostream& operator<< (std::ostream& stream, std::vector<T> v)
{
    for (typename std::vector<T>::iterator it = v.begin(); it != v.end(); it++)
        stream << *it << " ";
    stream << std::endl;
    return stream;
}


int main(int argc, char const *argv[])
{
    // int arr[] = {1, 3, -5, 10, -8};
    // selection_sort(arr, 5);
    // for (int i = 0; i < 5; i++) std::cout << arr[i] << " ";
    // std::cout << std::endl;
    int arr2[] = {1, 3, -5, 10};
    show(arr2, 4);
    selection_sort(arr2, 4);
    show(arr2, 4);

    int arr[] = {1, 3, -5, 10, -8};
    show(arr, 5);
    selection_sort(arr, 5);
    show(arr, 5);

    int arr3[10];
    Zufall z(87123);
    for (int i = 0; i < 10; i++) arr3[i] = z.ziehe_zahl() % 20;

    // std::cout << min(arr2, 0, 4) << std::endl;
    // selection_sort(arr2, 5);
    // show(arr2, 5);
    // std::cout << min(arr2, 0, 4) << std::endl;

    show(arr3, 10);
    selection_sort(arr3, 10);
    show(arr3, 10);
    std::vector<int> v;
    for (int i = 0; i < 10; i++) v.push_back(z.ziehe_zahl() & 100);
    std::cout << v;
    selectionsort(v);
    std::cout << v;


    return 0;
}
