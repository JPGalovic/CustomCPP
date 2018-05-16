#pragma once
/** 
 * Dynamic Queue, contains definitions for queued data structures.
 * Adapted from code developed for COS30008 - Data Structures and Patterns.
 * @author  J.P.Galovic
 * @version 1.2.0
 * @date    MAY18
 */
#include "List.h"

namespace Container
{
	template<class T>
	class Queue
	{
	private:
		List<T> fElements;

		// Getters.
		const List<T> getElements() const;

	public:
		// Construction and Destriction.

		// Getters.
		bool empty() const;

		int size() const;
		int count() const;

		const T& top() const;
		
		// Setters.
		void enqueue(const T& aElement);
		void dequeue() const;

		// OStream.
		friend ostream& operator<<(ostream& aOStream, const Queue<T>& aOther)
		{
			aOStream << aOther.getElements();
			return aOStream;
		}
	};

	/**
	 * Gest copy of elements list for printing.
	 * @date    16/05/2018.
	 */
	template<class T>
	const List<T> Queue<T>::getElements() const
	{
		return fElements;
	}

	/**
	 * Checks if queue is empty.
	 * @date    16/05/2018.
	 */
	template<class T>
	bool Queue<T>::empty() const
	{
		return fElements.empty();
	}

	/**
	 * Gets number of elements in queue.
	 * @date    16/05/2018.
	 */
	template<class T>
	int Queue<T>::size() const
	{
		return fElements.size();
	}

	/**
	 * Gets number of elements in queue.
	 * @date    16/05/2018.
	 */
	template<class T>
	int Queue<T>::count() const
	{
		return fElements.count();
	}

	/**
	 * Gets element at top of queue.
	 * @date    16/05/2018.
	 */
	template<class T>
	const T & Queue<T>::top() const
	{
		if (empty())
			throw std::underflow_error("Queue empty.");
		return fElements[0];
	}

	/**
	 * Adds element to back of queue.
	 * @param   aElement, element to add to queue.
	 * @date    16/05/2018.
	 */
	template<class T>
	void Queue<T>::enqueue(const T & aElement)
	{
		fElements.append(aElement);
	}

	/**
	 * Removes element at top of queue and returns it.
	 * @date    16/05/2018.
	 */
	template<class T>
	void Queue<T>::dequeue() const
	{
		if (empty())
			throw std::underflow_error("Queue empty.");
		fElements.removeAt(0);
	}
}
