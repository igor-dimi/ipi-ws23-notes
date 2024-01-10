class FloatArr
{
    public:
        FloatArr (int n, float f);
        FloatArr(const FloatArr&);
        FloatArr& operator= (const FloatArr&);
        ~FloatArr();
        virtual float& operator[] (int i);
        int index_count ();
        int min_index();
        int max_index();
        bool is_member(int i);
    private:
        int n;
        float* p;
};

FloatArr::FloatArr(int n, float f)
{
    this->n = n;
    p = new float[n];
    for (int i = 0; i < n; i++) p[i] = f;

}

FloatArr::~FloatArr () { delete[] p;}

int FloatArr::index_count () {return n;}

int FloatArr::min_index () {return 0;}

int FloatArr::max_index () {return n - 1;}

bool FloatArr::is_member (int i) {return (i >= 0 && i < n);}

float& FloatArr::operator[] (int i) {return p[i];}

FloatArr::FloatArr(const FloatArr& fa)
{
    this->n = fa.n;
    this->p = new float[n];
    for (int i = 0; i < n; i++) p[i] = fa.p[i];
}

FloatArr& FloatArr::operator= (const FloatArr& fa)
{
    if (&fa != this){
        if (this->n != fa.n){
            delete[] p;
            this->n = fa.n;
            this->p = new float[n]; 
        }
        for (int i = 0; i < n; i++) this->p[i] = fa.p[i];
    }
    return *this;
}

