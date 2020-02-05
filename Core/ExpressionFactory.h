//
// Created by CHICHAOUI Omar on 05/02/2020.
//

#ifndef CLIONTEST_EXPRESSIONFACTORY_H
#define CLIONTEST_EXPRESSIONFACTORY_H

#include <vector>

#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"

namespace core {
    template <class T>
    class ExpressionFactory
    {
    private:
        std::vector<Expression<T>*> memory;
    public:
        ExpressionFactory();
        ~ExpressionFactory();
        Expression<T> hold(Expression<T>* expression);
        Expression<T> newUnary(UnaryExpression<T>* ope , Expression<T>* o );
        Expression<T> newBinary(BinaryExpression<T>* ope, Expression<T>* l , Expression<T>* r);
    };

    template<class T>
    ExpressionFactory<T>::ExpressionFactory() {}

    template<class T>
    ExpressionFactory<T>::~ExpressionFactory() {}

    template <class T  >
    Expression<T> ExpressionFactory<T>::newUnary(UnaryExpression<T> *ope, Expression<T> *o)
    {
        return this->hold( new UnaryExpressionModel<T>(ope,o));
    }

    template <class T>
    Expression<T> ExpressionFactory<T>::newBinary(BinaryExpression<T> *ope, Expression<T> *l, Expression<T> *r)
    {
        return this->hold(new BinaryExpressionModel<T>(ope,l,r));
    }

    template <class T>
    Expression<T> ExpressionFactory<T>::hold(core::Expression<T> *expression)
    {
        this->memory.push_back(expression);
        return expression;
    }
}

#endif //CLIONTEST_EXPRESSIONFACTORY_H
