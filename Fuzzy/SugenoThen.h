//
// Created by pierr on 18/02/2020.
//

#ifndef CLIONTEST_SUGENOTHEN_H
#define CLIONTEST_SUGENOTHEN_H

#include "Operator.h"

namespace fuzzy {

    template <class T>
    class SugenoThen : public Then<T> {
    public:
        T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
        T getPremiseValue();

    private:
        T premiseValue;
    };


    template <class T>
    T SugenoThen<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
        premiseValue = l->evaluate() + r->evaluate();   //??????????????????????????????????????
        return l->evaluate() * r->evaluate();
    }

    template <class T>
    T SugenoThen<T>::getPremiseValue() {
        return premiseValue;
    }
}

#endif //CLIONTEST_SUGENOTHEN_H
