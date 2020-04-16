#pragma once
#ifndef UNARY_EXPRESSION_MODEL_H
#define UNARY_EXPRESSION_MODEL_H
#include "expression.h"
#include "unaryExpression.h"


namespace core
{
	template<class T>
	class UnaryExpressionModel : public UnaryExpression<T>
	{
	public:
		UnaryExpressionModel() {};
		UnaryExpressionModel(UnaryExpression<T>& ope, Expression<T>& o) : oper(ope), operand(o) {}
		T evaluate() const;
		T evaluate(Expression<T>&) const;
	private:
		const UnaryExpression<T> oper;
		const Expression<T> operand;
	};

	template<class T>
	T UnaryExpressionModel<T>::evaluate() const
	{
		if (operand != nullptr)
		{
			return evaluate(operand);
		}
		return nullptr;
	}

	template<class T>
	T UnaryExpressionModel<T>::evaluate(Expression<T>& o) const
	{
		if (oper != nullptr)
		{
			return oper.evaluate(o);
		}
		return nullptr;
	}

}

#endif