//
// Created by pierr on 18/02/2020.
//

#ifndef CLIONTEST_NARYEXPRESSIONMODEL_H
#define CLIONTEST_NARYEXPRESSIONMODEL_H

#include "NaryExpression.h"

namespace core {

    template <class T>
    class NaryExpressionModel : public NaryExpression<T>, Expression<T> {
    public:
        NaryExpressionModel();
        NaryExpressionModel(NaryExpression<T> *_operat, std::vector<Expression<T>> *_operands);
        virtual ~NaryExpressionModel() {};

        T evaluate() const;
        T evaluate(std::vector<Expression<T>> *operands) const;

    private:
        std::vector<Expression<T>> *expressionOperands;
        NaryExpression<T> *expressonOperator;
    };


    template <class T>
    NaryExpressionModel<T>::NaryExpressionModel() :
            expressonOperator(NULL), expressionOperands(NULL)
    {
    }

    template <class T>
    NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T> *_operat, std::vector<Expression<T>> *_operands) :
    expressonOperator(_operat), expressionOperands(_operands)
    {}


    template <class T>
    T NaryExpressionModel<T>::evaluate() const {
        if (expressionOperands != NULL) {
            return evaluate(expressionOperands);
        }
        return NULL;
    }

    template <class T>
    T NaryExpressionModel<T>::evaluate(std::vector<Expression<T> > *operands) const {
        if (expressonOperator != NULL) {
            return expressonOperator->evaluate(operands);
        }
        return NULL;
    }

}

#endif //CLIONTEST_NARYEXPRESSIONMODEL_H
