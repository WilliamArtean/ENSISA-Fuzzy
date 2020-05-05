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
        //T evaluate(std::vector<core::BinaryExpressionModel<T>* > operands) const;
    };

/*
    template <class T>
    T SugenoDefuzz<T>::evaluate(std::vector<core::Expression<T>* > operands) const {
        T numerator = 0;
        T denominator = 0;

        for (int i= 0; i < operands.size(); i++) {
            numerator += operands[i]->evaluate();
        }

        return numerator;
    }
*/
    template <class T>
    T SugenoDefuzz<T>::evaluate(std::vector<core::Expression<T>* > operands) const {
        T numerator = 0;
        T denominator = 0;

        for (int i= 0; i < operands.size(); i++) {
            T z = operands[i]->evaluate();
            T w = operands[i]->getPremiseValue();
            numerator += w * z;
            denominator += w;
        }

        if (denominator == 0) {
            std::cout << std::endl << "DIVISION PAR ZERO";
        }
        //std::cout << std::endl << "numerator =" << numerator;
        //std::cout << std::endl << "denominator =" << denominator;
        return numerator / denominator;
    }

}

#endif //CLIONTEST_SUGENODEFUZZ_H
