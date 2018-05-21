#pragma once
/**
 * Paired Elements
 * @author  J.P.Galovic
 * @version v1.1.2
 * @date    MAY18
 */

#include <ostream>
#include <Windows.h>

using std::ostream;

namespace Container
{
	template<class A, class B>
	class Pair
	{
	private:
		A fA;
		B fB;

	public:
		// Construction and Destruction.
		Pair();
		Pair(const A & aA, const B & aB);
		
		// Getters
		const A & getA() const;
		const B & getB() const;

		bool operator==(const Pair<A, B> & aOther) const;
		bool operator!=(const Pair<A, B> & aOther) const;

		// Setters
		void setA(const A & aA);
		void setB(const B & aB);

		// OStream
		friend ostream& operator<<(ostream& aOStream, const Pair<A, B> & aPair)
		{
			HANDLE lConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO lConsoleInfo;
			WORD lConsoleColor;

			GetConsoleScreenBufferInfo(lConsole, &lConsoleInfo);
			lConsoleColor = lConsoleInfo.wAttributes;

			SetConsoleTextAttribute(lConsole, 14);
			aOStream << "[";

			SetConsoleTextAttribute(lConsole, 15);
			A lA = (A)aPair.getA();
			aOStream << lA;

			SetConsoleTextAttribute(lConsole, 14);
			aOStream << ", ";

			SetConsoleTextAttribute(lConsole, 15);
			B lB = (B)aPair.getB();
			aOStream << lB;

			SetConsoleTextAttribute(lConsole, 14);
			aOStream << "]";

			SetConsoleTextAttribute(lConsole, lConsoleColor);
			return aOStream;
		}
	};

	/**
	 * Default Class Constructor, constructs empty pair.
	 * @date    14/05/2018
	 */
	template<class A, class B>
	Pair<A, B>::Pair()
	{
		fA = A();
		fB = B();
	}

	/**
	 * Class Constructor.
	 * @param   aA, refernce to A.
	 * @param   aB, refernce to B.
	 * @date    14/05/2018
	 */
	template<class A, class B>
	Pair<A, B>::Pair(const A & aA, const B & aB)
	{
		fA = aA;
		fB = aB;
	}

	/**
	 * Gets value of A.
	 * @date    21/05/2018.
	 */
	template<class A, class B>
	const A & Pair<A, B>::getA() const
	{
		return fA;
	}

	/** 
	 * Gets value of B.
	 * @date    21/05/2018.
	 */
	template<class A, class B>
	const B & Pair<A, B>::getB() const
	{
		return fB;
	}

	/**
	 * Equality Operator.
	 * @param   aOther, refernce to other pair.
	 * @date    20/05/2018.
	 */
	template<class A, class B>
	bool Pair<A, B>::operator==(const Pair<A, B>& aOther) const
	{
		return fA == aOther.fA && fB == aOther.fB;
	}

	/**
	 * Inequality Operator.
	 * @param   aOther, refernce to other pair.
	 * @date    14/05/2018.
	 */
	template<class A, class B>
	bool Pair<A, B>::operator!=(const Pair<A, B>& aOther) const
	{
		return !(*this == aOther);
	}

	/**
	 * Sets Value of A.
	 * @param   aA, refernce to A.
	 * @date    14/05/2018.
	 */
	template<class A, class B>
	void Pair<A, B>::setA(const A & aA)
	{
	}

	/**
	 * Sets value of B.
	 * @param   aB, refernce to B.
	 * @date    14/05/2018.
	 */
	template<class A, class B>
	void Pair<A, B>::setB(const B & aB)
	{
		fB = aB;
	}
}