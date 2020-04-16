#pragma once

#ifndef AGGMAX_H
#define AGGMAX_H

#include "unaryExpression.h"
#include "expression.h"
#include "operatorsUn.h"
using namespace core;

namespace fuzzy {
	template <class T>
	class IsTriangle : public Is<T>
	{
	public:
		IsTriangle(T& mn, T& md, T& mx) : min(mn), mid(md), max(mx) {}
		IsTriangle() : min(0), mid(0), max(0) {}
		T evaluate(Expression<T>&) const;
		const T min;
		const T mid;
		const T max;
	};


	template<class T>
	T IsTriangle<T>::evaluate(Expression<T> & e) const
	{
		//y = ax + b;
		T value = e.evaluate();
		if (value >= min && value <= (max - min) / 2)
		{
			return (max - 3 * min) / 2 * (value + min);
		}
		else if (value >= (max - min) / 2 && value <= max)
		{
			return 1 - (max - 3 * min) / 2 * (value + min);
		}
		else
		{
			return 0;
		}
	}

}

#endif
