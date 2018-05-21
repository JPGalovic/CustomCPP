#pragma once
/**
 * Doubly Linked List Node, Contains definition for nodes used in Doubly Linked Lists.
 * Adapted from code developed for COS30008 - Data Structures and Patterns.
 * @author  J.P.Galovic
 * @version v1.5.0
 * @date    MAY18
 */

#include <ostream>
#include <Windows.h>

using std::ostream;

namespace Container
{
	template<class T>
	class DLNode
	{
	private:
		T fValue;
		DLNode<T>* fNext;
		DLNode<T>* fPrevious;

		DLNode();

	public:
		// Construction and Destruction.
		static DLNode<T> NIL;
		DLNode(const T & aValue);

		// Getters.
		const T & getValue() const;
		const DLNode & getNext() const;
		const DLNode & getPrevious() const;

		// Setters.
		void prepend(DLNode<T> & aNode);
		void append(DLNode<T> & aNode);
		void remove();

		// Swaping
		static bool areNeighbours(DLNode<T>& aLeft, DLNode<T>& aRight);
		
		static void fixOuter(DLNode<T>& aNode);
		static void swap(DLNode<T>& aLeft, DLNode<T>& aRight);

		// OStream.
		friend std::ostream & operator<<(std::ostream aOStream, const DLNode<T> & aDLNode)
		{
			HANDLE lConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO lConsoleInfo;
			WORD lConsoleColor;

			GetConsoleScreenBufferInfo(lConsole, &lConsoleInfo);
			lConsoleColor = lConsoleInfo.wAttributes;

			SetConsoleTextAttribute(lConsole, 14);
			aOStream << '(';

			if (&aDLNode.getPrevious() == &NIL)
			{
				SetConsoleTextAttribute(lConsole, 12);
				aOStream << "NULL";
			}
			else
			{
				SetConsoleTextAttribute(lConsole, 15);
				aOStream << aDLNode.getPrevious().getValue();
			}

			SetConsoleTextAttribute(lConsole, 14);
			aOStream << ", ";
			SetConsoleTextAttribute(lConsole, 15);
			aOStream << aListNode.getValue();
			SetConsoleTextAttribute(lConsole, 14);
			aOStream << ", ";

			if (&aDLNode.getNext() == &NIL)
			{
				SetConsoleTextAttribute(lConsole, 12);
				aOStream << "NULL";
			}
			else
			{
				SetConsoleTextAttribute(lConsole, 15);
				aOStream << aDLNode.getNext().getValue();
			}

			SetConsoleTextAttribute(lConsole, 14);
			aOStream << ')';

			SetConsoleTextAttribute(lConsole, lConsoleColor);
			return aOStream;
		}
	};

	/**
	 * Null Sentinal, Refernce to indicate null node.
	 * @date    12/05/2018.
	 */
	template<class T>
	DLNode<T> DLNode<T>::NIL;

	/**
	 * Default Class Constructor, constructs empty node.
	 * @date    12/05/2018.
	 */
	template<class T>
	DLNode<T>::DLNode()
	{
		fValue    = T();
		fNext     = &NIL;
		fPrevious = &NIL;
	}

	/**
	 * Class Constructor, constructs a node with a given value.
	 * @param   aValue, value to initalise node to.
	 * @date    12/05/2018.
	 */
	template<class T>
	DLNode<T>::DLNode(const T & aValue)
	{
		fValue    = aValue;
		fNext     = &NIL;
		fPrevious = &NIL;
	}

	/**
	 * Get value of node.
	 * @return  refernce to value of node.
	 * @date    12/05/2018.
	 */
	template<class T>
	const T & DLNode<T>::getValue() const
	{
		return fValue;
	}

	/**
	 * Gets next connected node.
	 * @return  refernce to next node if connected.
	 * @date    12/05/2018.
	 */
	template<class T>
	const DLNode<T> & DLNode<T>::getNext() const
	{
		return *fNext;
	}

	/**
	 * Gets previous connected node.
	 * @return  refernce to previous node if connected.
	 * @date    12/05/2018.
	 */
	template<class T>
	const DLNode<T> & DLNode<T>::getPrevious() const
	{
		return *fPrevious;
	}

	/**
	 * Prepends node to previous.
	 * @param   aNode, refernce to node to prepend.
	 * @date    12/05/2018.
	 */
	template<class T>
	void DLNode<T>::prepend(DLNode<T>& aNode)
	{
		aNode.fNext = this;

		if (fPrevious != &NIL)
		{
			aNode.fPrevious = fPrevious;
			fPrevious->fNext = &aNode;
		}

		fPrevious = &aNode;
	}

	/**
	 * Appends node to next.
	 * @param   aNode, refernce to node to append.
	 * @date    12/05/2018.
	 */
	template<class T>
	void DLNode<T>::append(DLNode<T>& aNode)
	{
		aNode.fPrevious = this;

		if (fNext != &NIL)
		{
			aNode.fNext = fNext;
			fNext->fPrevious = &aNode;
		}

		fNext = &aNode;
	}

	/**
	 * Removes node from list.
	 * @date    12/05/2018.
	 */
	template<class T>
	void DLNode<T>::remove()
	{
		if (fPrevious != &NIL)
			fPrevious->fNext = fNext;
		if (fNext != &NIL)
			fNext->fPrevious = fPrevious;
	}

	/**
	 * Checks if two nodes are neibours
	 */
	template<class T>
	bool DLNode<T>::areNeighbours(DLNode<T>& aLeft, DLNode<T>& aRight)
	{
		return (aLeft.fNext == &aRight && aRight.fPrevious == &aLeft) || (aLeft.fPrevious == &aRight && aRight.fNext == &aLeft);
	}

	/**
	 * Fixes the outer pointers of the node.
	 * @param   aNode, refernce to node to fix outers from.
	 * @date    21/05/2018.
	 */
	template<class T>
	void DLNode<T>::fixOuter(DLNode<T>& aNode)
	{
		if (aNode.fPrevious != &DLNode<T>::NIL)
			aNode.fPrevious->fNext = &aNode;
		if (aNode.fNext != &DLNode<T>::NIL)
			aNode.fNext->fPrevious = &aNode;
	}

	/**
	 * Swaps the positions of the left and right nodes.
	 * @param   aLeft, refernce to left node.
	 * @param   aRight, refernce to right node.
	 * @date    21/05/2018.
	 */
	template<class T>
	void DLNode<T>::swap(DLNode<T>& aLeft, DLNode<T>& aRight)
	{
		DLNode<T>* lSwaps[4];
		DLNode<T> lTemp;

		if (&aLeft == &aRight)
			return;

		if (aRight.fNext == &aLeft)
		{
			lSwaps[0] = aRight.fPrevious;
			lSwaps[1] = aLeft.fPrevious;
			lSwaps[2] = aRight.fNext;
			lSwaps[3] = aLeft.fNext;

			if (DLNode<T>::areNeighbours(aLeft, aRight))
			{
				aRight.fPrevious = lSwaps[2];
				aLeft.fPrevious = lSwaps[0];
				aRight.fNext = lSwaps[3];
				aLeft.fNext = lSwaps[1];
			}
			else
			{
				aRight.fPrevious = lSwaps[1];
				aLeft.fPrevious = lSwaps[0];
				aRight.fNext = lSwaps[3];
				aLeft.fNext = lSwaps[2];
			}
		}
		else
		{
			lSwaps[0] = aLeft.fPrevious;
			lSwaps[1] = aRight.fPrevious;
			lSwaps[2] = aLeft.fNext;
			lSwaps[3] = aRight.fNext;

			if (DLNode<T>::areNeighbours(aLeft, aRight))
			{
				aLeft.fPrevious = lSwaps[2];
				aRight.fPrevious = lSwaps[0];
				aLeft.fNext = lSwaps[3];
				aRight.fNext = lSwaps[1];
			}
			else
			{
				aLeft.fPrevious = lSwaps[1];
				aRight.fPrevious = lSwaps[0];
				aLeft.fNext = lSwaps[3];
				aRight.fNext = lSwaps[2];
			}
		}

		DLNode<T>::fixOuter(aLeft);
		DLNode<T>::fixOuter(aRight);
	}
}