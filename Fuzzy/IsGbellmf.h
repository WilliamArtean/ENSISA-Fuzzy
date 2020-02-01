//
// Created by CHICHAOUI Omar on 29/01/2020.
//

#ifndef FUZZY_ISGBELLMF_H
#define FUZZY_ISGBELLMF_H
#include "Operators.h"
#include <math.h>
namespace fuzzy{
    template <class T>
    class IsGbellmf : fuzzy::Is<T>
    {
    private:
        T a,b,c;
    public:
        IsGbellmf(T _a,T _b,T _c);
        virtual T evaluate(core::Expression<T>* o);
    };


    template <class T>
    IsGbellmf<T>::IsGbellmf(T _a, T _b, T _c) : a(_a),b(_b),c(_c){}

    template <class T>
    T IsGbellmf<T>::evaluate(core::Expression<T> *o)
    {
        T absisce = o->evaluate();
       // return  1/(1 + (abs((absisce - c)/a))^(2 * b));
        return 1/(1 + pow(abs((absisce - c)/a), 2*b));
    }
}


#endif //FUZZY_ISGBELLMF_H
