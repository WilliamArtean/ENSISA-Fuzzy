//
// Created by pierr on 26/01/2020.
//

#ifndef CLIONTEST_ISTRIANGLE_H
#define CLIONTEST_ISTRIANGLE_H

#include "Operator.h"

namespace fuzzy {

    template<class T>
    class IsTriangle : public Is<T> {
    private:
        T *min, *mid, *max;

    public:
        T evaluate(core::Expression<T>* o) const;
    };

    template<class T>
    T IsTriangle<T>::evaluate(core::Expression<T>* o) const {
        if (o->evaluate() <= *min || o->evaluate() >= *max) {
            return 0;
        } else if (o->evaluate() <= mid) {
            return (()/())
        }
    }

}

#endif //CLIONTEST_ISTRIANGLE_H
