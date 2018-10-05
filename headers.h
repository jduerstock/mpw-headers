/*
 *------------------------------------------------------------------------
 * Copyright:
 *      � 1995 by Apple Computer Inc. � all rights reserved.
 *
 * Project:
 *      PowerPC C++ Streams Library
 *
 * Filename:
 *      headers.h
 *
 * Created:
 *      (unknown)
 *
 * Modified:
 *      Date     Engineer       Comment
 *      -------- -------------- ------------------------------------------
 *      01/12/95 Scott Fraser   Updated for new runtime environments.
 *      12/01/93 Rudy Wang      Added this header comment block.
 *------------------------------------------------------------------------
 */
#ifndef __HEADERS__
#define __HEADERS__	1

#ifndef __cplusplus
#error "This program is written in C++. Don't try to compile it as C!"
#endif

#include <stdlib.h>
#include <ctype.h>

#include <iostream.h>
#include <fstream.h>
#include <strstream.h>
#include <stdiostream.h>

#include <stddef.h>		// For NULL

#ifndef TRUE
#define TRUE		1
#endif
#ifndef FALSE
#define FALSE		0
#endif

#ifndef AUTO_SIZE
#define AUTO_SIZE	512
#endif

#ifndef DEFCONST
#define DEFCONST	1
#define NUL		0
#define FLAGS		17
#define PRECIS		6
#define FILL		' '
#define BASEF		0x70
#define ADJASTF		0x0E
#define FLOATF		0x1800
#define ISPESH		512
#define NEXTBIT		0x10000
#endif

#endif /* __HEADERS__ */
