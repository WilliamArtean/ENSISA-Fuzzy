//
// Created by CHICHAOUI Omar on 05/02/2020.
//

#ifndef CLIONTEST_FUZZYFACTORY_H
#define CLIONTEST_FUZZYFACTORY_H

#include "../Core/ExpressionFactory.h"
#include "../Core/BinaryShadowExpression.h"
#include "../Core/UnaryShadowExpression.h"
#include "../Core/Expression.h"
#include "../Core/ExpressionFactory.h"
#include "Operator.h"

#include "NotMinus1.h"
#include "AndMin.h"
#include "OrMax.h"
#include "ThenMin.h"
#include "CogDefuzz.h"

namespace fuzzy{

    template <class T>
    class FuzzyFactory :public core::ExpressionFactory<T>
    {
    private:
        core::BinaryShadowExpression<T>* _OrShadow;
        core::UnaryShadowExpression<T>* _NotShadow;
        core::BinaryShadowExpression<T>* _AndShadow;
        core::BinaryShadowExpression<T>* _MamdaniDefuzzShadow;
        core::BinaryShadowExpression<T>* _ThenShadow;
        core::BinaryShadowExpression<T>* _AggShadow;


    public:

        FuzzyFactory(And<T>* opAnd, Or<T>* opOr, Not<T>* opNot, Then<T>* opThen, Agg<T>* opAgg);
        FuzzyFactory(const FuzzyFactory<T>& o);
        virtual ~FuzzyFactory();
        core::Expression<T> newAnd(core::Expression<T>* l , core::Expression<T>* r );
        core::Expression<T> newThen(core::Expression<T>* l , core::Expression<T>* r );
        core::Expression<T> newAgg(core::Expression<T>* l , core::Expression<T>* r );
        core::Expression<T> newOr(core::Expression<T>* l, core::Expression<T>* r );
        core::Expression<T> newMamdaniDefuzz(core::Expression<T>* l, core::Expression<T>* r );
        core::Expression<T> newNot(core::Expression<T>* o);
        core::Expression<T> newIs(fuzzy::Is<T>* s,core::Expression<T>* o);


        void changeAnd(fuzzy::And<T>* opAnd);
        void changeOr(fuzzy::Or<T>* opOr);
        void changeThen(fuzzy::Then<T>* opThen);
        void changeNot(fuzzy::Not<T>* opNot);


    };

    template<class T>
    FuzzyFactory<T>::FuzzyFactory(const fuzzy::FuzzyFactory<T> &o) {
        _AndShadow = new core::BinaryShadowExpression<T>(o._AndShadow);
        _OrShadow = new core::BinaryShadowExpression<T>(o._OrShadow);
        _NotShadow = new core::UnaryShadowExpression<T>(o._NotShadow);
        _ThenShadow = new core::BinaryShadowExpression<T>(o._ThenShadow);
        _AggShadow = new core::BinaryShadowExpression<T>(o._AggShadow);
    }
    template<class T>
    FuzzyFactory<T>::FuzzyFactory(And<T>* opAnd, Or<T>* opOr, Not<T>* opNot, Then<T>* opThen, Agg<T>* opAgg) {
        _AndShadow = new core::BinaryShadowExpression<T>(opAnd);
        _OrShadow = new core::BinaryShadowExpression<T>(opOr);
        _NotShadow = new core::UnaryShadowExpression<T>(opNot);
        _ThenShadow = new core::BinaryShadowExpression<T>(opThen);
        _AggShadow = new core::BinaryShadowExpression<T>(opAgg);
    }
    template <class T>
    FuzzyFactory<T>::~FuzzyFactory() {
        delete _AggShadow;
        delete _OrShadow;
        delete _NotShadow;
        delete _ThenShadow;
        delete _AndShadow;
    }

    template <class T>
    core::Expression<T> FuzzyFactory<T>::newAnd(core::Expression<T> *l, core::Expression<T> *r) {
        return newBinary(_AndShadow, l,r);
    }

    template <class T>
    core::Expression<T> FuzzyFactory<T>::newOr(core::Expression<T> *l, core::Expression<T> *r) {
        return newBinary(_OrShadow, l, r);
    }

    template <class T>
    core::Expression<T> FuzzyFactory<T>::newThen(core::Expression<T> *l, core::Expression<T> *r) {
        return newBinary(_ThenShadow, l, r);
    }

    template <class T>
    core::Expression<T> FuzzyFactory<T>::newNot(core::Expression<T> *o) {
        return newUnary(_NotShadow, o);
    }

    template <class T>
    core::Expression<T> FuzzyFactory<T>::newIs(fuzzy::Is<T> *s, core::Expression<T> *o) {
        return newUnary(s,o);
    }

    template <class T>
    core::Expression<T> FuzzyFactory<T>::newAgg(core::Expression<T> *l, core::Expression<T> *r) {
        return newBinary(_AggShadow, l, r);
    }

    template <class T>
    core::Expression<T> FuzzyFactory<T>::newMamdaniDefuzz(core::Expression<T> *l, core::Expression<T> *r) {
        return newBinary(_MamdaniDefuzzShadow, l, r);
    }



    template <class T>
    void FuzzyFactory<T>::changeAnd(fuzzy::And<T> *opAnd) {
        _AndShadow->setTarget(opAnd);
    }
    template <class T>
    void FuzzyFactory<T>::changeOr(fuzzy::Or<T> *opOr) {
        _OrShadow->setTarget(opOr);
    }
    template <class T>
    void FuzzyFactory<T>::changeNot(fuzzy::Not<T> *opNot) {
        _NotShadow->setTarget(opNot);
    }
    template <class T>
    void FuzzyFactory<T>::changeThen(fuzzy::Then<T> *opThen) {
        _ThenShadow->setTarget(opThen);
    }



    }
#endif //CLIONTEST_FUZZYFACTORY_H
