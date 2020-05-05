//
// Created by pierr on 26/01/2020.
//

#ifndef CLIONTEST_BINARYEXPRESSION_H
#define CLIONTEST_BINARYEXPRESSION_H

#include "Expression.h"

namespace core {

    template<class T>
    class BinaryExpression {
    public:
        virtual T evaluate(Expression<T>* l, Expression<T>* r) const = 0;
    };


}

#endif //CLIONTEST_BINARYEXPRESSION_H
