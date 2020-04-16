#pragma once

#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "binaryExpression.h"
#include "expression.h"
#include "operatorsBi.h"
using namespace core;

namespace fuzzy {
	template <class T>
	class SugenoThen : public Then<T>
	{
	public:
		T evaluate(Expression<T>&, Expression<T>&) const;
		T premiseValue();
	private:
		T PremiseValue;
	

	template<class T>
	T SugenoThen<T>::evaluate(Expression<T> & l, Expression<T> & r) const
	{
		PremiseValue = l;
		return (left.evaluate() * right.evaluate());
	}

	template<class T>
	T SugenoThen<T>::premiseValue()
	{
		return PremiseValue;
	}


};

#endif