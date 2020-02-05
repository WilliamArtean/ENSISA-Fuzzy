//
// Created by pierr on 05/02/2020.
//

#ifndef CLIONTEST_BINARYSHADOWEXPRESSION_H
#define CLIONTEST_BINARYSHADOWEXPRESSION_H

#include "BinaryExpression.h"

namespace core {

    template <class T>
    class BinaryShadowExpression : public BinaryExpression<T> {
    public:
        T evaluate(Expression<T> l, Expression<T> r);

    private:
        BinaryExpression<T> *target;
    };

    template <class T>
    T BinaryShadowExpression<T>::evaluate(Expression<T> l, Expression<T> r) {
        if (target != NULL) {
            return target->evaluate(l, r);
        }
        return NULL;
    }

}

#endif //CLIONTEST_BINARYSHADOWEXPRESSION_H
