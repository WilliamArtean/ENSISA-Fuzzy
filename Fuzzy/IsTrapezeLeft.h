//
// Created by CHICHAOUI Omar on 29/01/2020.
//

#ifndef FUZZY_ISTRAPEZELEFT_H
#define FUZZY_ISTRAPEZELEFT_H

#include "Operator.h"
namespace fuzzy
{
    template <class T>
    class IsTrapezeLeft :public fuzzy::Is<T>
    {
    private:
        T mid,max;
    public:
        IsTrapezeLeft(T _mid,  T _max);
        virtual T evaluate(core::Expression<T>* o) const;
    };


    template <class T>
     IsTrapezeLeft<T>::IsTrapezeLeft(T _mid, T _max) : mid(_mid), max(_max){}

     template <class T>
     T IsTrapezeLeft<T>::evaluate(core::Expression<T> *o) const
     {
         T absisce = o->evaluate();
         if(absisce< mid)
         {
             return 1;
         } else {
             if(absisce < max)
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



#endif //FUZZY_ISTRAPEZELEFT_H
