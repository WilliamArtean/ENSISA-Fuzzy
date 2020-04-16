#pragma once
#ifndef UNARY_EXPRESSION_H
#define UNARY_EXPRESSION_H
#include "expression.h"

namespace core
{
	template<class T>
	class UnaryExpression : public Expression<T>
	{
	public:
		T evaluate(Expression<T>&) const = 0;
	};

	template<class T>
	T BinaryExpression<T>::evaluate() const
	{
		return evaluate(left, right);
	}
}


#endif