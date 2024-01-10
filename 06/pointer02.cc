#include <iostream>
#include <stdio.h>
#include "../code/fcpp.hh"

char* alphabet()
{
    char buffer[27];
    for (int i = 0; i < 26; i++) buffer[i] = i + 65;
    buffer[26] = 0;
    return buffer;
}

int main()
{
    char* c = alphabet();
    print(c);
    printf("%p\n", c);
    return 0;
}