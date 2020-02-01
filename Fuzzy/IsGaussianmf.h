//
// Created by CHICHAOUI Omar on 29/01/2020.
//

#ifndef FUZZY_ISGAUSSIANMF_H
#define FUZZY_ISGAUSSIANMF_H
#include <math.h>

#include "Operators.h"

namespace fuzzy{
    template <class T>
    class IsGaussianmf : fuzzy::Is<T>
    {
    private:
        T sig, c;
    public:
        IsGaussianmf(T _sig, T _c );
        virtual T evaluate(core::Expression<T>* o);

    };

    template <class T>
    IsGaussianmf<T>::IsGaussianmf(T _sig, T _c): sig(_sig) , c(_c) {}

    template<class T>
    T IsGaussianmf<T>::evaluate(core::Expression<T> *o)
    {
          T absisce = o->evaluate();
         return exp((-(absisce - c)*(absisce - c))/(2 * sig*sig));
    }
}

#endif //FUZZY_ISGAUSSIANMF_H
