#include "linked_list.h"
#include <iostream>

int main(int argc, char ** argv)
{
    if (argc < 2)
        return 1;

	linked_list<int> ll;
	int count = atoi(argv[1]);
	
	for (int i = 0; i < count; i++)
	{
		ll.add(i);
	}

	return 0;
}