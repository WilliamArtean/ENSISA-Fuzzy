#pragma once
#pragma once

#ifndef UNARY_SHADOW_EXPRESSION_H
#define UNARY_SHADOW_EXPRESSION_H
#include "unaryExpression.h"

namespace core
{
	template<class T>
	class UnaryShadowExpression : public UnaryExpression<T>
	{
	public:
		UnaryShadowExpression(UnaryExpression& e) : target(e) {}
		T evaluate(Expression&) const = 0;
	private:
		const UnaryExpression target;
	};

	template<class T>
	T UnaryShadowExpression<T>::evaluate(Expression<T>& o) const
	{
		if (target != null)
		{
			return target.evaluate(o);
		}
		return null;
	}
}


#endif
