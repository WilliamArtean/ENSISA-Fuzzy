#pragma once

#ifndef NARY_EXPRESSION_H
#define NARY_EXPRESSION_H
#include "expression.h"

namespace core
{
	template<class T>
	class NaryExpression : public Expression<T>
	{
	public:
		T evaluate(Expression[]) const = 0;
	};
}


#endif
