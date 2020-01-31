//
// Created by pierr on 28/01/2020.
//

#ifndef CLIONTEST_OPERATOR_H
#define CLIONTEST_OPERATOR_H

#include "../Core/UnaryExpression.h"
#include "../Core/BinaryExpression.h"

namespace fuzzy {

    template<class T>
    class Is : public core::UnaryExpression<T> {
    public:
        virtual T evaluate(core::Expression<T>*) const=0;
    };

    template<class T>
    class Not : public core::UnaryExpression<T> {
    public:
        virtual T evaluate(core::Expression<T>*) const=0;
    };

    template<class T>
    class And : public core::BinaryExpression<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const=0;
    };

    template<class T>
    class Or : public core::BinaryExpression<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const=0;
    };

    template<class T>
    class Then : public core::BinaryExpression<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const=0;
    };

    template<class T>
    class Agg : public core::BinaryExpression<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const=0;
    };

}

#endif //CLIONTEST_OPERATOR_H
