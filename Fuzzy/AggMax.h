//
// Created by pierr on 29/01/2020.
//

#ifndef CLIONTEST_AGGMAX_H
#define CLIONTEST_AGGMAX_H

#include "Operator.h"

namespace fuzzy {

    template <class T>
    class AggMax : public Agg<T> {
    public:
        T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template <class T>
    T AggMax<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return (l->evaluate() >= r->evaluate())? l->evaluate() : r->evaluate();
    }

}

#endif //CLIONTEST_AGGMAX_H
