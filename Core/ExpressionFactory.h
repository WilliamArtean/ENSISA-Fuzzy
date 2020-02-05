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
        Expression<T> hold(Expression<T>);
        Expression<T> newUnary(UnaryExpression<T> ope, Expression<T> o);
        Expression<T> newBinary(BinaryExpression<T> ope, Expression<T> l, Expression<T> r);
    };

}

#endif //CLIONTEST_EXPRESSIONFACTORY_H
