//
// Created by pierr on 18/02/2020.
//

#ifndef CLIONTEST_SUGENOCONCLUSION_H
#define CLIONTEST_SUGENOCONCLUSION_H

#include <vector>

#include "../Core/NaryExpression.h"

namespace fuzzy {

    template <class T>
    class SugenoConclusion : public core::NaryExpression<T> {
    public:
        T evaluate(std::vector<core::Expression<T>> *operands) const;

    private:
        std::vector<T> *coeffs;
    };



}

#endif //CLIONTEST_SUGENOCONCLUSION_H
