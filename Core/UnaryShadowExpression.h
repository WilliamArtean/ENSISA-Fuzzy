//
// Created by pierr on 05/02/2020.
//

#ifndef CLIONTEST_UNARYSHADOWEXPRESSION_H
#define CLIONTEST_UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"

namespace core {

    template <class T>
    class UnaryShadowExpression : public UnaryExpression<T> {
    public:
        T evaluate(Expression<T> *o);
        void changeTarget(UnaryExpression<T> *t);

    private:
        UnaryExpression<T> *target;
    };

    template <class T>
    T UnaryShadowExpression<T>::evaluate(core::Expression<T> *o) {
        if (target != NULL) {
            return target->evaluate(o);
        }
        return NULL;
    }

    template <class T>
    void UnaryShadowExpression<T>::changeTarget(core::UnaryExpression<T> *t) {
        target = t;
    }

}

#endif //CLIONTEST_UNARYSHADOWEXPRESSION_H
