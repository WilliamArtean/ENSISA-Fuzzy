//
// Created by pierr on 26/01/2020.
//

#ifndef CLIONTEST_UNARYEXPRESSIONMODEL_H
#define CLIONTEST_UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"

namespace core {

    template<class T>
    class UnaryExpressionModel : public UnaryExpression<T>, Expression<T> {
    private:
        UnaryExpression<T> *expressionOperator;
        Expression<T> *expressionOperand;

    public:
        UnaryExpressionModel();
        UnaryExpressionModel(UnaryExpression<T>* operat, Expression<T>* operand);     //operator THEN operand
        virtual ~UnaryExpressionModel() {};

        T evaluate() const;
        T evaluate(Expression<T>* o) const;
    };

    template <class T>
    UnaryExpressionModel<T>::UnaryExpressionModel() :
    expressionOperand(NULL), expressionOperator(NULL)
    {}

    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* operat, Expression<T>* operand) :
            expressionOperand(operand), expressionOperator(operat) {
    }


    template<class T>
    T UnaryExpressionModel<T>::evaluate() const {
        if (expressionOperand != NULL) {
            return evaluate(expressionOperand);
        }
        return NULL;
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T>* o) const {
        if (expressionOperator != NULL) {
            return expressionOperator->evaluate(o);
        }
        return NULL;
    }

}

#endif //CLIONTEST_UNARYEXPRESSIONMODEL_H
