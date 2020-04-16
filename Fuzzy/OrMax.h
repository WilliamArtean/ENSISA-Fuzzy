#pragma once
#ifndef ORMAX_H
#define ORMAX_H

#include "binaryExpression.h"
#include "expression.h"
#include "operatorsBi.h"
using namespace core;

namespace fuzzy {
	template <class T>
	class OrMax : public Or<T>
	{
	public:
		T evaluate(Expression<T>&, Expression<T>&) const;
	};


	template<class T>
	T OrMax<T>::evaluate(Expression<T> & l, Expression<T> & r) const
	{
		T left = l.evaluate();
		T right = r.evaluate();
		return (left >= right) ? left : right;
	}

}

#endif
