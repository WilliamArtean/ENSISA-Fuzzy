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

    template <class T>
    T SugenoConclusion<T>::evaluate(std::vector<core::Expression<T>> *operands) const {
        if (coeffs->size() != operands->size() + 1) {
            return -1;
        }

        T result;
        for (int i = 0; i < operands->size(); i++) {
            result += operands[i]->evaluate() * coeffs[i];
        }

        result += coeffs[++i];
        return result;
    }

}

#endif //CLIONTEST_SUGENOCONCLUSION_H
