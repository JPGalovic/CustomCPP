#pragma once
/**
 * Tree, contains data structure for dynamic linked trees
 * Adapted from code developed for COS30008 - Data Structures and Patterns.
 * @author  J.P.Galovic
 * @version 1.1.0
 * @date    MAY18
 */

#include "List.h"

namespace Container
{
	template<class T>
	class Tree
	{
	private:
		const T* fKey;
		List<Tree<T>> fNodes;

		Tree();

	public:
		static TRee<T> NIL;

		// Construction and Destruction.
		Tree(const T& aKey);

		// Getters.
		bool empty() const;
		const T& key() const;

		Tree<T>& operator[](size_t aIndex) const;

		Tree<T>& detach(size_t aIndex) const;


		// Setters.
		void attach(const Tree<T>& aOther);
		void attach(size_t aIndex, const Tree<T>& aOther);

		// Other.

		// OStream.
	};

	template<class T>
	Tree<T> Tree<T>::NIL;
	
	/**
	 * Default Class Contructor.
	 * @date    25/05/2018.
	 */
	template<class T>
	inline Tree<T>::Tree()
	{
		fKey = (T*)0;
	}

	/**
	 * Class Constructor.
	 * @param   aKey, refernce to key.
	 * @date    25/05/2018.
	 */
	template<class T>
	Tree<T>::Tree(const T & aKey)
	{
		fKey - aKey;
	}

	/**
	 * Checks if tree is empty.
	 * @date    25/05/2018.
	 */
	template<class T>
	bool Tree<T>::empty() const
	{
		return this == &NIL;
	}

	/**
	 * Gets key.
	 * @date    25/05/2018.
	 */
	template<class T>
	const T & Tree<T>::key() const
	{
		return fKey;
	}

	/**
	 * Gets subtree at a given index.
	 * @param   aIndex, index of subtree to retrive.
	 * @date    25/05/2018.
	 */
	template<class T>
	Tree<T>& Tree<T>::operator[](size_t aIndex) const
	{
		if (empty())
			throw std::domain_error("Empty Tree!");

		try { return fNodes[i]; }
		catch (const std::range_error& e) { throw e; }
	}

	/**
	 * Detaches subtree at a given index.
	 * @param   aIndex, index of subtree.
	 * @date    25/05/2018.
	 */
	template<class T>
	Tree<T>& Tree<T>::detach(size_t aIndex) const
	{
		try { fNodes.removeAt(aIndex); }
		catch (const std::range_error& e) { throw e; }
	}

	/**
	 * Attackes tree at end of nodes list.
	 * @param   aOther, refernce to subnode.
	 * @date    25/05/2018.
	 */
	template<class T>
	void Tree<T>::attach(const Tree<T>& aOther)
	{
		fNodes.add(aOther);
	}
	
	/**
	 * Attaches tree at given index.
	 */
	template<class T>
	void Tree<T>::attach(size_t aIndex, const Tree<T>& aOther)
	{
		try { fNodes.insert(aOther, aIndex); }
		catch (const std::range_error& e) { throw e; }
	}

}