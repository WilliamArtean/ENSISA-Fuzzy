//
// Created by CHICHAOUI Omar on 03/05/2020.
//

#ifndef CLIONTEST_AGG_H
#define CLIONTEST_AGG_H

#include "../Core/BinaryExpression.h"

namespace fuzzy
{
    template <class T>
    class Agg : public core::BinaryExpression<T>
    {
    public:
        virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const = 0;
    };
}
#endif //CLIONTEST_AGG_H
