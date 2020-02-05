//
// Created by CHICHAOUI Omar on 05/02/2020.
//

#ifndef CLIONTEST_UNARYSHADOWEXPRESSION_H
#define CLIONTEST_UNARYSHADOWEXPRESSION_H

#include <Iostream>
#include "UnaryExpression.h"
#include "BinaryShadowExpression.h"

namespace core {
    template <class T>
    class UnaryShadowExpression : public UnaryExpression<T>
    {
    private:
        Expression<T>* target;
    public:
        UnaryShadowExpression();
        UnaryShadowExpression(UnaryExpression<T>* _target);
        void setTarget(const UnaryExpression<T>& _target);
        UnaryExpression<T> getTarget();

        virtual T evaluate(Expression<T>* o) const;
    };

    template <class T>
    UnaryShadowExpression<T>::UnaryShadowExpression() {}

    template <class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(core::UnaryExpression<T> *_target) : target(_target)
    {}


    template <class T>
    void UnaryShadowExpression<T>::setTarget(const UnaryExpression<T>& _target) {
        this->target = _target;
    }

    template <class T>
    UnaryExpression<T> UnaryShadowExpression<T>::getTarget() {
        return target;
    }

    template<class T>
    T UnaryShadowExpression<T>::evaluate(core::Expression<T> *o) const {
        if(target != NULL)
            return this->target->evaluate(o);
        return NULL;
    }
}

#endif //CLIONTEST_UNARYSHADOWEXPRESSION_H
