//
// Created by pierr on 29/01/2020.
//

#ifndef CLIONTEST_AGGPLUS_H
#define CLIONTEST_AGGPLUS_H

#include "Operator.h"

namespace fuzzy {

    template <class T>
    class AggPlus : public Agg<T> {
    public:
        T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template <class T>
    T AggPlus<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return l->evaluate() + r->evaluate();
    }

}

#endif //CLIONTEST_AGGPLUS_H
