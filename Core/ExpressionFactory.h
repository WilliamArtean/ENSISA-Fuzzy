//
// Created by pierr on 05/02/2020.
//

#ifndef CLIONTEST_EXPRESSIONFACTORY_H
#define CLIONTEST_EXPRESSIONFACTORY_H

#include <vector>

#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"

namespace core {

    template <class T>
    class ExpressionFactory : public Expression<T> {
    private:
        std::vector<Expression<T>*> memory;
    public:
        Expression<T> hold(Expression<T>*);
        Expression<T> newUnary(UnaryExpression<T> *ope, Expression<T> *o);
        Expression<T> newBinary(BinaryExpression<T> *ope, Expression<T> *l, Expression<T> *r);
    };

    template <class T>
    Expression<T> ExpressionFactory<T>::hold(Expression<T> *o) {
        memory.push_back(o);
    }

    template <class T>
    Expression<T> ExpressionFactory<T>::newUnary(UnaryExpression<T> *ope, Expression<T> *o) {
        UnaryExpressionModel<T> uem = new UnaryExpressionModel<T>(ope, o);
        hold(uem);
        return uem;
    }

    template <class T>
    Expression<T> ExpressionFactory<T>::newBinary(BinaryExpression<T> *ope, Expression<T> *l, Expression<T> *r) {
        BinaryExpressionModel<T> bem = new BinaryExpressionModel<T>(ope, l, r);
        hold(bem);
        return bem;
    }

}

#endif //CLIONTEST_EXPRESSIONFACTORY_H
