#pragma once
#ifndef SUGENODEFFUZ_H
#define SUGENODEFFUZZ_H
#include "naryExpression.h"
#include "expression.h"
using namespace core;

namespace fuzzy
{
	template<class T>
	class SugenoDefuzz : public NaryExpression<T>
	{
	public:
		T evaluate(Expression<T>[]) const;
	};

	template<class T>
	T SugenoDefuzz<T>::evaluate(Expression<T> operands []) const
	{
		int somme = 0;
		for (int i = 0; i < sizeof(operands); i++)
		{
			somme += operands[i].evaluate()/operands[i].premiseValue();
		}
		return somme;
	}
	// sugeno est la somme pondérée des évaluation de toutes les règles, les coeffiscients, on s'en fout pour l'instant, on utilise the OrPlus pour sugeno et le sugeno then a un cache pour la pondér&ation
};

#endif
