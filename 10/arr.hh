class Array
{
    public:
        virtual ~Array() {};
        virtual float& operator[](int i) = 0;
        virtual int num_index() = 0;
        virtual int min_index() = 0;
        virtual int max_index() = 0;
        virtual bool is_member (int i) = 0;
};