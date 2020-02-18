//
// Created by pierr on 18/02/2020.
//

#ifndef CLIONTEST_NARYEXPRESSION_H
#define CLIONTEST_NARYEXPRESSION_H
#include <vector>

#include "Expression.h"

namespace core {

    template <class T>
    class NaryExpression {
    public :
        virtual T evaluate(std::vector<Expression<T>> *operands) const = 0;
    };

}

#endif //CLIONTEST_NARYEXPRESSION_H
