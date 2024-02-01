#ifndef DLL_H
#define DLL_H
template<class T>
class DL_list 
{
    struct Element {
        Element* next;
        Element* prev;
        T item;
        Element (T &t) 
        {
            item = t;
            next = prev = 0;
        }
    };
    public :
        typedef T MemberType;  // remember basis type 
        // iterator encapsulates pointer to list element
        class Iterator
        {
            private :
                Element* p;
            public :
                Iterator () {p = 0;}
                Iterator (Element* q) {p = q;}
                bool operator!= (Iterator x) {return p != x.p;}
                bool operator== (Iterator x) {return p == x.p;}
                Iterator operator++ () 
                { //prefix 
                    p = p->next;
                    return *this;
                }
                Iterator operator++ (int) 
                { //postfix
                    Iterator tmp = *this;
                    p = p->next;
                    return tmp;
                }
                Iterator operator-- ()
                {
                    p = p->prev;
                    return *this;
                }
                Iterator operator-- (int)
                {
                    Iterator tmp = *this;
                    p = p->prev;
                    return tmp;
                }
                T& operator* () {return p->item;}
                T* operator-> () {return &(p->item);}
                friend class DL_list<T>; 
        };

        // Iterators
        Iterator begin () const {return head;}
        Iterator end () const {return Iterator (); }
        Iterator rbegin () const {return tail;}
        Iterator rend() const {return Iterator();}

        // Construction, Destruction Assignment
        DL_list ();
        DL_list (const DL_list<T>& list);
        DL_list<T>& operator= (const DL_list<T>&);
        ~DL_list();

        // List manipulation
        Iterator insert(Iterator i, T item); 
        void erase (Iterator i);
        void append (const DL_list<T>& l);
        void clear ();
        bool empty () const;
        int size () const;
        Iterator find (T item) const;

        private :
            Iterator head; //First element of the list 
            Iterator tail; 
};
#endif // !DLL_H