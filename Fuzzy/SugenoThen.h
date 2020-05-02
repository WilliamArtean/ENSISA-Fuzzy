//
// Created by pierr on 18/02/2020.
//

#ifndef CLIONTEST_SUGENOTHEN_H
#define CLIONTEST_SUGENOTHEN_H

#include "Operator.h"

namespace fuzzy {

    template <class T>
    class SugenoThen : public Then<T> {
    public:
        T evaluate(core::Expression<T>* _w, core::Expression<T>* _z) const;
        T getPremiseValue();

    private:
        T premiseValue;
    };


    template <class T>
    T SugenoThen<T>::evaluate(core::Expression<T>* _w, core::Expression<T>* _z) const {     //l'opérateur _z est un SugenoConclusion
        premiseValue = _w->evaluate();
        return _w->evaluate() * _z->evaluate();   //Combinaison linéaire ?
    }

    template <class T>
    T SugenoThen<T>::getPremiseValue() {
        return premiseValue;
    }
}

#endif //CLIONTEST_SUGENOTHEN_H
