#pragma once
#include "Expression.h"
#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H

namespace core
{
	template <class T>
	class BinaryExpression : public Expression<T>
	{
	public:
		T evaluate(Expression<T>&, Expression<T>&) const =0;
	};

}

#endif
