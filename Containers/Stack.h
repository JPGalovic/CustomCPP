#pragma once
/**
 * Dynamic Stack, contains definitions for stacked data structures.
 * Adapted from code developed for COS30008 - Data Structures and Patterns.
 * @author  J.P.Galovic
 * @version 1.1.0
 * @date    MAY18
 */

#include "List.h"

namespace Container
{
	template<class T>
	class Stack
	{
	private:
		List<T> fElements;

		const List<T>& getElements() const;
	public:
		// Construction and Destruction.

		// Getters.
		bool empty() const;
		int size() const;

		const T& top() const;

		// Setters.
		void push(const T& aElement);
		void pop();

		// OStream.
		friend ostream& operator<<(ostream& aOStream, const Stack<T>& aOther)
		{
			aOStream << aOther.getElements();
			return aOStream;
		}
	};

	/**
	 * Gets element list, for OStream.
	 * @date    24/05/2018.
	 */
	template<class T>
	inline const List<T>& Stack<T>::getElements() const
	{
		return fElements;
	}

	/**
	 * Checks if stack is empty.
	 * @return    24/05/2018.
	 */
	template<class T>
	inline bool Stack<T>::empty() const
	{
		return fElements.empty();
	}

	/**
	 * Gest size of stack.
	 * @return    24/05/2018.
	 */
	template<class T>
	inline int Stack<T>::size() const
	{
		return fElements.size();
	}

	/**
	 * Gets elemet at top of stack.
	 * @date    24/05/2018.
	 */
	template<class T>
	inline const T & Stack<T>::top() const
	{
		if (empty())
			throw std::underflow_error("Empty Stack.");
		return fElements[0];
	}

	/**
	 * Adds element to top of stack.
	 * @param   aElement, element to add.
	 * @date    24/05/2018.
	 */
	template<class T>
	inline void Stack<T>::push(const T & aElement)
	{
		fElements.prepend(aElement);
	}

	/**
	 * Removes element from top of stack.
	 * @date    24/05/2018.
	 */
	template<class T>
	inline void Stack<T>::pop()
	{
		if (empty())
			throw std::underflow_error("Empty Stack.");
		return fElements.removeAt(0);
	}
}