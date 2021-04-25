#ifndef MAKEPTR_CPP
#define MAKEPTR_CPP

#include "makeptr.hpp"

template <class T>
makeptr<T>::makeptr()
{
    ptr = NULL;
}

template <class T>
makeptr<T>::~makeptr()
{
    if (ptr != NULL)
        delete ptr;
}

#endif