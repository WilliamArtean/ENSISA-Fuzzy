#pragma once
#ifndef EXPRESSION_FACTORY_H
#define EXPRESSION_FACTORY_H
#include "expression.h"
#include "unaryExpression.h"
#include "unaryExpressionModel.h"
#include "binaryExpressionModel.h"
#include <vector>

namespace core
{
	template <class T>
	class ExpressionFactory
	{
	public:
		virtual Expression<T> Hold(Expression<T>&);
		virtual Expression<T> newUnary(UnaryExpression<T>&, Expression<T>&);
		virtual Expression<T> newBinary(BinaryExpression<T>&,Expression<T>&, Expression<T>&);
	private:
		std::vector<Expression<T>> memory;
	};

	template<class T>
	Expression<T> ExpressionFactory<T>::Hold(Expression<T>& e)
	{
		memory.push_back(e);
		return e;
	}

	template<class T>
	Expression<T> ExpressionFactory<T>::newUnary(UnaryExpression<T>& op, Expression<T>& o)
	{
		return Hold( new UnaryExpressionModel<T>(op, o));
	}

	template<class T>
	Expression<T> ExpressionFactory<T>::newBinary(BinaryExpression<T>& op, Expression<T>& l, Expression<T>& r)
	{
		return Hold(new BinaryExpressionModel<T>(op, l,r));
	}
}

#endif
