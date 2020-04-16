#pragma once
#ifndef NARY_EXPRESSION_MODEL_H
#define NARY_EXPRESSION_MODEL_H
#include "expression.h"
#include "naryExpression.h"


namespace core
{
	template<class T>
	class NaryExpressionModel : public NaryExpression<T>
	{
	public:
		NaryExpressionModel() {};
		NaryExpressionModel(NaryExpression& ope, Expression& [] o) : oper(ope), operands(o) {}
		T evaluate() const;
		T evaluate(Expression*) const;
	private:
		const UnaryExpression oper;
		const Expression[] operands;
	};

	template<class T>
	T NaryExpressionModel<T>::evaluate() const
	{
		if (operand != null)
		{
			return evaluate(operands);
		}
		return null;
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate(Expression<T>* o) const
	{
		if (oper != null)
		{
			return operator.evaluate(o);
		}
		return null;
	}

}

#endif
