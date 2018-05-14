#pragma once
/**
 * Doubly Linked List Node Iterator, Provides simplified means to traverse lists in an iterive manor.
 * Adapted from code developed for COS30008 - Data Structures and Patterns.
 * @author  J.P.Galovic.
 * @version v1.2.1.
 * @date    MAY18.
 */

#include "DLNode.h"

namespace Container
{
	template<class T>
	class DLNodeIter
	{
	private:
		enum State {BEFORE, DATA, AFTER};
		State fState;

		const DLNode<T>* fLeftMost;
		const DLNode<T>* fRightMost;
		const DLNode<T>* fCurrent;

	public:
		// Construction and Destruction.
		DLNodeIter(const DLNode<T>& aList);

		// Getters.
		const T & operator*() const;

		DLNodeIter<T>& operator++();
		DLNodeIter<T> operator++(int);
		DLNodeIter<T>& operator--();
		DLNodeIter<T> operator--(int);

		bool operator==(const DLNodeIter<T>& aOther) const;
		bool operator!=(const DLNodeIter<T>& aOther) const;

		DLNodeIter<T> leftEnd() const;
		DLNodeIter<T> first() const;
		DLNodeIter<T> last() const;
		DLNodeIter<T> rightEnd() const;
	};

	/**
	 * Class Constructor, constructs itereator based on list node provided.
	 * @param   aList, refernce to list.
	 * @date    14/05/2018.
	 */
	template<class T>
	DLNodeIter<T>::DLNodeIter(const DLNode<T>& aList)
	{
		fLeftMost = &aList;
		while (&fLeftMost->getPrevious() != &DLNode<T>::NIL)
			fLeftMost = &fLeftMost->getPrevious();

		fCurrent = fLeftMost;
		if (fCurrent != &DLNode<T>::NIL)
			fState = DATA;
		else
			fState = AFTER;

		fRightMost = &aList;
		while (&fRightMost->getNext() != &DLNode<T>::NIL)
			fRightMost = &fRightMost->getNext();
	}

	/**
	 * Derefernce operator, derefernces current node.
	 * @date    14/05/2018.
	 */
	template<class T>
	const T & DLNodeIter<T>::operator*() const
	{
		return fCurrent->getValue();
	}

	/**
	 * Prefix Increment.
	 * @date    14/05/2018.
	 */
	template<class T>
	DLNodeIter<T>& DLNodeIter<T>::operator++()
	{
		switch (fState)
		{
		case BEFORE:
			fCurrent = fLeftMost;
			if (fCurrent == &DLNode<T>::NIL)
				fState = AFTER;
			else
				fState = DATA;
			break;
		case DATA:
			fCurrent = &fCurrent->getNext();
			if (fCurrent == &DLNode<T>::NIL)
		default:
			break;
		}
		return *this;
	}

	/**
	 * Postfix Increment.
	 * @date    14/05/2018.
	 */
	template<class T>
	DLNodeIter<T> DLNodeIter<T>::operator++(int)
	{
		DLNodeIter<T> lTemp = *this;
		++(*this);
		return lTemp;
	}


	/**
	 * Prefix Decrement.
	 * @date    14/05/2018.
	 */
	template<class T>
	DLNodeIter<T>& DLNodeIter<T>::operator--()
	{
		switch (fState)
		{
		case AFTER:
			fCurrent = fRightMost;
			if (fCurrent == &DLNode<T>::NIL)
				fState = BEFORE;
			else
				fState = DATA;
			break;
		case DATA:
			fCurrent = &fCurrent->fPrevious();
			if (fCurrent == &DLNode<T>::NIL)
				fCurrent = BEFORE;
		default:
			break;
		}
		return *this;
	}

	/**
	 * Postfix Decrement.
	 * @date    14/05/2018.
	 */
	template<class T>
	DLNodeIter<T> DLNodeIter<T>::operator--(int)
	{
		DLNodeIter<T> lTemp = *this;
		--(*this);
		return lTemp;
	}

	/**
	 * Equality Operator.
	 * @param   aOther, refernce to other Iterator.
	 * @date    14/05/2018.
	 */
	template<class T>
	bool DLNodeIter<T>::operator==(const DLNodeIter<T>& aOther) const
	{
		return fLeftMost == aOther.fLeftMost &&
			fRightMost == aOther.fRightMost &&
			fCurrent == aOther.fCurrent &&
			fState == aOther.fState;
	}

	/**
	 * Inequality Operator.
	 * @param   aOther, refernce to other Iterator.
	 * @date    14/05/2018.
	 */
	template<class T>
	bool DLNodeIter<T>::operator!=(const DLNodeIter<T>& aOther) const
	{
		return !(*this == aOther);
	}

	/**
	 * Gets iterator set before leftmost node.
	 * @date    14/05/2018.
	 */
	template<class T>
	DLNodeIter<T> DLNodeIter<T>::leftEnd() const
	{
		DLNodeIter<T> lTemp = *this;
		lTemp.fCurrent = &DLNode::NIL;
		lTemp.fState = BEFORE;
		return lTemp;
	}

	/**
	 * Gets iterator set at first node.
	 * @date    14/05/2018.
	 */
	template<class T>
	DLNodeIter<T> DLNodeIter<T>::first() const
	{
		return ++(leftEnd());
	}

	/**
	 * Gets iterator set at last node.
	 * @date    14/05/2018.
	 */
	template<class T>
	DLNodeIter<T> DLNodeIter<T>::last() const
	{
		return --(rightEnd());
	}

	/**
	 * Gets iterator set after rightmost node.
	 * @date    14/05/2018.
	 */
	template<class T>
	DLNodeIter<T> DLNodeIter<T>::rightEnd() const
	{
		DLNodeIter<T> lTemp = *this;
		lTemp.fCurrent = &DLNode::NIL;
		lTemp.fState = AFTER;
		return lTemp;
	}
}