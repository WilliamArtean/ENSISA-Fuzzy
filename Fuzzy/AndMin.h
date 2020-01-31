//
// Created by pierr on 29/01/2020.
//

#ifndef CLIONTEST_ANDMIN_H
#define CLIONTEST_ANDMIN_H

#include "Operator.h"

namespace fuzzy {

    template <class T>
    class AndMin : public And<T> {
    public:
        T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
    };

    template <class T>
    T AndMin<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return (l->evaluate() <= r->evaluate())? l->evaluate() : r->evaluate();
    }

}

#endif //CLIONTEST_ANDMIN_H
