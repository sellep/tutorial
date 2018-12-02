#pragma once

#include "list.h"
#include <stdlib.h>
#include <cstddef>

template <class T> class array_list : public list<T>
{
    T *arr = nullptr;
    std::size_t length = 0;
    std::size_t size;

    void resize(std::size_t to)
    {
        arr = (T*)realloc(arr, sizeof(T) * to);
        size = to;
    }

public:
    array_list() : array_list(1)
    {

    }

    array_list(std::size_t initialSize)
    {
        resize(initialSize);
    }

    void add(T val)
    {
        if (length == size)
        {
            resize(2 * size);
        }

        arr[length++] = val;
    }
};