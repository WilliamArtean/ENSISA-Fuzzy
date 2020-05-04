//
// Created by pierr on 26/01/2020.
//

#ifndef CLIONTEST_BINARYEXPRESSION_H
#define CLIONTEST_BINARYEXPRESSION_H

#include "Expression.h"

namespace core {

    template<class T>
    class BinaryExpression {
    public:
        virtual T evaluate(Expression<T>* l, Expression<T>* r) const = 0;
        virtual T getPremiseValue() const;
    };


    template <class T>
    T BinaryExpression<T>::getPremiseValue() const {
        //std::cout << std::endl << "VOUS AVEZ APPELE LA METHODE getPremiseValue() DE LA CLASSE BinaryExpression<T>";
        return 0;
    }
}

#endif //CLIONTEST_BINARYEXPRESSION_H
