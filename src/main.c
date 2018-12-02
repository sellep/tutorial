#include "linked_list.h"
#include <iostream>

int main(int argc, char ** argv)
{
    if (argc < 2)
        return 1;

    list<int> *l = new linked_list<int>();
    int count = atoi(argv[1]);

    for (int i = 0; i < count; i++)
    {
        l->add(i);
    }

    return 0;
}