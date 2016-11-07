#pragma once
/******************************************************************************
* Copyright (C) 10/07/2016
*
* @file         NObjectStatistics.hpp
* @author       Robert Badea
* @url		www.robertbadea.ro
******************************************************************************/

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------
#include <inttypes.h>			// for uint32_t
//--------------------------------------------------------------------
//                         Class Declaration
//--------------------------------------------------------------------
namespace NUtility
{
	namespace NObjectStatistics
	{
		template <typename T>
		class CObjectPool
		{
		public:

			CObjectPool(void)
			{
				++objects_created;
				++objects_alive;
			}

			CObjectPool(const CObjectPool&)
			{
				++objects_created;
				++objects_alive;
			}

			static const uint32_t GetObjectsCreated(void)
			{
				return objects_created;
			}
			
			static const uint32_t GetObjectsAlive(void)
			{
				return objects_alive;
			}

		protected:
			virtual ~CObjectPool(void)
			{
				--objects_alive;
			}
		private:
			static uint32_t objects_created;
			static uint32_t objects_alive;
		};
		template <typename T> uint32_t CObjectPool<T>::objects_created(0);
		template <typename T> uint32_t CObjectPool<T>::objects_alive(0);

	} // namespace NObjectStatistics
} // namespace NUtility 
