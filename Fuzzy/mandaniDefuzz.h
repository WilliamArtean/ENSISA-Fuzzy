#pragma once
#pragma once
#ifndef MANDANIDEFUZZ_H
#define MANDANIDEFUZZ_H

#include "binaryExpression.h"
#include "expression.h"
using namespace core;

namespace fuzzy
{
	template<class T>
	class ManzaniDefuzz : public BinaryExpression<T>
	{
	public:
		T evaluate(Expression<T>&, Expression<T>&) const;
	};

	template<class T>
	T ManzaniDefuzz<T>::evaluate(Expression<T>& l, Expression<T>& r) const
	{
		return l.evaluate(r);
	}
	//Mandani : 1 expression est la fonction, la deuzième le x
}

#endif