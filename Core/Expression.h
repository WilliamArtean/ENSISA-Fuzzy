//
// Created by pierr on 26/01/2020.
//

#ifndef CLIONTEST_EXPRESSION_H
#define CLIONTEST_EXPRESSION_H

namespace core {

    template<class T>
    class Expression {
    public:
        virtual T evaluate() const = 0;
        virtual T getPremiseValue() const;
    };

    template <class T>
    T Expression<T>::getPremiseValue() const {
        //std::cout << std::endl << "VOUS AVEZ APPELE LA METHODE getPremiseValue() DE LA CLASSE Expression<T>";
        return 0;
    }
}

#endif //CLIONTEST_EXPRESSION_H
