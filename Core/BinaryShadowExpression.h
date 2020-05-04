//
// Created by CHICHAOUI Omar on 05/02/2020.
//

#ifndef CLIONTEST_BINARYSHADOWEXPRESSION_H
#define CLIONTEST_BINARYSHADOWEXPRESSION_H

#include "BinaryExpression.h"
#include <iostream>

namespace core {
    template <class T>
    class BinaryShadowExpression:BinaryExpression<T>{
    private:
        BinaryExpression<T>* target;
    public:
        BinaryShadowExpression();
        virtual T evaluate(Expression<T>* l, Expression<T>* r) const;
        void setTarget(const BinaryExpression<T>& binaryExpression);
        BinaryExpression<T>  getTarget();
    };

    template <class T>
    BinaryShadowExpression<T>::BinaryShadowExpression() {}

    template <class T>
    T BinaryShadowExpression<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const
    {
        if(this->target != NULL)
            return target->evaluate(l,r);
        //throw NullArgumentException("BinaryShadowExpression : Expression");
        return NULL;
    }
    template <class T>
    BinaryExpression<T> BinaryShadowExpression<T>::getTarget() {
        return target;
    }
    template <class T>
    void BinaryShadowExpression<T>::setTarget(const BinaryExpression<T> &binaryExpression)
    {
        this->target = binaryExpression;
    }



}

#endif //CLIONTEST_BINARYSHADOWEXPRESSION_H