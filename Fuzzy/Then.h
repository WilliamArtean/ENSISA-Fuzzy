//
// Created by CHICHAOUI Omar on 03/05/2020.
//

#ifndef CLIONTEST_THEN_H
#define CLIONTEST_THEN_H

#include "../Core/BinaryExpression.h"

namespace fuzzy{
    template <class T>
class Then : public core::BinaryExpression<T>
{
public:
    virtual T evaluate(core::Expression<T>* cond,core::Expression<T>* result) const = 0;
};
}
#endif //CLIONTEST_THEN_H
