#pragma once
#ifndef ANDMULT_H
#define ANDMULT_H

#include "binaryExpression.h"
#include "expression.h"
#include "operatorsBi.h"
using namespace core;

namespace fuzzy {
	template <class T>
	class AndMult : public And<T>
	{
	public:
		T evaluate(Expression<T>&, Expression<T>&) const;
	};


	template<class T>
	T AndMult<T>::evaluate(Expression<T> & l, Expression<T> & r) const
	{
		T left = l.evaluate();
		T right = r.evaluate();
		return (left * right);
	}

}

#endif
