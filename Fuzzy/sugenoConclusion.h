#pragma once
#ifndef SUGENODEFFUZ_H
#define SUGENODEFFUZZ_H
#include "naryExpression.h"
#include "expression.h"
using namespace core;

namespace fuzzy
{
	template<class T>
	class SugenoConclusion : public NaryExpression<T>
	{
	public:
		T evaluate(Expression<T>[]) const;
	};

	template<class T>
	T SugenoConclusion<T>::evaluate(Expression<T> operands[]) const
	{
		int somme = 0;
		if (sizeof(operands) <= sizeof(coeffs))
		{
			for (int i = 0; i < sizeof(operands); i++)
			{
				somme += coef[i]*operands[i].evaluate() / operands[i].premiseValue();
			}
		}
		
		return somme;
	}
}

#endif