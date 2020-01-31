//
// Created by pierr on 29/01/2020.
//

#ifndef CLIONTEST_ANDMULT_H
#define CLIONTEST_ANDMULT_H

#include "Operator.h"

namespace fuzzy {

    template <class T>
    class AndMult : public And<T> {
    public:
        T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template <class T>
    T AndMult<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return l->evaluate() * r->evaluate();
    }

}

#endif //CLIONTEST_ANDMULT_H
