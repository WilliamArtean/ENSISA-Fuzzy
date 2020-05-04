//
// Created by coscoy on 05/02/2020.
//

#ifndef CLIONTEST_MAMDANIDEFUZZ_H
#define CLIONTEST_MAMDANIDEFUZZ_H

#include <vector>
#include <ostream>
#include "../Core/BinaryExpressionModel.h"
#include "../Core/BinaryExpression.h"
#include "../Core/ValueModel.h"


namespace fuzzy {
    template<class T>
    class MamdaniDefuzz : public core::BinaryExpression<T> {
    public:
        MamdaniDefuzz();
        MamdaniDefuzz(T min, T max, T step);
        T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;

        typedef std::pair<std::vector<T>,std::vector<T> > Shape;
        virtual T Defuzz(Shape shape) const = 0;

        static Shape BuildShape(const T& min, const T& max, const T& step, core::ValueModel<T>* value, core::BinaryExpression<T>* expression);
        static std::ostream& PrintShape(std::ostream&, const Shape& s);

    protected:
        const T& min;
    public:
        const T &getMin() const;

        const T &getMax() const;

        const T &getStep() const;

    protected:
        const T& max;
        const T& step;
    };
    template<class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(): min(0), max(0), step(0) {}

    template<class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(T min, T max, T step): min(min), max(max), step(step){}

    template<class T>
    std::ostream &MamdaniDefuzz<T>::PrintShape(std::ostream & os, const Shape &s) {
        os << '[';
        typename std::vector<T>::const_iterator it= s.first.begin();
        for(; it!=s.first.end(); ++it)
            os << *it << ' ';
        os << ']' << std::endl << '[';
        it = s.second.begin();
        for(; it!=s.second.end(); ++it)
            os << *it << ' ';
        os << ']';
        return os;
    }


    template<class T>
    typename MamdaniDefuzz<T>::Shape
    MamdaniDefuzz<T>::BuildShape(const T &min, const T &max, const T &step, core::ValueModel<T>* value,
                                 core::BinaryExpression<T>* expression) {
        std::vector<T> x, y;
        for (T i= min ;i <= max ;i += step) {
            value->setValue(i);
            y.push_back(((core::BinaryExpressionModel<T>*)expression)->evaluate());
            x.push_back(value->evaluate());
        }
        return Shape(x,y);
    }


    template<class T>
    T MamdaniDefuzz<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
        return 0;
    }


    template<class T>
    const T &MamdaniDefuzz<T>::getMin() const {
        return min;
    }

    template<class T>
    const T &MamdaniDefuzz<T>::getMax() const {
        return max;
    }

    template<class T>
    const T &MamdaniDefuzz<T>::getStep() const {
        return step;
    }

}

#endif