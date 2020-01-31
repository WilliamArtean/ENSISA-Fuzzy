//
// Created by pierr on 26/01/2020.
//

#ifndef CLIONTEST_UNARYEXPRESSION_H
#define CLIONTEST_UNARYEXPRESSION_H

#include "Expression.h"

namespace core {

    template<class T>
    class UnaryExpression {
    public:
        virtual T evaluate(Expression<T>* o) const = 0;
    };

}

#endif //CLIONTEST_UNARYEXPRESSION_H
