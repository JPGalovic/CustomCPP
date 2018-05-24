#pragma once
/**
 * Stack Iterator, provides methods to iterate over Dynamic Stacks
 * Adapted from code developed for COS30008 - Data Structures and Patterns.
 * @author  J.P.Galovic
 * @version 1.1.0
 * @date    MAY18
 */

#include "Stack.h"

namespace Container
{
	template<class T>
	class StackIter
	{
	private:
		Stack<T> fStack;

	public:
		// Construction and Destruction.
		StackIter(const Stack<T>& aStack);

		// Getters.
		const T& operator*();

		StackIter<T>& operator++();
		StackIter<T> operator++(int);

		bool operator==(const StackIter<T>& aOther) const;
		bool operator!=(const StackIter<T>& aOther) const;

		StackIter<T> end() const;
	};

	/**
	 * Class Constructor.
	 * @param   aStack, refernce to stack.
	 * @date    24/05/2018.
	 */
	template<class T>
	inline StackIter<T>::StackIter(const Stack<T>& aStack)
	{
		fStack = aStack;
	}

	/**
	 * Derefernce operator.
	 * @date    24/05/2018.
	 */
	template<class T>
	inline const T & StackIter<T>::operator*()
	{
		return fStack.top();
	}

	/**
	 * Prefix increment.
	 * @date    24/05/2018.
	 */
	template<class T>
	inline StackIter<T>& StackIter<T>::operator++()
	{
		fStack.pop();
		return *this;
	}

	/**
	 * Postfix increment.
	 * @date    24/05/2018.
	 */
	template<class T>
	inline StackIter<T> StackIter<T>::operator++(int)
	{
		StackIter<T> lTemp = *this;
		++(*this);
		return lTemp;
	}

	/**
	 * Equality operator.
	 * @date    24/05/2018.
	 */
	template<class T>
	inline bool StackIter<T>::operator==(const StackIter<T>& aOther) const
	{
		return fStack.size() == aOther.fStack.size();
	}

	/**
	 * Inequality operator.
	 * @date    24/05/2018.
	 */
	template<class T>
	inline bool StackIter<T>::operator!=(const StackIter<T>& aOther) const
	{
		return !(*this == aOther);
	}

	/**
	 * Creates empty stack iterator.
	 * @date    24/05/2018.
	 */
	template<class T>
	inline StackIter<T> StackIter<T>::end() const
	{
		Stack<T> lStack;
		return StackIter<T>(lStack);
	}
}