//
// Created by pierr on 26/01/2020.
//

#ifndef CLIONTEST_BINARYEXPRESSIONMODEL_H
#define CLIONTEST_BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"

namespace core {

    template<class T>
    class BinaryExpressionModel : public BinaryExpression<T>, Expression<T> {     //Héritage multiple ??
    private:
        BinaryExpression<T>* expressionOperator;
        Expression<T>* leftOperand;
        Expression<T>* rightOperand;

    public:
        BinaryExpressionModel();
        BinaryExpressionModel(BinaryExpression<T> *operat, Expression<T> *left, Expression<T> *right);     //Operator THEN left operand, then right operand
        virtual ~BinaryExpressionModel() {};


        T evaluate() const;
        T evaluate(Expression<T>* l, Expression<T>* r) const;
    };

    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel() :
            expressionOperator(NULL), leftOperand(NULL), rightOperand(NULL)
    {
    }

    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T> *operat, Expression<T> *left, Expression<T> *right) :
            expressionOperator(operat), leftOperand(left), rightOperand(right) {
    }


    template<class T>
    T BinaryExpressionModel<T>::evaluate() const {
        if (leftOperand != NULL && rightOperand != NULL) {
            return evaluate(leftOperand, rightOperand);
        }
        return NULL;
    }

    template<class T>
    T BinaryExpressionModel<T>::evaluate(Expression<T>* l, Expression<T>* r) const {
        if (expressionOperator != NULL) {
            return expressionOperator->evaluate(l, r);
        }
        return NULL;
    }

}

#endif //CLIONTEST_BINARYEXPRESSIONMODEL_H
