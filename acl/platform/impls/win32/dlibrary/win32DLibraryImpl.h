//-----------------------------------------------------------------------------
// Application Core Library
// Copyright (c) 2009-2012 DuJardin Consulting, LLC.
// Portions Copyright (c) 2009 GarageGames, Inc.
//-----------------------------------------------------------------------------

#ifndef ACL_PLATFORM_WIN32_DLIBRARYIMPL_H_
#define ACL_PLATFORM_WIN32_DLIBRARYIMPL_H_

#include <Windows.h>
#include "platform/impls/base/dlibrary/dlibraryImpl.h"

namespace Platform2
{
   namespace Internal_
   {
      class Win32DLibraryImpl : public DLibraryImpl
      {
      public:
         Win32DLibraryImpl();
         virtual ~Win32DLibraryImpl();

         virtual bool init(const String& file);
         virtual void* bind(const String& name);
         virtual void close();

      private:
         HMODULE mHandle;
      };
   }
}

#endif
