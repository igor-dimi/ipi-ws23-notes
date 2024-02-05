#include <iostream>

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