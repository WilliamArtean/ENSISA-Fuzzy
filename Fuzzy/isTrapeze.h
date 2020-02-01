//
// Created by CHICHAOUI Omar on 29/01/2020.
//

#ifndef FUZZY_ISTRAPEZE_H
#define FUZZY_ISTRAPEZE_H
#include "Operators.h"

namespace  fuzzy
{
    template<class T>
    class IsTrapeze :public fuzzy::Is<T>
    {
    private:
        T min,mid1,mid2,max;
    public:
        IsTrapeze(T _min, T _mid1, T _mid2, T _max);
        virtual T evaluate(core::Expression<T>* o);
    };

    template<class T>
    IsTrapeze<T>::IsTrapeze(T _min, T _mid1, T _mid2, T _max) : min(_min), mid1(_mid1), mid2(_mid2), max(_max)
    {

    }
    template<class T>
    T IsTrapeze<T>::evaluate(core::Expression<T> *o)
    {
        T absisce = o->evaluate();
        if(absisce< min)
        {
            return 0;
        } else {
            if(absisce < mid1)
            {
                float a = 1/(mid1 - min);
                float b = 1 - mid1/(mid1 - min);
                return a*absisce + b;
            }else{
                if(absisce < mid2)
                {
                    return 1;
                } else
                {
                    if(absisce < max)
                    {
                        float a = -1/(max - mid2);
                        float b = -a * max;
                        return a*absisce + b;
                    } else{
                        return 0;
                    }
                }
            }
        }

    }
}




#endif //FUZZY_ISTRAPEZE_H
