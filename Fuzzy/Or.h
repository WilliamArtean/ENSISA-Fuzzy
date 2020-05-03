//
// Created by CHICHAOUI Omar on 03/05/2020.
//

#ifndef CLIONTEST_OR_H
#define CLIONTEST_OR_H

#include "../Core/BinaryExpression.h"

namespace fuzzy
{
    template <class T>
class Or: public core::BinaryExpression<T>
{
public:
    virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const = 0;
};
}
#endif //CLIONTEST_OR_H
