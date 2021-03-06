/*
    perf-libs-tools
    Copyright 2017 Arm Limited. 
    All rights reserved.
*/

#ifndef PRELOADLIB_DOT_H
#define PRELOADLIB_DOT_H

#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#define __GNU_SOURCE
#define  __USE_GNU
#include <dlfcn.h>

#ifdef LOGGING
#include "logging.h"
#else
#include "summary.h"
#endif

/* ------------------------------------------------------------------ */

/* All lines containing _ARMPL_INT_T or INTEGER64 get          _ARMPL_INT_T
   filtered out of the distributed copy of armpl.h             _ARMPL_INT_T */
/* _ARMPL_INT_T The ARMPL integer type, either 32-bit or 64-bit */
#ifndef _ARMPL_INT_T
#define _ARMPL_INT_T
#ifdef INTEGER64
/* _ARMPL_INT_T  N.B. even in 64-bit integer variants of ARMPL, hidden
   _ARMPL_INT_T  Fortran string length arguments (type armpl_strlen_t)
   _ARMPL_INT_T  are of type int rather than long */
  typedef long armpl_int_t;                /* _ARMPL_INT_T */
  typedef unsigned long armpl_uint_t;      /* _ARMPL_INT_T */
  typedef int armpl_strlen_t;              /* _ARMPL_INT_T */
#else /* ! INTEGER64 */
  typedef int armpl_int_t;                 /* _ARMPL_INT_T */
  typedef unsigned int armpl_uint_t;       /* _ARMPL_INT_T */
  typedef int armpl_strlen_t;              /* _ARMPL_INT_T */
#endif /* ! INTEGER64 */
#endif /* _ARMPL_INT_T */

/* A complex datatype for use by the C interfaces to ARMPL routines */
#ifndef _ARMPL_ARMPL_SINGLECOMPLEX_T
#define _ARMPL_ARMPL_SINGLECOMPLEX_T
typedef struct
{
  float real, imag;
} armpl_singlecomplex_t;
typedef struct
{
  double real, imag;
} armpl_doublecomplex_t;
#endif /* !defined(_ARMPL_ARMPL_SINGLECOMPLEX_T) */

/* ------------------------------------------------------------------ */

#include "armpl.h"

#endif
