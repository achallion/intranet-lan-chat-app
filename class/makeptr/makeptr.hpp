#ifndef MAKEPTR_HPP
#define MAKEPTR_HPP

#include <iostream>

template <class T>
class makeptr
{
public:
    T *ptr;

    makeptr();
    ~makeptr();
};

#endif