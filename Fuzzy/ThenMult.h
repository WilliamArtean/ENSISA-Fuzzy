//
// Created by pierr on 29/01/2020.
//

#ifndef CLIONTEST_THENMULT_H
#define CLIONTEST_THENMULT_H

#include "Operator.h"

namespace fuzzy {

    template <class T>
    class ThenMult : public Then<T> {
    public:
        T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template <class T>
    T ThenMult<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return l->evaluate() * r->evaluate();
    }

}

#endif //CLIONTEST_THENMULT_H
