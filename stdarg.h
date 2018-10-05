/*
	StdArg.h -- Variable arguments
	
	Copyright Apple Computer,Inc.	1987, 1990, 1994-1998
	All rights reserved.

*/


#ifndef __STDARG__
#define __STDARG__

/*
 * Get common declarations 
 */

#include <NullDef.h>
#include <SizeTDef.h>
#include <VaListTDef.h>

#if __spillargs
	/*	"__spillargs" needed for MrC[pp] PowerMac register-based calling conventions.*/
	/*	When using other preprocessors other than MrC, simply define "__spillargs".  */
	#undef __spillargs
	extern int __spillargs;
	#define va_start(ap, parmN) ap = (__spillargs, (va_list)((unsigned int)&(parmN) + (((sizeof(parmN)+3)/4)*4)))

#elif !defined (__SC__) || defined (__CFM68K__)
	/*	most normal compilers are long-word aligned�  */
	#define va_start(ap, parmN) ap = (va_list)((unsigned int)&(parmN) + (((sizeof(parmN)+3)/4)*4))

#else
	/*	�but Symantec C is word aligned.  */
	#define va_start(ap, parmN) ap = (va_list)((char*)&parmN + (((sizeof(parmN)+1)/2)*2))
#endif
	
	/* Vector compilations require a unique form of va_arg in order to access 16-byte  	*/
	/* aligned vector data structures. __va_align__ is a special compile-time variable 	*/
	/* that takes a type of expression as its argument and returns 16 if the type		*/
	/* is a vector type or a struct/class that contains a vector field.  It is 4 for 	*/
	/* everything else.																	*/
#if __VEC__
	#define va_arg(ap, type) ((type *)(ap = (char *)(((unsigned long)ap+__va_align__(type)-1)&~(__va_align__(type)-1)) + sizeof(type)))[-1]
#else
	#define va_arg(ap, type) ((type *)(ap += sizeof (type)))[-1]
#endif

#define va_end(ap)	/* do nothing */


#endif
