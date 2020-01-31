//
// Created by pierr on 28/01/2020.
//

#ifndef CLIONTEST_ORMAX_H
#define CLIONTEST_ORMAX_H

#include "Operator.h"

namespace fuzzy {

    template <class T>
    class OrMax : public Or<T> {
    public:
        T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template <class T>
    T OrMax<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return (l->evaluate() >= r->evaluate())? l->evaluate() : r->evaluate();
    }

}

#endif //CLIONTEST_ORMAX_H
