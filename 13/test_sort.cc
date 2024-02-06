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

void bubble_sort(int* arr, int size)
{
    // invariant: sorted(arr[i+1..size - 1])
    for (int i = size - 1; i >= 0; i--) {
        //bubble until i
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j+1]) //swap a[j], a[j+1]
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    } // i == -1 => sorted(arr[0..size - 1])
}

template <class T>
void bubblesort(T& arr)
{
    // invariant: sorted(arr[i+1 .. size - 1])
    for (int i = arr.size() - 1; i >= 0; i--) {
        // bubble until i
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j+1]) std::swap(arr[j], arr[j+1]);
    } // i == -1 => sorted(arr[0 .. size - 1])
}


void insertion_sort(int* arr, int size)
{
    // sorted(arr[0 .. i])
    for (int i = 0; i < size - 1; i++){
        //insert a[i+1] in a[0 .. i]
        int j = i;
        while (j >= 0 && arr[j] > arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j--;
        }
    } // i == size - 1 => sorted(arr[0 .. size - 1])
}

// modifies arr s.t. sorted(arr[i .. i + n - 1]) holds
// template <class C>
void mergesort(int* arr, int i, int n)
{
    if (n == 1) return; //single element to sort, do nothing

    // divide and sort recursively
    int n1 = n/2;
    int n2 = n - n1;
    mergesort(arr, i, n1); //sorted(a[i .. i + n1-1]
    mergesort(arr, i + n1, n2); //sorted(a[i+n1, i + n-1])

    //merge
    int temp[n]; // secondary temp array to realize merging
    int i1 = i, i2 = i + n1;
    int k = 0;
    while (i1 < i + n1 && i2 < i + n) {
        if (arr[i1] < arr[i2]) {
            temp[k] = arr[i1];
            i1++;
        } else {
            temp[k] = arr[i2];
            i2++;
        }
        k++;
    } // i1 == i + n1 || i2 == i + n
    if (i1 == i + n1) { //end of 
        for (int l = i2; l < i + n; l++) temp[k++] = arr[l];
    } else //i2 == i + n
        for (int l = i1; l < i1 + n1; l++) temp[k++] = arr[l];
    //copy temp to arr
    for (int k = 0; k < n; k++) arr[i + k] = temp[k];
}

// merge two sorted arrays into arr
void merge(int* arr1, int* arr2, int size1, int size2, int* arr)
{
    int temp[size1 + size2];
    int i, j, k;
    i = j = k = 0;
    
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            temp[k] = arr1[i];
            i++;
        } else {
            temp[k] = arr2[j];
            j++;
        }
        k++;
    } // i == size1 || j == size2
    if (i == size1) {
        for (int l = j; l < size2; l++) temp[k++] = arr2[l];
    } else 
        for (int l = i; l < size2; l++) temp[k++] = arr2[l];
    for (int k = 0; k < size1 + size2; k++) arr[k] = temp[k];
}

template<class C>
//heapify at node 
inline void heapify(C& a, int n, int i)
{
    while (2*i + 1 < n) //left child exists
    {
        int l = 2*i + 1; //left child
        int r = l + 1;  //right child
        int k = ((r < n) && (a[r] > a[l])) ? r : l;
        if (a[k] <= a[i]) break;
        std::swap(a[k], a[i]);
        i = k;
    }
}

template <class C>
void heapsort (C& a)
{
    //build the heap by reheaping from the rear
    for (int i = a.size() - 1; i >= 0; i--)
        heapify(a, a.size(), i);
    for (int i = a.size() - 1; i >= 0; i--) {
        std::swap(a[0], a[i]);
        heapify(a, i, 0);
    }
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


    std::cout << std::endl;
    int arr4[] = {3, 1, 10, -5, 6};
    show(arr4, 5);
    bubble_sort(arr4, 5);
    show(arr4, 5);
    // int arr5[] = {3};
    // bubble_sort(arr5, 1);
    // show(arr5, 1);

    std::cout << std::endl;

    std::vector<int> v2;
    for (int i = 0; i < 20; i++) v2.push_back(z.ziehe_zahl() % 45);
    std::cout << v2;
    bubblesort(v2);
    std::cout << v2;


    int arr5[] = {3, 1, 10, -5, 6};
    show(arr5, 5);
    insertion_sort(arr5, 5);
    show(arr5, 5);

    int arr6[] = {-1, 10, -2, 5, 10};
    int arr7[] = {-3, 2, 10, 12};

    insertion_sort(arr6, 5);
    insertion_sort(arr7, 4);

    show(arr6, 5);
    show(arr7, 4);

    int arr8[9];

    merge(arr6, arr7, 5, 4, arr8);

    show(arr8, 9);
    int arr9[] = {-2, 10, 22, -9, 3, 5};
    show(arr9, 6);
    mergesort(arr9, 0, 6);
    show(arr9, 6);

    std::vector<int> v4;
    for (int i = 0; i < 12; i++) v4.push_back(z.ziehe_zahl() % 33);
    std::cout << v4;
    heapsort(v4);
    std::cout << v4;

    return 0;
}
