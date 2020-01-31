//
// Created by pierr on 29/01/2020.
//

#ifndef CLIONTEST_THENMIN_H
#define CLIONTEST_THENMIN_H

#include "Operator.h"

namespace fuzzy {

    template <class T>
    class ThenMin : public Then<T> {
    public:
        T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template <class T>
    T ThenMin<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return (l->evaluate() <= r->evaluate())? l->evaluate() : r->evaluate();
    }

}

#endif //CLIONTEST_THENMIN_H
