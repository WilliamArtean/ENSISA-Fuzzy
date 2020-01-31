//
// Created by pierr on 26/01/2020.
//

#ifndef CLIONTEST_NOTMINUS1_H
#define CLIONTEST_NOTMINUS1_H

#include "Operator.h"

namespace fuzzy {

    template<class T>
    class NotMinus1 : public Not<T> {
    public:
        T evaluate(core::Expression<T>* o) const;
    };

    template<class T>
    T NotMinus1<T>::evaluate(core::Expression<T>* o) const {
        return 1-(o->evaluate());
    }

}

#endif //CLIONTEST_NOTMINUS1_H
