#pragma once
#ifndef ANDMIN_H
#define ANDMIN_H

#include "binaryExpression.h"
#include "expression.h"
#include "operatorsBi.h"
using namespace core;

namespace fuzzy {
	template <class T>
	class AndMin : public And<T>
	{
	public:
		T evaluate(Expression<T>&, Expression<T>&) const;
	};


	template<class T>
	T AndMin<T>::evaluate(Expression<T> & l, Expression<T> & r) const
	{
		T left = l.evaluate();
		T right = r.evaluate();
		return (left <= right) ? left : right;
	}

}

#endif

