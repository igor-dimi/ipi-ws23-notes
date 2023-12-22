#include "../code/fcpp.hh"
#include "random.cc"

double montecarlo (Experiment& e, int N)
{
    int successful = 0;
    
    for (int i = 0; i < N; i++) successful += e.carry_out();

    return ((double) successful) / ((double) N);
}

int main(int argc, char** argv)
{
    Random r(93267); 
    Experiment e(r);

    print(sqrt(6.0/montecarlo(e, readarg_int(argc, argv, 1))));

    return 0;
}