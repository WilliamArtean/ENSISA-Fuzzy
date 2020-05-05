//
// Created by pierr on 05/05/2020.
//

#ifndef CLIONTEST_NARYSHADOWEXPRESSION_H
#define CLIONTEST_NARYSHADOWEXPRESSION_H

#include "NaryExpression.h"

namespace core {

    template <class T>
    class NaryShadowExpression : public NaryExpression<T> {

    public:
        NaryShadowExpression();

        virtual T evaluate(std::vector<Expression<T>* > _operands) const;
        void setTarget(NaryExpression<T>* naryExpression);
        NaryExpression<T>* getTarget();

    private:
        NaryExpression<T>* target;

    };

    template <class T>
    NaryShadowExpression<T>::NaryShadowExpression() {}

    template <class T>
    T NaryShadowExpression<T>::evaluate(std::vector<Expression<T>* > _operands) const {
        if (target != NULL) {
            return target->evaluate(_operands);
        }
        return NULL;
    }

    template <class T>
    NaryExpression<T>* NaryShadowExpression<T>::getTarget() {
        return target;
    }

    template <class T>
    void NaryShadowExpression<T>::setTarget(NaryExpression<T>* _target) {
        target = _target;
    }

}

#endif //CLIONTEST_NARYSHADOWEXPRESSION_H
