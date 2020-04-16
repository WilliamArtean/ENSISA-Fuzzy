#pragma once
#ifndef VALUE_MODEL_H
#define VALUE_MODEL_H

namespace core
{
	template <class T>
	class ValueModel
	{
	public:
		ValueModel() {};
		ValueModel(T& v) :value(v) {};
		T evaluate() const;
		void setValue(T&);
	private:
		T value;
	};

	template<class T>
	T ValueModel<T>::evaluate() const
	{
		return value;
	}

	template <class T>
	void ValueModel<T>::setValue(T& v)
	{
		value = v;
	}
}

#endif