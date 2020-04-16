#pragma once

#pragma once

#ifndef BINARY_SHADOW_EXPRESSION_H
#define BINARY_SHADOW_EXPRESSION_H
#include "binaryExpression.h"

namespace core
{
	template<class T>
	class BinaryShadowExpression : public BinaryExpression<T>
	{
	public:
		BinaryShadowExpression(BinaryExpression& e) : target(e) {}
		T evaluate(Expression&,Expression&) const = 0;
	private:
		const BinaryExpression target;
	};

	template<class T>
	T BinaryShadowExpression<T>::evaluate(Expression<T>& r,Expression<T>& l) const
	{
		if (target != null)
		{
			return target.evaluate(r,l);
		}
		return null;
	}
}


#endif
