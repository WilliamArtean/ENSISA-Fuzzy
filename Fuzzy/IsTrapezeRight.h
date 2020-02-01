//
// Created by CHICHAOUI Omar on 29/01/2020.
//

#ifndef FUZZY_ISTRAPEZERIGHT_H
#define FUZZY_ISTRAPEZERIGHT_H

#include "Operators.h"
namespace fuzzy
{
    template <class T>
    class IsTrapezeRight : fuzzy::Is<T>
    {
    private:
        T min,mid;
    public:
        IsTrapezeRight(T _min,  T _mid);
        virtual T evaluate(core::Expression<T>* o);
    };

    template <class T>
    IsTrapezeRight<T>::IsTrapezeRight(T _min, T _mid) : min(_min) , mid(_mid) {}


    template<class T>
    T IsTrapezeRight<T>::evaluate(core::Expression<T> *o)
    {
        T absisce = o->evaluate();
        if(absisce < min)
        {
            return 0;
        }
        else {
            if(absisce < mid){
                float a = 1/(mid - min);
                float b = 1 - mid/(mid - min);
                return a*absisce + b;
            }else{
                return 1;
            }
        }
    }

}



#endif //FUZZY_ISTRAPEZERIGHT_H
