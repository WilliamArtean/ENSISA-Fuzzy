#pragma once

#ifndef NARY_SHADOW_EXPRESSION_H
#define NARY_SHADOW_EXPRESSION_H
#include "naryExpression.h"

namespace core
{
	template<class T>
	class NaryShadowExpression : public NaryExpression<T>
	{
	public:
		NaryShadowExpression(NaryExpression& e): target(e) {}
		T evaluate(Expression[]) const = 0;
	private:
		const NaryExpression target;
	};

	template<class T>
	T NaryShadowExpression<T>::evaluate(Expression<T> * operands) const
	{
		if (target != null)
		{
			return target.evaluate(operands);
		}
		return null;
	}
}


#endif