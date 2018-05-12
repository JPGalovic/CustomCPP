#pragma once
/**
 * Doubly Linked List, Contains definition for lists.
 * Adapted from code developed for COS30008 - Data Structures and Patterns.
 * @author  J.P.Galovic
 * @version v1.3.0
 * @date    MAY18
 */

#include "DLNodeIter.h"

namespace Container
{
	template<class T>
	class List
	{
	private:
		DLNode<T>* fTop;
		DLNode<T>* fLast;

		int fCount;

	public:
		typedef DLNodeIter<T> Iter;
		typedef DLNode<T> Node;
		typedef List<T> List;

		// Construction and Destruction.
		List();
		List(const List<T>& aOther);

		~List();

		List<T>& operator=(const List<T>& aOther);
		
		// Getters.
		bool empty() const;

		int size() const;
		int count() const;

		int count(const T & aElement) const;

		bool contains(const T & aElement) const;

		const T & find(const T & aElement) const;
		int findIndex(const T & aElement) const;
		int findIndex(const T & aElement, int aIndex) const;

		const T & findLast(const T & aElement) const;
		int findLastIndex(const T & aElement) const;
		int findLastIndex(const T & aElement, int aIndex) const;

		bool operator==(const List<T> & aOther) const;
		bool operator!=(const List<T> & aOther) const;

		const T & getAt(int aIndex) const;
		const T & operator[](int aIndex) const;

		DLNodeIter<T> getIter() const;

		// Setters.
		void append(const T & aElement);
		void prepend(const T & aElement);

		void add(const T & aElement);
		void insert(const T & aElement, int aIndex);

		bool remove(const T & aElement);
		int removeAll(const T & aElement);
		void removeAt(int aIndex);
		void removeRange(int aIndex, int aCount);

		// OStream.
		friend ostream& operator<<(ostream& aOStream, const List<T> & aList)
		{
			HANDLE lConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO lConsoleInfo;
			WORD lConsoleColor;

			GetConsoleScreenBufferInfo(lConsole, &lConsoleInfo);
			lConsoleColor = lConsoleInfo.wAttributes;

			SetConsoleTextAttribute(lConsole, 14);
			aOStream << "{";

			for (int i = 0; i < aList.size(); i++)
			{
				if (i > 0)
				{
					SetConsoleTextAttribute(lConsole, 14);
					aOStream << ", ";
				}
				SetConsoleTextAttribute(lConsole, 15);
				aOStream << aList[i];
			}

			SetConsoleTextAttribute(lConsole, 14);
			aOStream << "}";

			SetConsoleTextAttribute(lConsole, lConsoleColor);
			return aOStream;
		}
	};

	/**
	 * Default Class Constructor, constructs an empty list.
	 * @date    12/05/2018.
	 */
	template<class T>
	List<T>::List()
	{
		fTop = &Node::NIL;
		fLast = &Node::NIL;
		fCount = 0;
	}

	/**
	 * Copy Constructor, constructs a copy of the list.
	 * @param   aOther, refernce to other list.
	 * @date    12/05/2018.
	 */
	template<class T>
	List<T>::List(const List<T>& aOther)
	{
		fTop = &Node::NIL;
		fLast = &Node::NIL;
		fCount = 0;

		for (Iter lIter = aOther.getIter(); lIter != lIter.rightEnd(); lIter++)
			append(*lIter);
	}

	/**
	 * Class Distructor, destructs list, deleting all elements within list.
	 * @date    12/05/2018.
	 */
	template<class T>
	List<T>::~List()
	{
		while (fTop != &Node::NIL)
		{
			Node* lTemp = (Node*) &fTop->getNext();
			fTop->remove();
			delete fTop;
			fTop = lTemp;
		}
	}

	/**
	 * Class Asignment Operater, makes this a copy of the other.
	 * @param   aOther, refernce to other list.
	 * @date    12/05/2018.
	 */
	template<class T>
	List<T>& List<T>::operator=(const List<T>& aOther)
	{
		if (&aOther != this)
		{
			while (fTop != &Node::NIL)
			{
				Node* lTemp = (Node*) &fTop->getNext();
				fTop->remove();
				delete fTop;
				fTop = lTemp;
			}

			fTop = &Node::NIL;
			fLast = &Node::NIL;
			fCount = 0;

			for (Iter lIter = aOther.getIter(); lIter != lIter.rightEnd(); lIter++)
				append(*lIter);
		}
		return *this;
	}

	/**
	 * Checks if list is empty.
	 * @date    12/10/2018.
	 */
	template<class T>
	bool List<T>::empty() const
	{
		return fTop == &Node::NIL;
	}

	/**
	 * Gets number of elements in the list.
	 * @date    12/10/2018.
	 */
	template<class T>
	int List<T>::size() const
	{
		return fCount;
	}

	/**
	 * Gets number of elements in the list.
	 * @date    12/10/2018.
	 */
	template<class T>
	int List<T>::count() const
	{
		return fCount;
	}

	/**
	 * Gets number of a given element in list.
	 * @param   aElement, refernce to element to check for.
	 * @date    12/05/2018.
	 */
	template<class T>
	int List<T>::count(const T & aElement) const
	{
		int lCount = 0;

		if (!empty())
			for (Iter lIter = aOther.getIter(); lIter != lIter.rightEnd(); lIter++)
				if (*lIter == aElement)
					lCount++;
		return lCount;
	}

	/**
	 * Checks if element within list.
	 * @param   aElement, refernce to element to check for.
	 * @date    12/05/2018.
	 */
	template<class T>
	bool List<T>::contains(const T & aElement) const
	{
		if (!empty())
			for (Iter lIter = aOther.getIter(); lIter != lIter.rightEnd(); lIter++)
				if (*lIter == aElement)
					return true;
		return false;
	}

	/**
	 * Finds first matching element in list.
	 * @param   aElement, refernce to element to find.
	 * @date    12/05/2018.
	 */
	template<class T>
	const T & List<T>::find(const T & aElement) const
	{
		if (!empty())
			for (Iter lIter = aOther.getIter(); lIter != lIter.rightEnd(); lIter++)
				if (*lIter == aElement)
					return *lIter;
		throw std::runtime_error("List does not contain element.");
	}

	/**
	 * Finds the index of the first matching element in list.
	 * @param   aElement, refernce to element to find.
	 * @date    12/05/2018.
	 */
	template<class T>
	int List<T>::findIndex(const T & aElement) const
	{
		if (!empty())
		{
			int i = 0;
			for (Iter lIter = aOther.getIter(); lIter != lIter.rightEnd(); lIter++)
			{
				if (*lIter == aElement)
					return i;
				i++;
			}
		}
		throw std::runtime_error("List does not contain element.");
	}

	/**
	 * Finds the index of the first matching element in list after index through end..
	 * @param   aElement, refernce to element to find.
	 * @param   aIndex, index to start searching from.
	 * @date    12/05/2018.
	 */
	template<class T>
	int List<T>::findIndex(const T & aElement, int aIndex) const
	{
		if (aIndex < fCount)
		{
			int i = 0;
			for (Iter lIter = aOther.getIter(); lIter != lIter.rightEnd(); lIter++)
			{
				if (*lIter == aElement && i > aIndex)
					return i;
				i++;
			}
			throw std::runtime_error("List does not contain element.");
		}
		throw std::range_error("Index out of range.");
	}

	/**
	 * Finds last matching element in list.
	 * @param   aElement, refernce to element to find.
	 * @date    12/05/2018.
	 */
	template<class T>
	const T & List<T>::findLast(const T & aElement) const
	{
		if (!empty())
			for (Iter lIter = aOther.getIter().last(); lIter != lIter.leftEnd(); lIter--)
				if (*lIter == aElement)
					return *lIter;
		throw std::runtime_error("List does not contain element.");
	}

	/**
	 * Finds the index of the last matching element in list.
	 * @param   aElement, refernce to element to find.
	 * @date    12/05/2018.
	 */
	template<class T>
	int List<T>::findLastIndex(const T & aElement) const
	{
		if (!empty())
		{
			int i = fCount;
			for (Iter lIter = aOther.getIter().last(); lIter != lIter.leftEnd(); lIter--)
			{
				if (*lIter == aElement)
					return i;
				i--;
			}
		}
		throw std::runtime_error("List does not contain element.");
	}

	/**
	 * Finds the index of the last matching element in list before index through start..
	 * @param   aElement, refernce to element to find.
	 * @param   aIndex, index to start searching from.
	 * @date    12/05/2018.
	 */
	template<class T>
	int List<T>::findLastIndex(const T & aElement, int aIndex) const
	{
		if (aIndex < fCount)
		{
			int i = fCount;
			for (Iter lIter = aOther.getIter().last(); lIter != lIter.leftEnd(); lIter--)
			{
				if (*lIter == aElement && i > aIndex)
					return i;
				i--;
			}
			throw std::runtime_error("List does not contain element.");
		}
		throw std::range_error("Index out of range.");
	}

	/**
	 * Equality operator.
	 * @param   aOther, refernce to other list.
	 * @date    12/05/2018
	 */
	template<class T>
	bool List<T>::operator==(const List<T>& aOther) const
	{
		return fTop == aOther.fTop &&
			fLast == aOther.fLast &&
			fCount == aOther.fCount;
	}

	/**
	 * Inequality operator.
	 * @param   aOther, refernce to other list.
	 * @date    12/05/2018.
	 */
	template<class T>
	bool List<T>::operator!=(const List<T>& aOther) const
	{
		return !(*this == aOther);
	}

	/** 
	 * Gets value of node at the given index.
	 * @param   aIndex, index to retrive.
	 * @date    12/05/2018.
	 */
	template<class T>
	inline const T & List<T>::getAt(int aIndex) const
	{
		if (aIndex < fCount)
		{
			Node* lNode = fTop;
			while (aIndex)
			{
				aIndex--;
				lNode = (Node*)&lNode->getNext();
			}
			return lNode->getValue();
		}
		throw std::range_error("Index out of range.");
	}

	/** 
	 * Gets value of node at the given index.
	 * @param   aIndex, index to retrive.
	 * @date    12/05/2018.
	 */
	template<class T>
	inline const T & List<T>::operator[](int aIndex) const
	{
		try
		{
			return getAt(aIndex);
		}
		catch (const std::range_error& e)
		{
			throw e;
		}
	}

	/**
	 * Gets list iterator.
	 * @date    12/05/2018.
	 */
	template<class T>
	inline DLNodeIter<T> List<T>::getIter() const
	{
		return DLNodeIter<T>(*fTop);
	}

	/**
	 * Appends list with element.
	 * @param   aElement, refernce to element to append list.
	 * @date    12/05/2018.
	 */
	template<class T>
	void List<T>::append(const T & aElement)
	{
		Node* lNewElement = new Node(aElement);

		if (fTop == &Node::NIL)
		{
			fTop = lNewElement;
			fLast = lNewElement;
		}
		else
		{
			fLast->append(*lNewElement);
			fLast = lNewElement;
		}

		fCount++;
	}

	/** 
	 * Prepends list with element.
	 * @param   aElement, refernce to element to prepend list.
	 * @date    12/05/2018.
	 */
	template<class T>
	void List<T>::prepend(const T & aElement)
	{
		Node* lNewElement = new Node(aElement);
		
		if (fTop == &Node::NIL)
		{
			fTop = lNewElement;
			fLast = lNewElement;
		}
		else
		{
			fTop->prepend(*lNewElement);
			fTop = lNewElement;
		}
		
		fCount++;
	}

	/**
	 * Adds element to list.
	 * @param   aElement, refernce to element to add.
	 * @date 12/05/2018.
	 */
	template<class T>
	void List<T>::add(const T & aElement)
	{
		append(aElement);
	}

	/**
	 * Inserts element at a given index.
	 * @param   aElement, refernce to element to insert.
	 * @param   aIndex, index to insert at.
	 * @date    12/05/2018.
	 */
	template<class T>
	void List<T>::insert(const T & aElement, int aIndex)
	{
		if (!(aIndex < fCount))
			throw std::range_error("Index out of range.");

		Node* lNewElement = new Node(aElement);
		Node* lNode = fTop;

		while (aIndex)
		{
			aIndex--;
			lNode = (Node*)&lNode->getNext();
		}
		lNode->append(&lNewElement);

		fCount++;
	}

	/**
	 * Removes first instance of a given element.
	 * @param   aElement, reference to element to remove.
	 * @date    12/05/2018.
	 */
	template<class T>
	bool List<T>::remove(const T & aElement)
	{
		Node* lNode = fTop;

		while (lNode != &Node::NIL)
		{
			if (lNode->getValue() == aElement)
			{
				if (lNode == fTop)
					fTop = (Node*)&lNode->getNext();
				if (lNode == fLast)
					fLast = (Node*)&lNode->getPrevious();
				lNode->remove();
				delete lNode;
				fCount--;
				return true;
			}
			lNode = (Node*)&lNode->getNext();
		}
		return false;
	}

	/**
	 * Removes all instances of a given element.
	 * @param   aElement, refernce to element to remove.
	 * @date    12/05/2018.
	 */
	template<class T>
	int List<T>::removeAll(const T & aElement)
	{
		int lCount = 0;

		Node* lNode = fTop;

		while (lNode != &Node::NIL)
		{
			if (lNode->getValue() == aElement)
			{
				if (lNode == fTop)
					fTop = (Node*)&lNode->getNext();
				if (lNode == fLast)
					fLast = (Node*)&lNode->getPrevious();
				lNode->remove();
				delete lNode;

				Node* lNode = fTop;

				fCount--;
				lCount++;
				continue;
			}
			lNode = (Node*)&lNode->getNext();
		}
		return false;
	}

	/**
	 * Removes node at given index.
	 * @param   aIndex, index of node to remove.
	 * @date    12/05/2018.
	 */
	template<class T>
	void List<T>::removeAt(int aIndex)
	{
		try
		{
			remove(getAt(aIndex));
		}
		catch (const std::range_error& e)
		{
			throw e;
		}
	}

	/**
	 * Removes a given number of nodes from the index.
	 * @param   aIndex, starting index to remove node.
	 * @param   aCount, number of nodes to remove.
	 * @date    12/05/2018.
	 */
	template<class T>
	void List<T>::removeRange(int aIndex, int aCount)
	{
		try
		{
			for(int i = aCount; i > 0; i--)
				remove(getAt(aIndex));
		}
		catch (const std::range_error& e)
		{
			throw e;
		}
	}
}