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
		MamdaniDefuzz(core::ValueModel<T>* value, core::BinaryExpression<T>* expression, T min, T max, T step);
        virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
		virtual T evaluate() const;

        typedef std::pair<std::vector<T>,std::vector<T> > Shape;
        virtual T Defuzz(Shape shape) const = 0;

        static Shape BuildShape(T min, T max, T step, core::ValueModel<T>* value, core::BinaryExpression<T>* expression);
        static std::ostream& PrintShape(std::ostream&, const Shape& s);

    public:
        const T &getMin() const;

        const T &getMax() const;

        const T &getStep() const;

		core::ValueModel<T> *getValue() const;

		core::BinaryExpression <T> *getExpression() const;

		void setMin(T);

		void setMax(T);

		void setStep(T);

		void setValue(core::ValueModel<T>*);

		void setExpression(core::BinaryExpression<T>*);

    protected:
        T min;
        T max;
        T step;
		core::BinaryExpression<T>* expression;
		core::ValueModel<T>* value;
    };
	
    template<class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(): min(0), max(0), step(0){}

    template<class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(core::ValueModel<T>* value, core::BinaryExpression<T>* expression,T min, T max, T step):value(value), expression(expression), min(min), max(max), step(step){}

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
    MamdaniDefuzz<T>::BuildShape(T min, T max, T step, core::ValueModel<T>* value, core::BinaryExpression<T>* expression) {
        std::vector<T> x, y;
        for (T i= min ;i <= max ;i += step) {
            value->setValue(i);
            y.push_back(((core::BinaryExpressionModel<T>*)expression)->evaluate());
            x.push_back(i);
        }
        return Shape(x,y);
    }


    template<class T>
    T MamdaniDefuzz<T>::evaluate(core::Expression<T>* l, core::Expression<T>* r) const {
		Shape s = this->BuildShape(this->min, this->max, this->step, (core::ValueModel<T>*) r,(core::BinaryExpressionModel<T>*) l);
		return Defuzz(s);
	}

	template<class T>
	T MamdaniDefuzz<T>::evaluate() const {
		Shape s = this->BuildShape(this->min, this->max, this->step, value, expression);
		return this->Defuzz(s);
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

	template<class T>
	core::ValueModel<T> *MamdaniDefuzz<T>::getValue() const {
		return value;
	}

	template<class T>
	core::BinaryExpression<T> *MamdaniDefuzz<T>::getExpression() const {
		return expression;
	}
	
	template<class T>
	void MamdaniDefuzz<T>::setMin(T m) {
		min = m;
	}

	template<class T>
	void MamdaniDefuzz<T>::setMax(T m) {
		max = m;
	}

	template<class T>
	void MamdaniDefuzz<T>::setStep(T s) {
		step = s;
	}

	template<class T>
	void MamdaniDefuzz<T>::setValue(core::ValueModel<T> * v) {
		value = v;
	}

	template<class T>
	void MamdaniDefuzz<T>::setExpression(core::BinaryExpression<T> * e) {
		expression = e;
	}

}

#endif