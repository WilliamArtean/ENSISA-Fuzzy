//
// Created by CHICHAOUI Omar on 05/02/2020.
//

#ifndef CLIONTEST_FUZZYFACTORY_H
#define CLIONTEST_FUZZYFACTORY_H

#include "../Core/ExpressionFactory.h"
#include "../Core/BinaryShadowExpression.h"
#include "../Core/UnaryShadowExpression.h"
#include "../Core/Expression.h"
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

        FuzzyFactory(NotMinus1<T>* opNot, AndMin<T> opAnd, OrMax<T> opOr,ThenMin<T>* opThen,OrMax<T>* opOr1,CogDefuzz<T> *opDefuzz);
        FuzzyFactory(const FuzzyFactory<T>& o);
        virtual ~FuzzyFactory();
        core::Expression<T> newAnd(core::Expression<T>* l , core::Expression<T>* r );
        core::Expression<T> newThen(core::Expression<T>* l , core::Expression<T>* r );
        core::Expression<T> newAgg(core::Expression<T>* l , core::Expression<T>* r );
        core::Expression<T> newDefuzz(core::Expression<T>* l , core::Expression<T>* r );
        core::Expression<T> newNote(core::Expression<T>* o);
        core::Expression<T> newIs(fuzzy::Is<T>* s,core::Expression<T>* o);




    };
    }
#endif //CLIONTEST_FUZZYFACTORY_H
