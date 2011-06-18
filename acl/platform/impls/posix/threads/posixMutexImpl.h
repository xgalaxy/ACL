//-----------------------------------------------------------------------------
// Application Core Library
// Copyright (c) 2009-2011 DuJardin Consulting, LLC.
//-----------------------------------------------------------------------------

#ifndef ACL_PLATFORM_POSIX_MUTEXIMPL_H_
#define ACL_PLATFORM_POSIX_MUTEXIMPL_H_

#include "platform/impls/base/threads/mutexImpl.h"
#include "core/types/types.h"
#include <pthread.h>

namespace Platform2
{
   namespace Internal_
   {
      class PosixMutexImpl : public MutexImpl
      {
      public:      
         PosixMutexImpl();
         virtual ~PosixMutexImpl();
         virtual bool init();
         virtual Threading::Status lock(bool block);
         virtual Threading::Status unlock();

      private:
         pthread_mutex_t mMutex;
      };
   }
}

#endif