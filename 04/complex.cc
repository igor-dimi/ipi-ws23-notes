#include "../code/fcpp.hh"
#include <math.h>

struct Complex {
    float real;
    float imag;
};

Complex create_complex (float real, float imag)
{
    Complex z;
    z.real = real;
    z.imag = imag;
    return z;
}

Complex add(Complex u, Complex w)
{
    return create_complex(
        u.real + w.real,
        u.imag + w.imag
    );
}

Complex mult(Complex u, Complex w)
{
    return create_complex(
        u.real * w.real - u.imag * w.imag,
        u.real * w.imag + w.real * u.imag
    );
}

float mag(Complex z)
{
    return sqrt(z.real * z.real + z.imag * z.imag);
}



void print_complex(Complex z){print(z.real, "+ i *", z.imag, 0);}

int main()
{
    Complex z1 = create_complex(3.0, 4.0);
    Complex z2 = create_complex(5.0, 3.0);

    Complex z3 = add(z1, z2);
    Complex z4 = mult(z1, z2);

    float m = mag(z1);

    print_complex(z1);
    print_complex(z2);
    print_complex(z3);
    print_complex(z4);
    print(m);

    return 0;
}
