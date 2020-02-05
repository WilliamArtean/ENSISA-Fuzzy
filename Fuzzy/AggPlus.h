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
        T somme = l->evaluate() + r->evaluate();
        if (somme <= 1) {
            return somme;
        } else {
            return 1;
        }
    }

}

#endif //CLIONTEST_AGGPLUS_H
