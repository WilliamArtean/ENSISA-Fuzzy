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
        SugenoConclusion();
        SugenoConclusion(std::vector<T> _coeffs);
        virtual ~SugenoConclusion() {};

        T evaluate(std::vector<core::Expression<T>*> operands) const;

    private:
        std::vector<T> coeffs;
    };

    template <class T>
    SugenoConclusion<T>::SugenoConclusion() :
        coeffs(NULL)
    {
    }

    template <class T>
    SugenoConclusion<T>::SugenoConclusion(vector<T> _coeffs) :
        coeffs(_coeffs)
    {
    }


    template <class T>
    T SugenoConclusion<T>::evaluate(std::vector<core::Expression<T>*> operands) const {
        if (coeffs.size() != operands.size() + 1) {
            return -1;
        }

        T result = 0;
        for (int i = 0; i < operands.size(); i++) {
            result += coeffs[i] * operands[i]->evaluate();
        }

        result += coeffs.back();

        return result;
    }
}

#endif //CLIONTEST_SUGENOCONCLUSION_H
