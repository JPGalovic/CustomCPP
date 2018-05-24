#pragma once
/**
 * Queue Iterator, provides methods to iterate over Dynamic Queues
 * Adapted from code developed for COS30008 - Data Structures and Patterns.
 * @author  J.P.Galovic
 * @version 1.1.0
 * @date    MAY18
 */
#include "Queue.h"

namespace Container
{
	template<class T>
	class QueueIter
	{
	private:
		Queue<T> fQueue;

	public:
		// Construction and Destruction.
		QueueIter(const Queue<T>& aQueue);

		// Getters
		const T& operator*();
		
		QueueIter<T>& operator++();
		QueueIter<T> operator++(int);

		bool operator==(const QueueIter<T>& aOther) const;
		bool operator!=(const QueueIter<T>& aOther) const;

		QueueIter<T> end() const;

	};

	/**
	 * Class Constructor.
	 * @date    24/05/2018.
	 */
	template<class T>
	QueueIter<T>::QueueIter(const Queue<T>& aQueue)
	{
		fQueue = aQueue;
	}

	/**
	 * Derefernce operator.
	 * @date    24/05/2018.
	 */
	template<class T>
	const T & QueueIter<T>::operator*()
	{
		return fQueue.top();
	}

	/**
	 * Prefix increment.
	 * @date    24/05/2018.
	 */
	template<class T>
	QueueIter<T>& QueueIter<T>::operator++()
	{
		fQueue.dequeue();
		return *this;
	}

	/**
	 * Postfix increment.
	 * @date    24/05/2018.
	 */
	template<class T>
	QueueIter<T> QueueIter<T>::operator++(int)
	{
		QueueIter<T> lTemp = *this;
		++(*this);
		return lTemp;
	}

	/**
	 * Equality Operator.
	 * @date    24/05/2018.
	 */
	template<class T>
	bool QueueIter<T>::operator==(const QueueIter<T>& aOther) const
	{
		return fQueue.size() == aOther.fQueue.size();
	}

	/**
	 * Inequality Operator.
	 * @date    24/05/2018.
	 */
	template<class T>
	bool QueueIter<T>::operator!=(const QueueIter<T>& aOther) const
	{
		return !(*this == aOther);
	}

	/**
	 * Creates empty queue iterator.
	 * @date    24/05/2018.
	 */
	template<class T>
	QueueIter<T> QueueIter<T>::end() const
	{
		Queue<T> lQueue;
		return QueueIter<T>(lQueue);
	}
}