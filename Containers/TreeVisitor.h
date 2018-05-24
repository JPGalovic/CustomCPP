#pragma once
/**
 * Tree Visitor, facilitates visiting NTrees, used by overloading methods (expansion)
 * Adapted from code developed for COS30008 - Data Structures and Patterns.
 * @author  J.P.Galovic
 * @version 1.1.0
 * @date    MAY18
 */

#include <iostream>

using std::cout;

namespace Container
{
	/**
	 * Default "Parent" Class.
	 * @date    24/05/2018.
	 */
	template<class T>
	class TreeVisitor
	{
	public:
		// Construction and Destruction
		virtual ~TreeVisitor() {}

		// Other
		virtual void preVisit(const T& aKey) const {}
		virtual void posVisit(const T& aKey) const {}
		virtual void inVisit(const T& aKey) const {}
		virtual void visit(const T& aKey) const { cout << aKey << " "; }
	};

	/**
	 * PreOrder Tree Visitor.
	 * @date    24/05/2018.
	 */
	template<class T>
	class PreOrderVisitor : public TreeVisitor<T>
	{
	public:
		// Other
		/**
		 * Pre visit overidden to invoke default behavior.
		 */
		virtual void preVisit(const T& aKey) const { this->visit(aKey); }
	};

	/**
	 * PostOrder Tree Visitor.
	 * @date    24/05/2018.
	 */
	template<class T>
	class PostOrderVisitor : public TreeVisitor<T>
	{
	public:
		// Other
		/**
		 * Post Visit overidden to invoke default behavior.
		 */
		virtual void postVisit(const T& aKey) const { this->visit(aKey); }
	};

	/**
	 * Left Linear Tree Visitor.
	 * @date    24/05/2018.
	 */
	template<class T>
	class LeftLinearVisitor : public TreeVisitor<T>
	{
	public:
		// Other
		/**
		 * Post Visit overidden.
		 */
		virtual void postVisit(const T& aKey) const { cout << "]"; }

		/**
		 * Pre Visit overidden.
		 */
		virtual void preVisit(const T& aKey) const { cout << "[" << aKey; }
	};
}