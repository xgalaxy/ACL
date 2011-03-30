//-----------------------------------------------------------------------------
// Application Core Library
// Copyright (C) GarageGames.com, Inc.
//-----------------------------------------------------------------------------

#ifndef _TYPESGCC_H
#define _TYPESGCC_H


// For additional information on GCC predefined macros
// http://gcc.gnu.org/onlinedocs/gcc-3.0.2/cpp.html


//--------------------------------------
// Types
typedef signed long long    S64;
typedef unsigned long long  U64;


//--------------------------------------
// Compiler Version
#define TORQUE_COMPILER_GCC (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)


//--------------------------------------
// Identify the compiler string

#if defined(__MINGW32__)
#  define TORQUE_COMPILER_STRING "GCC (MinGW)"
#  define TORQUE_COMPILER_MINGW
#elif defined(__CYGWIN__)
#  define TORQUE_COMPILER_STRING "GCC (Cygwin)"
#  define TORQUE_COMPILER_MINGW
#else
#  define TORQUE_COMPILER_STRING "GCC "
#endif


//--------------------------------------
// Identify the Operating System
#if defined(__WIN32__) || defined(_WIN32)
#  define TORQUE_OS_STRING "Win32"
#  define TORQUE_OS_WIN32
#  define TORQUE_SUPPORTS_NASM
#  define TORQUE_SUPPORTS_GCC_INLINE_X86_ASM
#  include "./types.win32.h"

#elif defined(linux)
#  define TORQUE_OS_STRING "Linux"
#  define TORQUE_OS_LINUX
#  define TORQUE_SUPPORTS_NASM
#  define TORQUE_SUPPORTS_GCC_INLINE_X86_ASM
#  include "./types.posix.h"

#elif defined(__OpenBSD__)
#  define TORQUE_OS_STRING "OpenBSD"
#  define TORQUE_OS_OPENBSD
#  define TORQUE_SUPPORTS_NASM
#  define TORQUE_SUPPORTS_GCC_INLINE_X86_ASM
#  include "./types.posix.h"

#elif defined(__FreeBSD__)
#  define TORQUE_OS_STRING "FreeBSD"
#  define TORQUE_OS_FREEBSD
#  define TORQUE_SUPPORTS_NASM
#  define TORQUE_SUPPORTS_GCC_INLINE_X86_ASM
#  include "./types.posix.h"

#elif defined(__APPLE__)
#  define TORQUE_OS_STRING "MacOS X"
#  define TORQUE_OS_MAC
#  include "./types.mac.h"
#  if defined(i386)
#     define TORQUE_SUPPORTS_NASM
#  endif
#else 
#  error "GCC: Unsupported Operating System"
#endif


//--------------------------------------
// Identify the CPU
#if defined(i386)
#  define TORQUE_CPU_STRING "Intel x86"
#  define TORQUE_CPU_X86
#  define TORQUE_LITTLE_ENDIAN
#  define TORQUE_DEBUG_BREAK __asm{int 3}

#elif defined(__ppc__)
#  define TORQUE_CPU_STRING "PowerPC"
#  define TORQUE_CPU_PPC
#  define TORQUE_BIG_ENDIAN
#  define TORQUE_DEBUG_BREAK asm{trap}

#else
#  error "GCC: Unsupported Target CPU"
#endif

#ifndef Offset
/// Offset macro:
/// Calculates the location in memory of a given member x of class cls from the
/// start of the class.  Need several definitions to account for various
/// flavors of GCC.

// now, for each compiler type, define the Offset macros that should be used.
// The Engine code usually uses the Offset macro, but OffsetNonConst is needed
// when a variable is used in the indexing of the member field (see
// TSShapeConstructor::initPersistFields for an example)

// compiler is non-GCC, or gcc < 3
#if (__GNUC__ < 3)
#define Offset(x, cls) _Offset_Normal(x, cls)
#define OffsetNonConst(x, cls) _Offset_Normal(x, cls)

// compiler is GCC 3 with minor version less than 4
#elif defined(TORQUE_COMPILER_GCC) && (__GNUC__ == 3) && (__GNUC_MINOR__ < 4)
#define Offset(x, cls) _Offset_Variant_1(x, cls)
#define OffsetNonConst(x, cls) _Offset_Variant_1(x, cls)

// compiler is GCC 3 with minor version greater than 4
#elif defined(TORQUE_COMPILER_GCC) && (__GNUC__ == 3) && (__GNUC_MINOR__ >= 4)
#include <stddef.h>
#define Offset(x, cls) _Offset_Variant_2(x, cls)
#define OffsetNonConst(x, cls) _Offset_Variant_1(x, cls)

// compiler is GCC 4
#elif defined(TORQUE_COMPILER_GCC) && (__GNUC__ == 4)
#include <stddef.h>
#define Offset(x, cls) _Offset_Normal(x, cls)
#define OffsetNonConst(x, cls) _Offset_Variant_1(x, cls)

#endif
#endif

#define TORQUE_PRETTY_FUNCTION __PRETTY_FUNCTION__
#define TORQUE_NO_INLINE __attribute__((__noinline__))


#endif // INCLUDED_TYPES_GCC_H
