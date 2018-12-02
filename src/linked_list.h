#pragma once

#include "list.h"
#include <cstddef>

template <class T> class linked_list : public list<T>
{
    class ll_node
    {
    public:
        T val;
        ll_node *next;

        ll_node(T val)
        {
            this->val = val;
            next = nullptr;
        }
    };

    ll_node *root = nullptr;
    #ifdef TAIL
    ll_node *tail = nullptr;
    #endif
    std::size_t count;

public:
    void add(T val)
    {
        if (root == nullptr)
        {
            root = new ll_node(val);
            #ifdef TAIL
            tail = root;
            #endif
        }
        else
        {
            #ifdef TAIL
            tail->next = new ll_node(val);
            tail = tail->next;
            #else
            ll_node *cur = root;

            while (cur->next != nullptr)
            {
                cur = cur->next;
            }

            cur->next = new ll_node(val);
            #endif
        }

        count++;
    }
};