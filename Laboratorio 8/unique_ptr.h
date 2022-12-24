#ifndef unique_ptr_h
#define unique_ptr_h
#include <iostream>
using namespace std;

template <typename T>
class unique_ptr{
    private:
        T* elem;
    public:
        unique_ptr(T* t)
        :elem{t}
        {};
        ~unique_ptr(){
            delete elem;
        };
        unique_ptr(unique_ptr t) = delete;
        operator=(unique_ptr t) = delete;
        T* release(){
            return &elem;
        };

};
#include "unique_ptr.hpp"
#endif