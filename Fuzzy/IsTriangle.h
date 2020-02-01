//
// Created by pierr on 26/01/2020.
//

#ifndef CLIONTEST_ISTRIANGLE_H
#define CLIONTEST_ISTRIANGLE_H

#include "Operator.h"

namespace fuzzy {

    template<class T>
    class IsTriangle : public Is<T> {
    private:
        T min, mid, max;

    public:
        virtual T evaluate(core::Expression<T>* o) const;
        IsTriangle(T min,T mid, T max);
    };

    template<class T>
    IsTriangle<T>::IsTriangle(T _min, T _mid, T _max):
            min(_min), mid(_mid), max(_max)
    {}

    template<class T>
    T IsTriangle<T>::evaluate(core::Expression<T>* o) const {
        /*
        if (o->evaluate() <= *min || o->evaluate() >= *max) {
            return 0;
        } else if (o->evaluate() <= mid) {
            return (()/())
        }
         */
        T absisce = o->evaluate();
        if(absisce< min)
        {
            return 0;
        } else
        {
            if (absisce<mid){
                float a = 1/(mid - min);
                float b = 1 - mid/(mid - min);
                return a*absisce + b;
            }else{
                if(absisce<max)
                {
                    float a = -1/(max - mid);
                    float b = -a * max;
                    return a*absisce + b;
                }else{
                    return 0;
                }
            }
        }
    }

}

#endif //CLIONTEST_ISTRIANGLE_H
