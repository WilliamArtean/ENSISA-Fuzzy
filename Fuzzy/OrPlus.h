#pragma once
#ifndef ORPLUS_H
#define ORPLUS_H

#include "binaryExpression.h"
#include "expression.h"
#include "operatorsBi.h"
using namespace core;

namespace fuzzy {
	template <class T>
	class OrPlus : public Or<T>
	{
	public:
		T evaluate(Expression<T>&, Expression<T>&) const;
	};


	template<class T>
	T OrPlus<T>::evaluate(Expression<T> & l, Expression<T> & r) const
	{
		T left = l.evaluate();
		T right = r.evaluate();
		return (left + right);
	}

}

#endif