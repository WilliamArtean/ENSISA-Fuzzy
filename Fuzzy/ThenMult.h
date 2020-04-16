#pragma once

#ifndef THENMULT_H
#define THENMULT_H

#include "binaryExpression.h"
#include "expression.h"
#include "operatorsBi.h"
using namespace core;

namespace fuzzy {
	template <class T>
	class ThenMult : public Then<T>
	{
	public:
		T evaluate(Expression<T>&, Expression<T>&) const;
	};


	template<class T>
	T ThenMult<T>::evaluate(Expression<T> & l, Expression<T> & r) const
	{
		T left = l.evaluate();
		T right = r.evaluate();
		return (left * right);
	}

}

#endif
