#include <cstdlib>
#include <iostream>
#include <vector>

template <typename T>
T one_norm(T* v, int size)
{
    T norm = 0;
    for (int i = 0; i < size; i++)
        if (v[i] < 0) norm += -v[i];
        else norm += v[i];
    return norm;
}

template <class T>
T one_norm(std::vector<T> v)
{
    T norm = 0;
    for (int i = 0; i < v.size(); i++)
        if (v[i] < 0) norm += -v[i];
        else norm += v[i];
    return norm;
}

int main(int argc, char const *argv[])
{
    int v[3]; 
    std::vector<int> u;
    u.push_back(3); u.push_back(2); u.push_back(2);
    v[0] = 3; v[1] = 2; v[2] = 2;
    std::cout << one_norm(v, 3) << std::endl;
    std::cout << one_norm(u) << std::endl;

    float x[2];
    x[0] = 0.557; x[1] = 2.713;
    std::cout << one_norm(x, 2) << std::endl;

    std::vector<float> y;
    y.push_back(0.557); y.push_back(0.213);

    std::cout << one_norm(y) << std::endl;

    // abs
    

    return 0;
}
