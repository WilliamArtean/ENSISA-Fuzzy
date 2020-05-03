//
// Created by CHICHAOUI Omar on 03/05/2020.
//

#ifndef CLIONTEST_NOT_H
#define CLIONTEST_NOT_H

#include "../Core/UnaryExpression.h"

namespace fuzzy {
    template <class T>
class Not : public core::UnaryExpression<T>
{
public:
    virtual T evaluate(core::Expression<T>* operand) const = 0;
};
}
#endif //CLIONTEST_NOT_H
