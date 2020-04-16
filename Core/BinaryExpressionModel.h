#pragma once
#ifndef BINARY_EXPRESSION_MODEL_H
#define BINARY_EXPRESSION_MODEL_H
#include "expression.h"
#include "binaryExpression.h"


namespace core
{
	template<class T>
	class BinaryExpressionModel : public BinaryExpression<T>
	{
	public:
		BinaryExpressionModel() {};
		BinaryExpressionModel(BinaryExpression<T>& ope, Expression<T>& l, Expression<T>& r) : oper(ope), left(l), right(r) {}
		T evaluate() const;
		T evaluate(Expression<T>&,Expression<T>&) const;
	private:
		const BinaryExpression<T> oper;
		const Expression<T> left;
		const Expression<T> right;
	};

	template<class T>
	T BinaryExpressionModel<T>::evaluate() const
	{
		if (left != nullptr && right != nullptr)
		{
			return evaluate(left,right);
		}
		return nullptr;
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate(Expression<T>& l,Expression<T>& r) const
	{
		if (oper != nullptr)
		{
			return oper.evaluate(l,r);
		}
		return nullptr;
	}

}

#endif
