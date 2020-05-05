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
        T getPremiseValue() const;

    private:
        mutable T premiseValue;
    };


    template <class T>
    T SugenoThen<T>::evaluate(core::Expression<T>* _w, core::Expression<T>* _z) const {     //l'opérateur _z est un SugenoConclusion
        premiseValue = _w->evaluate();
        //std::cout << std::endl << "SugenoThen evalue z à : " << _z->evaluate();
        return _z->evaluate();
    }

    template <class T>
    T SugenoThen<T>::getPremiseValue() const {
        //std::cout << std::endl << "VOUS AVEZ APPELE LA METHODE getPremiseValue() DE LA CLASSE SugenoThen<T>";
        //std::cout << std::endl << "SugenoThen evalue w à : " << w->evaluate();
        return premiseValue;
    }
}

#endif //CLIONTEST_SUGENOTHEN_H
