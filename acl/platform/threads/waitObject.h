//-----------------------------------------------------------------------------
// Application Core Library
// Copyright (c) 2009-2012 DuJardin Consulting, LLC.
// Portions Copyright (c) 2009 GarageGames, Inc.
//-----------------------------------------------------------------------------

#ifndef ACL_PLATFORM_THREADWAITOBJECT_H_
#define ACL_PLATFORM_THREADWAITOBJECT_H_

#include "core/types.h"
#include "core/util/scopedPtr.h"
#include "core/util/noncopyable.h"
#include "platform/threads/threadingStatus.h"

namespace Platform2
{
 
   /// @ingroup p2thread
   /// WaitObject can wait on a threaded condition to be signaled.
   class WaitObject : private Noncopyable
   {
   public:
      WaitObject();
      ~WaitObject();

      Threading::Status wait(S32 timeout=-1);
     
      /// Unblock one thread that is waiting on this object.
      void signalOne();
     
      /// Unblock all threads that are waiting on this object.
      void signalAll();
   private:
      /// @cond
      struct Internal;
      ACLib::ScopedPtr<Internal> mImpl;
      /// @endcond
   };
}

#endif
