#pragma once
/******************************************************************************
* Copyright (C) 10/07/2016
*
* @file         NObjectStatistics.hpp
* @author       Robert Badea
* @url		www.robertbadea.ro
******************************************************************************

//--------------------------------------------------------------------
//                              Includes
//--------------------------------------------------------------------

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

			static const unsigned GetObjectsCreated(void)
			{
				return objects_created;
			}
			
			static const unsigned GetObjectsAlive(void)
			{
				return objects_alive;
			}

		protected:
			virtual ~CObjectPool(void)
			{
				--objects_alive;
			}
		private:
			static unsigned objects_created;
			static unsigned objects_alive;
		};
		template <typename T> unsigned CObjectPool<T>::objects_created(0);
		template <typename T> unsigned CObjectPool<T>::objects_alive(0);

	} // namespace NObjectStatistics
} // namespace NUtility 
