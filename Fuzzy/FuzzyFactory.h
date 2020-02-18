//
// Created by pierr on 05/02/2020.
//

#ifndef CLIONTEST_FUZZYFACTORY_H
#define CLIONTEST_FUZZYFACTORY_H

#include "../Core/ExpressionFactory.h"
#include "../Core/BinaryShadowExpression.h"
#include "../Core/UnaryShadowExpression.h"
#include "Operator.h"

namespace fuzzy {

    template <class T>
    class FuzzyFactory : public core::ExpressionFactory<T> {
    public:
        core::Expression<T> newAnd(core::Expression<T> *l, core::Expression<T> *r);
        core::Expression<T> newOr(core::Expression<T> *l, core::Expression<T> *r);
        core::Expression<T> newThen(core::Expression<T> *l, core::Expression<T> *r);
        core::Expression<T> newAgg(core::Expression<T> *l, core::Expression<T> *r);
        core::Expression<T> newDefuzz(core::Expression<T> *l, core::Expression<T> *r);
        core::Expression<T> newNot(core::Expression<T> *o);
        core::Expression<T> newIs(Is<T> *s, core::Expression<T> *o);

        void changeAnd(And<T> *o);
        void changeOr(Or<T> *o);
        void changeThen(Then<T> *o);
        void changeAgg(Agg<T> *o);
        //void changeDefuzz(MamdaniDefuzz<T> o);
        void changeNot(Not<T> *o);

    private:
        core::BinaryShadowExpression<T> andShadow;
        core::BinaryShadowExpression<T> orShadow;
        core::BinaryShadowExpression<T> thenShadow;
        core::BinaryShadowExpression<T> aggShadow;
        core::BinaryShadowExpression<T> defuzzShadow;

        core::UnaryShadowExpression<T> notShadow;
    };

    template <class T>
    void FuzzyFactory<T>::changeAnd(And<T> *o) {
        andShadow.changeTarget(o)
    }

}

#endif //CLIONTEST_FUZZYFACTORY_H
