#include "linked_list.h"
#include "array_list.h"
#include <iostream>

template<class T> list<T>* get_list()
{
#ifdef ARRAY
    return new array_list<T>();
#else
    return new linked_list<T>();
#endif
}

int main(int argc, char ** argv)
{
    if (argc < 2)
        return 1;

    int count = atoi(argv[1]);

    list<int> *l = get_list<int>();

    for (int i = 0; i < count; i++)
    {
        l->add(i);
    }

    return 0;
}