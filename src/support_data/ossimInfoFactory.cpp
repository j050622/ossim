//----------------------------------------------------------------------------
//
// License:  LGPL
// 
// See LICENSE.txt file in the top level directory for more details.
//
// Author:  David Burken
//
// Description: Factory for info objects.
// 
//----------------------------------------------------------------------------
// $Id: ossimInfoFactory.cpp 22118 2013-01-18 21:05:14Z dburken $

#include <ossim/support_data/ossimInfoFactory.h>
#include <ossim/ossimConfig.h>
#include <ossim/base/ossimFilename.h>
#include <ossim/support_data/ossimInfoBase.h>
#include <ossim/support_data/ossimCcfInfo.h>
#include <ossim/support_data/ossimDemInfo.h>
#include <ossim/support_data/ossimDoqq.h>
#include <ossim/support_data/ossimDtedInfo.h>
#include <ossim/support_data/ossimEnviInfo.h>
#include <ossim/support_data/ossimJ2kInfo.h>
#include <ossim/support_data/ossimJp2Info.h>
#include <ossim/support_data/ossimLasInfo.h>
#include <ossim/support_data/ossimNitfInfo.h>
#include <ossim/support_data/ossimRpfInfo.h>
#include <ossim/support_data/ossimTiffInfo.h>
#include <ossim/support_data/ossimXmpInfo.h>

#if OSSIM_HAS_HDF5
#include <ossim/hdf5/ossimHdf5Info.h>
#endif


ossimInfoFactory* ossimInfoFactory::theInstance = 0;

ossimInfoFactory::~ossimInfoFactory()
{}

ossimInfoFactory* ossimInfoFactory::instance()
{
   if ( !theInstance )
   {
      theInstance = new ossimInfoFactory;
   }
   return theInstance;
}

ossimInfoBase* ossimInfoFactory::create(const ossimFilename& file) const
{
   ossimRefPtr<ossimInfoBase> result = 0;

   result = new ossimTiffInfo();
   if ( result->open(file) )
   {
      return result.release();
   }

   result = new ossimJp2Info();
   if ( result->open(file) )
   {
      return result.release();
   }

   result = new ossimNitfInfo();
   if ( result->open(file) )
   {
      return result.release();
   }

   result = new ossimDemInfo();
   if ( result->open(file) )
   {
      return result.release();
   }

   result = new ossimDtedInfo();
   if ( result->open(file) )
   {
      return result.release();
   }

   result = new ossimEnviInfo();
   if ( result->open(file) )
   {
      return result.release();
   }

   result = new ossimRpfInfo();
   if ( result->open(file) )
   {
      return result.release();
   }
   
   result = new ossimXmpInfo();
   if ( result->open(file) )
   {
      return result.release();
   }
   
   result = new ossimLasInfo();
   if ( result->open(file) )
   {
      return result.release();
   }

   result = new ossimDoqq();
   if ( result->open(file) )
   {
      return result.release();
   }

   result = new ossimJ2kInfo();
   if ( result->open(file) )
   {
      return result.release();
   }
   
   result = new ossimCcfInfo();
   if ( result->open(file) )
   {
      return result.release();
   }
   
#if OSSIM_HAS_HDF5
   result = new ossimHdf5Info();
   if ( result->open(file) )
   {
      return result.release();
   }
#endif

   return 0;
}

ossimInfoFactory::ossimInfoFactory()
{}

ossimInfoFactory::ossimInfoFactory(const ossimInfoFactory& /* obj */ )
{}

const ossimInfoFactory& ossimInfoFactory::operator=(
   const ossimInfoFactory& /* rhs */)
{
   return *this;
}
