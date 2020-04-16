#pragma once
#ifndef OPERATORSBI_H
#define OPERATORSBI_H

#include "binaryExpression.h"
#include "expression.h"
using namespace core;

namespace fuzzy
{
	template <class T>
	class Or : public BinaryExpression<T> {};
	template <class T>
	class And : public BinaryExpression<T> {};
	template <class T>
	class Then : public BinaryExpression<T> {};
	template <class T>
	class Agg : public BinaryExpression<T> {};
}


#endif

