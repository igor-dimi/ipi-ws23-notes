#include "fcpp.hh"

typedef int (*F)( int n ); // Datentyp Funktionszeiger

int apply( F f, int arg )  // apply wendet f auf arg an
{
  return f(arg);
}

int main( int argc, char *argv[] )
{
  return print( apply( []( int n ){ return n+5; }, // anonyme Fkt.
                       readarg_int( argc, argv, 1 ) ) );
}
