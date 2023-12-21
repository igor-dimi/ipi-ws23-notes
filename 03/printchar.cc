#include "../code/fcpp.hh"
#include <string>

int main()
{
    char name[32] = "Jurassic Park";
    std::string first = "Hey";
    std::string last = "Jude";
    std::string full = first + " " + last;
    for (int i = 32; print((char) i++) < 127;);
    for (int i = 0; name[i] != 0; ) print(name[i++]);
    print(name);
    print(full);
}