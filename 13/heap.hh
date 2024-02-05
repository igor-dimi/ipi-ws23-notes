#ifndef HEA_H
#define HEA_H
#include <vector>

template <class T>
class Heap
{
    public :
        bool empty();
        void push (T item);
        void pop(); //remove root, i.e. the element with highest priority
        T top(); //insepct the element at the top
    private :
        std::vector<T> data; 
        void heapify(int i); //heapify starting at the node i downwards
};

template<class T>
void Heap<T>::push(T item)
{
    int i = data.size();
    data.push_back(item); //item is the last element of the heap
    while (i > 0 && data[i] > data[(i-1)/2]) { // child larger than parent, parent not root
        std::swap(data[i], data[(i-1)/2]); // swap child and parent
        i = (i-1)/2;
    }
}

template<class T>
void Heap<T>::heapify(int i)
{
    int n = data.size();
    while (2*i + 1 < n) { //node i has a left child
        int l = 2*i + 1; //left child
        int r = l + 1; //right child
        int k = ((r < n) && (data[r] > data[l])) ? r : l;
        std::swap(data[k], data[i]);
        i = k;
    }
}

template<class T>
void Heap<T>::pop()
{
    std::swap(data.front(), data.back());
    data.pop_back();
    heapify(0);
}

template<class T>
T Heap<T>::top() {return data[0];}

template<class T>
inline bool Heap<T>::empty() {return data.size() == 0;}

#endif
