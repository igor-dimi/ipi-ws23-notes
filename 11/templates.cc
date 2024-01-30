#include <iostream>

template <class T>
void swap (T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

template <class T>
T max(T a, T b)
{
    if (a < b) return b;
    return a;
}

int main()
{
    int a, b;
    double x, y;
    std::cin >> a >> b >> x >> y;

    swap(a, b);
    swap(x, y);
    int max1 = max(a, b);
    double max2 = max(x, y);

    std::cout << a << " " << b << "\n" << x << " " << y;
    std::cout << std::endl;
    std::cout << max1 << std::endl << max2 << std::endl;

    int max3 = max<int>(2.0, 3.0);
    std::cout << max3 << std::endl;

    return 0;
}