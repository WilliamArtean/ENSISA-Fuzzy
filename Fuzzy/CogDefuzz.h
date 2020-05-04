//
// Created by coscoy on 05/02/2020.
//

#ifndef CLIONTEST_COGDEFUZZ_H
#define CLIONTEST_COGDEFUZZ_H

#include "MamdaniDefuzz.h"

namespace fuzzy {
    template<class T>
class CogDefuzz : public MamdaniDefuzz<T> {
public:
    CogDefuzz(core::ValueModel<T>* value, core::BinaryExpression<T>* expression, T min, T max, T step);
    CogDefuzz();

    typedef std::pair<std::vector<T>,std::vector<T> > Shape;
    virtual T Defuzz(Shape shape) const;
    virtual T Evaluate() const;
private:
    core::ValueModel<T>* value;
public:
    core::ValueModel<T> *getValue() const;

    core::BinaryExpression <T> *getExpression() const;

private:
    core::BinaryExpression<T>* expression;
};

    template <class T>
    CogDefuzz<T>::CogDefuzz() {
    }

    template <class T>
    CogDefuzz<T>::CogDefuzz(core::ValueModel<T>* value, core::BinaryExpression<T>* expression, T min, T max, T step):value(value), expression(expression), MamdaniDefuzz<T>(min,max,step) {
    }

    template<class T>
    T CogDefuzz<T>::Defuzz(Shape shape) const {
        T value = 0;
        unsigned int i = 0;
        typename std::vector<T>::const_iterator itx= shape.first.begin();
        typename std::vector<T>::const_iterator ity= shape.second.begin();
        for (; itx!=shape.first.end(); ++itx) {
            value += (*ity);
            ++ity;
            i += 1;
        }
        return value/i;
    }

    template <class T>
    T CogDefuzz<T>::Evaluate() const {
        Shape s = this->BuildShape(this->min, this->max, this->step, value , expression);
        return Defuzz(s);
    }

    template<class T>
    core::ValueModel<T> *CogDefuzz<T>::getValue() const {
        return value;
    }

    template<class T>
    core::BinaryExpression<T> *CogDefuzz<T>::getExpression() const {
        return expression;
    }
}

#endif