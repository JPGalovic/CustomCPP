#pragma once
/**
 * Dictionary Lookup Table, Contains a list of matched pairs.
 * @author  J.P.Galovic
 * @version v1.1.3
 * @date    MAY18
 */
#include "List.h"
#include "Pair.h"

namespace Container
{
	template<class K, class T>
	class Dictionary
	{
	private:
		List<Pair<K, T>> fLookup;

		// Getters
		const Pair<K, T> & getPair(const K & aKey) const;
		const List<Pair<K, T>> getData() const;

	public:
		// Construction and Destruction

		// Getters
		const T & getValue(const K & aKey) const;

		bool hasKey(const K & aKey) const;
		
		// Setters
		void addItem(const K & aKey, const T & aValue);
		void removeItem(const K & aKey);

		// OStream
		friend ostream& operator<<(ostream& aOStream, const Dictionary<K, T> & aDictionary)
		{
			aOStream << aDictionary.getData();
			return aOStream;
		}
	};

	/**
	 * Gets pair with a given key.
	 * @param   aKey, key of pair to get.
	 * @date    19/05/2018.
	 */
	template<class K, class T>
	inline const Pair<K, T> & Dictionary<K, T>::getPair(const K & aKey) const
	{
		for (int i = 0; i < fLookup.count(); i++)
		{
			Pair<K, T> lPair = fLookup[i];
			if (lPair.getA() == aKey)
				return fLookup[i];
		}
		throw std::runtime_error("Key not found.");
	}

	/**
	 * Gets value of pair with a given key.
	 * @param   aKey, key of pair to get value of.
	 * @date    19/05/2018.
	 */
	template<class K, class T>
	inline const T & Dictionary<K, T>::getValue(const K & aKey) const
	{
		try
		{
			Pair<K, T> lPair = getPair(aKey);
			return lPair.getB();
		}
		catch (const std::runtime_error& e)
		{
			throw e;
		}
	}

	/**
	 * Checks if key is found within pairs.
	 * @param   aKey, key to check.
	 * @date    19/05/2018.
	 */
	template<class K, class T>
	inline bool Dictionary<K, T>::hasKey(const K & aKey) const
	{
		try
		{
			getPair(aKey);
		}
		catch (const std::runtime_error& e)
		{
			return false;
		}
	}

	/**
	 * Gets data list.
	 * @date    16/05/2018.
	 */
	template<class K, class T>
	inline const List<Pair<K, T>> Dictionary<K, T>::getData() const
	{
		return fLookup;
	}

	/**
	 * Adds item to dictionary.
	 * Method enforces unique key definitions.
	 * @param   aKey, key of item.
	 * @param   aValue, value of item.
	 * @date    16/05/2018.
	 */
	template<class K, class T>
	inline void Dictionary<K, T>::addItem(const K & aKey, const T & aValue)
	{
		if (hasKey(aKey))
			throw std::runtime_error("Key alredy in dictionary.");
		fLookup.add(Pair<K, T>(aKey, aValue));
	}

	/**
	 * Removes item from dictionary.
	 * @param   aKey, key of item to remove.
	 * @date    16/05/2018.
	 */
	template<class K, class T>
	inline void Dictionary<K, T>::removeItem(const K & aKey)
	{
		try
		{
			fLookup.remove(getPair(aKey));
		}
		catch (const std::runtime_error& e)
		{
			throw e;
		}
	}
}
