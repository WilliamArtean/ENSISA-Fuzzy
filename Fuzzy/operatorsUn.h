#pragma once
#ifndef OPERATORSUN_H
#define OPERATORSUN_H

#include "unaryExpression.h"
#include "expression.h"
using namespace core;

namespace fuzzy
{
	template <class T>
	class Not : public UnaryExpression<T> {};
	template <class T>
	class Is : public UnaryExpression<T> {};
}

#endif