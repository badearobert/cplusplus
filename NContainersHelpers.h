#ifndef _NContainersHelpers_H_
#define _NContainersHelpers_H_

#include <map>
#include <vector>

namespace NContainersHelpers
{
	/**
	* Usage: 
	*
	* std::map<string,int> myMap = InitMap<string,int>
	* ("INTERNAL_CONST_DIGIT_ONE", 			1)
	* ("INTERNAL_CONST_DIGIT_TWO", 			2)
	* ("INTERNAL_CONST_DIGIT_SEVEN", 		7);
	*
	**/
	
	template <typename T, typename U>
	class InitMap
	{
	public:
		InitMap(const T& key, const U& value);
		InitMap<T, U>& operator()(const T& key, const U& value);
		operator std::map<T, U>();
	private:
		std::map<T, U> mMap;
	};
	
	/**
	* Usage: 
	*
	* std::vector<string> myVector = InitVector<string>
	* ("INTERNAL_CONST_DIGIT_ONE")
	* ("INTERNAL_CONST_DIGIT_TWO")
	* ("INTERNAL_CONST_DIGIT_SEVEN");
	*
	**/
	
	template <typename T>
	class InitVector
	{
	public:
		InitVector(const T& value);
		InitVector<T>& operator()(const T& value);
		operator std::vector<T>();
	private:
		std::vector<T> mVector;
	};

}

namespace NContainersHelpers
{
	//--------------------Implementation of InitMap---------------------------

	template <typename T, typename U>
	InitMap<T, U>::InitMap(const T& key, const U& value)
	{
		mMap.insert(std::make_pair(key, value));
	}

	//---------------------------------------------------------------------------

	template <typename T, typename U>
	InitMap<T, U>& InitMap<T, U>::operator()(const T& key, const U& value)
	{
		mMap.insert(std::make_pair(key, value));
		return *this;
	}

	//---------------------------------------------------------------------------

	template <typename T, typename U>
	InitMap<T, U>::operator std::map<T, U>()
	{
		return mMap;
	}

	//----------------------------End InitMap------------------------------

	//----------------------Implementation of InitVector----------------------

	template <typename T>
	InitVector<T>::InitVector(const T& value)
	{
		mVector.push_back(value);
	}

	//---------------------------------------------------------------------------

	template <typename T>
	InitVector<T>& InitVector<T>::operator()(const T& value)
	{
		mVector.push_back(value);
		return *this;
	}

	//---------------------------------------------------------------------------

	template <typename T>
	InitVector<T>::operator std::vector<T>()
	{
		return mVector;
	}

	//----------------------------End InitVector------------------------------
}

#endif // _NContainersHelpers_H_