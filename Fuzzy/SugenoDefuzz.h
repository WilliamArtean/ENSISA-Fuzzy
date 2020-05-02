//
// Created by pierr on 18/02/2020.
//

#ifndef CLIONTEST_SUGENODEFUZZ_H
#define CLIONTEST_SUGENODEFUZZ_H

#include <vector>

#include "../Core/NaryExpression.h"

namespace fuzzy {

    template <class T>
    class SugenoDefuzz : public core::NaryExpression<T> {
    public:
        T evaluate(std::vector<core::Expression<T>* > operands) const;
    };

    template <class T>
    T SugenoDefuzz<T>::evaluate(std::vector<core::Expression<T>* > operands) const {    //collection de SugenoThen ?
        T numerator, denominator;

        for (int i; i < operands.size(); i++) {
            numerator += operands[i]->evaluate() * operands[i]->getPremiseValue();
            denominator += operands[i]->getPremiseValue();
        }

        return numerator / denominator;
    }

}

#endif //CLIONTEST_SUGENODEFUZZ_H
