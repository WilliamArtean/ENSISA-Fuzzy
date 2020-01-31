//
// Created by pierr on 26/01/2020.
//

#ifndef CLIONTEST_VALUEMODEL_H
#define CLIONTEST_VALUEMODEL_H

#include "Expression.h"

namespace core {

    template<class T>
    class ValueModel : public Expression<T> {
    private:
        T value;

    public:
        ValueModel();
        ValueModel(const T &);
        virtual ~ValueModel() {};

        T evaluate() const;
        void setValue(const T&);
    };

    template<class T>
    ValueModel<T>::ValueModel() :
            value(v) {
    }

    template<class T>
    ValueModel<T>::ValueModel(const T& v) :
            value(v) {
    }


    template<class T>
    T ValueModel<T>::evaluate() const {
        return value;
    }

    template<class T>
    void ValueModel<T>::setValue(const T& v) {
        value = v;
    }

}

#endif //CLIONTEST_VALUEMODEL_H
