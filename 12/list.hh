template <class T>
class List 
{
    public :
        // infrastructure? 
        List () {_first = 0;} 
        ~List();

        // List element as private class
        class Link 
        {
            Link* _next;
            public :
                T item;
                Link (T& t) {item = t;}
                Link* next() {return _next;}
                friend class List<T>;a
        }

        Link* first () {return _first;}
        void insert (Link* where, T t);
        void remove (Link* where);

    private :
        Link* _first;
        // Private copy constructor and assignment operator
        List (const List<T>& l) {};
        List<T>& operator= (const List<T>& l) {};
};