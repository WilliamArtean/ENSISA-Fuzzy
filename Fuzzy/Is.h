//
// Created by CHICHAOUI Omar on 03/05/2020.
//

#ifndef CLIONTEST_IS_H
#define CLIONTEST_IS_H

#include "../Core/UnaryExpression.h"

namespace fuzzy
{
    template <class T>
class Is : public core::UnaryExpression<T>
{
public:
    virtual T evaluate(core::Expression<T>* operand) const = 0;
};
}
#endif //CLIONTEST_IS_H
