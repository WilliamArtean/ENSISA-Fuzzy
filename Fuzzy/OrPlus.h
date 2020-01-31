//
// Created by pierr on 29/01/2020.
//

#ifndef CLIONTEST_ORPLUS_H
#define CLIONTEST_ORPLUS_H

#include "Operator.h"

namespace fuzzy {

    template <class T>
    class OrPlus : public Or<T> {
    public:
        T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template <class T>
    T OrPlus<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return l->evaluate() + r->evaluate();
    }

}

#endif //CLIONTEST_ORPLUS_H
